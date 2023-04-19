#include "PrecompileHeader.h"
#include "GameEngineTexture.h"

// #pragma comment();

GameEngineTexture::GameEngineTexture() 
{
}

GameEngineTexture::~GameEngineTexture() 
{
	if (nullptr != RenderTarget)
	{
		RenderTarget->Release();
		RenderTarget = nullptr;
	}

	if (nullptr != Texture2D)
	{
		Texture2D->Release();
		Texture2D = nullptr;
	}
}


void GameEngineTexture::ResCreate(ID3D11Texture2D* _Create)
{
	Texture2D = _Create;
	CreateRenderTargetView();
}

void GameEngineTexture::CreateRenderTargetView()
{
	if (nullptr == Texture2D)
	{
		MsgAssert("�ؽ�ó�� �������� �ʴ� ����Ÿ���� ���� ���� �����ϴ�.");
		return;
	}

	// ����Ÿ���� �������� ����� �ִ�.
	HRESULT Result = GameEngineDevice::GetDevice()->CreateRenderTargetView(Texture2D, nullptr, &RenderTarget);

	if (S_OK != Result)
	{
		MsgAssert("����Ÿ�� ������ �����߽��ϴ�.");
		return;
	}

}


void GameEngineTexture::ResLoad(const std::string_view& _Path) 
{
	// GameEnginePath NewPath = 
	
}