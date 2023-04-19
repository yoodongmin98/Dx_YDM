#include "PrecompileHeader.h"
#include "GameEngineCore.h"
#include <GameEngineBase\GameEngineDebug.h>
#include <GameEnginePlatform\GameEngineWindow.h>
#include <GameEnginePlatform\GameEngineSound.h>
#include "GameEngineResource.h"

#include "GameEngineVertex.h"

#include "GameEngineMesh.h"
#include "GameEngineTexture.h"
#include "GameEngineRenderTarget.h"
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"
#include "GameEngineRenderingPipeLine.h"
#include "GameEngineRasterizer.h"
#include "GameEnginePixelShader.h"
#include "GameEngineConstantBuffer.h"

#include "GameEngineVertexShader.h"


void GameEngineCore::CoreResourcesInit()
{
	// ���ؽ� ������ ����� ��ǲ ���̾ƿ��� ������ �� �߿��ϴ�.
	GameEngineVertex::LayOut.AddInputLayOut("POSITION", DXGI_FORMAT_R32G32B32A32_FLOAT);
	GameEngineVertex::LayOut.AddInputLayOut("COLOR", DXGI_FORMAT_R32G32B32A32_FLOAT);

	//typedef struct D3D11_INPUT_ELEMENT_DESC
	//{
	//	LPCSTR SemanticName; = "POSITION"
	//	UINT SemanticIndex; = 0
	//	DXGI_FORMAT Format; 
	//	UINT InputSlot;
	//	UINT AlignedByteOffset;
	//	D3D11_INPUT_CLASSIFICATION InputSlotClass;
	//	UINT InstanceDataStepRate; 
	//} 	


	//const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
	//UINT NumElements, // 
	//const void* pShaderBytecodeWithInputSignature,  // ���̴��� ���̳ʸ� �ڵ带 ����
	//SIZE_T BytecodeLength,
	//ID3D11InputLayout** ppInputLayout // ������� ������ ������

	{
		std::vector<GameEngineVertex> ArrVertex;
		ArrVertex.resize(4);
		// �ո�
		ArrVertex[0] = { { -0.5f, 0.5f, 0.0f }, float4::Red };
		ArrVertex[1] = { { 0.5f, 0.5f, 0.0f }, float4::Green };
		ArrVertex[2] = { { 0.5f, -0.5f, 0.0f }, float4::Black };
		ArrVertex[3] = { { -0.5f, -0.5f, 0.0f }, float4::White };

		std::vector<UINT> ArrIndex = {0, 1, 2, 0, 2, 3};

		GameEngineVertexBuffer::Create("Rect", ArrVertex);
		GameEngineIndexBuffer::Create("Rect", ArrIndex);

	}

	{
		// ������ ���ؽ��� ��ġ�� ���ð����̶�� �θ��ϴ�.
		std::vector<float4> ArrVertex;
		ArrVertex.resize(24);
		// �ո�
		ArrVertex[0] = { -0.5f, -0.5f, 0.5f };
		ArrVertex[1] = { 0.5f, -0.5f,0.5f };
		ArrVertex[2] = { 0.5f, 0.5f,0.5f };
		ArrVertex[3] = { -0.5f, 0.5f,0.5f };

		// �޸�
		ArrVertex[4] = ArrVertex[0].RotaitonXDegReturn(180.0f);
		ArrVertex[5] = ArrVertex[1].RotaitonXDegReturn(180.0f);
		ArrVertex[6] = ArrVertex[2].RotaitonXDegReturn(180.0f);
		ArrVertex[7] = ArrVertex[3].RotaitonXDegReturn(180.0f);

		// ���ʸ�
		ArrVertex[8] = ArrVertex[0].RotaitonYDegReturn(90.0f);
		ArrVertex[9] = ArrVertex[1].RotaitonYDegReturn(90.0f);
		ArrVertex[10] = ArrVertex[2].RotaitonYDegReturn(90.0f);
		ArrVertex[11] = ArrVertex[3].RotaitonYDegReturn(90.0f);

		// ������
		ArrVertex[12] = ArrVertex[0].RotaitonYDegReturn(-90.0f);
		ArrVertex[13] = ArrVertex[1].RotaitonYDegReturn(-90.0f);
		ArrVertex[14] = ArrVertex[2].RotaitonYDegReturn(-90.0f);
		ArrVertex[15] = ArrVertex[3].RotaitonYDegReturn(-90.0f);

		ArrVertex[16] = ArrVertex[0].RotaitonXDegReturn(90.0f);
		ArrVertex[17] = ArrVertex[1].RotaitonXDegReturn(90.0f);
		ArrVertex[18] = ArrVertex[2].RotaitonXDegReturn(90.0f);
		ArrVertex[19] = ArrVertex[3].RotaitonXDegReturn(90.0f);

		ArrVertex[20] = ArrVertex[0].RotaitonXDegReturn(-90.0f);
		ArrVertex[21] = ArrVertex[1].RotaitonXDegReturn(-90.0f);
		ArrVertex[22] = ArrVertex[2].RotaitonXDegReturn(-90.0f);
		ArrVertex[23] = ArrVertex[3].RotaitonXDegReturn(-90.0f);

	}

	// ���ؽ� ���̴� ������
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("EngineResources");
		NewDir.Move("EngineResources");
		NewDir.Move("Shader");

		std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".hlsl", ".fx"});

		GameEngineVertexShader::Load(Files[0].GetFullPath(), "Texture_VS");
		GameEnginePixelShader::Load(Files[0].GetFullPath(), "Texture_PS");

		//for (size_t i = 0; i < Files.size(); i++)
		//{
		//}

	}


	{
		D3D11_RASTERIZER_DESC Desc = {};

		//D3D11_FILL_MODE FillMode;
		// �������� �� ����� ä��� ��带 �����մϴ�( D3D11_FILL_MODE ���� ).
		//D3D11_CULL_MODE CullMode;
		// ������ ������ ���ϴ� �ﰢ���� �׷����� ������ ��Ÿ���ϴ�( D3D11_CULL_MODE ���� ).
		//BOOL FrontCounterClockwise;
		// �ﰢ���� �ո����� �޸����� �����մϴ�. 
		// �� �Ű������� TRUE �̸� ���� �� ���� ��󿡼� 
		// �ð� �ݴ� �����̸� �ﰢ���� ������ ���ϴ� ������ 
		// ���ֵǰ� �ð� �����̸� �ĸ��� ���ϴ� ������ ���ֵ˴ϴ�. 
		// �� �Ű������� FALSE �̸� �� �ݴ��Դϴ�.
		//INT DepthBias;
		// ������ �ȼ��� �߰��� ���� ���Դϴ�. ���� ���⿡ ���� ������ ���� ���� �� �����Ͻʽÿ� .
		//FLOAT DepthBiasClamp;
		// �ȼ��� �ִ� ���� ����. ���� ���⿡ ���� ������ ���� ���� �� �����Ͻʽÿ� .
		//FLOAT SlopeScaledDepthBias;
		// �־��� �ȼ��� ���⿡ ���� ��Į��. ���� ���⿡ ���� ������ ���� ���� �� �����Ͻʽÿ� .
		//BOOL DepthClipEnable;
		// �Ÿ��� ���� Ŭ������ Ȱ��ȭ�մϴ�.
		// �ϵ����� �׻� ������ȭ�� ��ǥ�� x �� y Ŭ������ �����մϴ�.
		// DepthClipEnable�� �⺻���� TRUE �� ���� �Ǹ� �ϵ��� z 
		// ���� �ڸ��ϴ�(��, �ϵ����� ���� �˰����� ������ �ܰ踦 �����մϴ�).
		//BOOL ScissorEnable;
		// ���� �簢�� �ø��� Ȱ��ȭ�մϴ�. Ȱ�� ���� �簢�� �ܺ��� ��� �ȼ��� �߷����ϴ�.
		//BOOL MultisampleEnable;
		// ���� ���� ��Ƽ�ٸ����(MSAA) ���� ��󿡼� �纯�� �Ǵ� ���� ���� ��Ƽ�ٸ���� 
		// �˰����� ������� ���θ� �����մϴ�. �纯�� ���� ��Ƽ �ٸ���� �˰����� 
		// ����Ϸ��� TRUE �� ���� �ϰ� ���� ���� ��Ƽ �ٸ���� �˰����� ����Ϸ��� 
		// FALSE �� �����մϴ�. �� ����� ���� �ڼ��� ������ ��� �����ϼ���.
		//BOOL AntialiasedLineEnable;
		// �� ��Ƽ�ٸ������ Ȱ��ȭ���� ���θ� �����մϴ�. �� �׸��⸦ �����ϰ� MultisampleEnable�� 
		// FALSE �� ��쿡�� ����˴ϴ� . �� ����� ���� �ڼ��� ������ ��� �����ϼ���.

		// ���̾� �������� ������ ǥ���ϴ� �̴ϴ�. 
		Desc.FillMode = D3D11_FILL_MODE::D3D11_FILL_WIREFRAME;
		Desc.CullMode = D3D11_CULL_MODE::D3D11_CULL_BACK;
		Desc.FrontCounterClockwise = FALSE;

		std::shared_ptr<GameEngineRasterizer> Res = GameEngineRasterizer::Create("EngineBase", Desc);
	}


	{
		{
			std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("2DTexture");

			Pipe->SetVertexBuffer("Rect");
			Pipe->SetIndexBuffer("Rect");
			Pipe->SetVertexShader("TextureShader.hlsl");
			Pipe->SetRasterizer("EngineBase");
			Pipe->SetPixelShader("TextureShader.hlsl");
			// Pipe->SetFILL_MODE(D3D11_FILL_WIREFRAME);
		}
	}
}

void GameEngineCore::CoreResourcesEnd()
{
	GameEngineConstantBuffer::ResourcesClear();
	GameEnginePixelShader::ResourcesClear();
	GameEngineRasterizer::ResourcesClear();
	GameEngineVertexShader::ResourcesClear();
	GameEngineIndexBuffer::ResourcesClear();
	GameEngineVertexBuffer::ResourcesClear();
	GameEngineMesh::ResourcesClear();
	GameEngineTexture::ResourcesClear();
	GameEngineRenderTarget::ResourcesClear();
}
