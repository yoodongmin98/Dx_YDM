#include "PrecompileHeader.h"
#include "GameEngineTileMapRenderer.h"
#include "GameEngineSprite.h"
#include "GameEngineLevel.h"
#include "GameEngineCamera.h"

GameEngineTileMapRenderer::GameEngineTileMapRenderer()
{
}

GameEngineTileMapRenderer::~GameEngineTileMapRenderer()
{
}

void GameEngineTileMapRenderer::Start()
{
	GameEngineRenderer::Start();

	SetMesh("Rect");
	SetPipeLine("2DTexture");

	AtlasData.x = 0.0f;
	AtlasData.y = 0.0f;
	AtlasData.z = 1.0f;
	AtlasData.w = 1.0f;

	ColorOptionValue.MulColor = float4::One;
	ColorOptionValue.PlusColor = float4::Null;

	GetShaderResHelper().SetConstantBufferLink("AtlasData", AtlasData);
	GetShaderResHelper().SetConstantBufferLink("ColorOption", ColorOptionValue);
}

void GameEngineTileMapRenderer::CreateTileMap(int _X, int _Y, const float4& _TileSize)
{
	TileSize = _TileSize;
	TileSize.z = 1.0f;

	MapCount.x = static_cast<float>(_X);
	MapCount.y = static_cast<float>(_Y);

	Tiles.resize(_Y);

	for (size_t y = 0; y < Tiles.size(); y++)
	{
		Tiles[y].resize(_X);
	}
}

void GameEngineTileMapRenderer::Clear()
{
	Tiles.clear();
}

void GameEngineTileMapRenderer::SetTile(int _X, int _Y, const std::string_view& _SpriteName, int _Index)
{
	if (true == Tiles.empty())
	{
		MsgAssert("CreateTileMap�� ���� ȣ�����ּž� �մϴ�.");
	}


	// �ε��� ����
	if (true == IsOver(_X, _Y))
	{
		MsgAssert("Ÿ�ϸ� ũ�⸦ �ʰ��� �����Ϸ� �߽��ϴ�");
		return;
	}


	std::shared_ptr<GameEngineSprite> Sprite = GameEngineSprite::Find(_SpriteName);

	Tiles[_Y][_X].Sprite = Sprite.get();
	Tiles[_Y][_X].Index = _Index;
}

bool GameEngineTileMapRenderer::IsOver(int _X, int _Y) const
{
	if (0 > _X || MapCount.ix() <= _X)
	{
		return true;
	}

	if (0 > _Y || MapCount.iy() <= _Y)
	{
		return true;
	}

	return false;
}

void GameEngineTileMapRenderer::Render(float _Delta)
{
	const TransformData& TransData = GetTransform()->GetTransDataRef();
	// 

	TransformData TileTransData = TransData;

	float4x4 Scale;
	float4x4 Pos;
	float4x4 Rot;
	float4 vPos;

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetMainCamera();

	for (size_t y = 0; y < Tiles.size(); y++)
	{
		for (size_t x = 0; x < Tiles[y].size(); x++)
		{
			GameEngineSprite* Sprite = Tiles[y][x].Sprite;
			const SpriteInfo& SpriteInfo = Sprite->GetSpriteInfo(Tiles[y][x].Index);

			// Ʈ������ ����
			{
				vPos = { TileSize.x * x, TileSize.y * y, 1.0f };

				Scale.Scale(TileSize);
				Pos.Pos(vPos);
				TileTransData.WorldViewProjectionMatrix = Scale * Pos * TransData.WorldMatrix;

				if (true == IsTilemapCulling)
				{
					TileTransData.WorldPosition = TileTransData.WorldViewProjectionMatrix.ArrVector[3];
					TileTransData.WorldScale = TileSize;

					if (false == Camera->IsView(TileTransData))
					{
						continue;
					}
				}

				//if (true == GetLevel()->IsCameraOver(WorldPos))
				//{
				//	continue;
				//}

				TileTransData.WorldViewProjectionMatrix = TileTransData.WorldViewProjectionMatrix * TransData.View * TransData.Projection;

				GetShaderResHelper().SetConstantBufferLink("TransformData", TileTransData);
			}

			// �ؽ�ó ����
			{
				GetShaderResHelper().SetTexture("DiffuseTex", SpriteInfo.Texture);
				AtlasData = SpriteInfo.CutData;
			}

			GameEngineRenderer::Render(_Delta);
		}
	}

	GetShaderResHelper().SetConstantBufferLink("TransformData", GetTransform()->GetTransDataRef());

}
