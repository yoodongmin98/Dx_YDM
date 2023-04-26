#include "PrecompileHeader.h"
#include "GameEngineTexture.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\GameEngineCore\\ThirdParty\\DirectXTex\\lib\\x64\\Debug\\DirectXTex.lib")
#else
#pragma comment(lib, "..\\GameEngineCore\\ThirdParty\\DirectXTex\\lib\\x64\\Release\\DirectXTex.lib")
#endif

// #pragma comment(lib, "DirectXTex.lib")

GameEngineTexture::GameEngineTexture() 
{
}

GameEngineTexture::~GameEngineTexture() 
{
	if (nullptr != DSV)
	{
		DSV->Release();
		DSV = nullptr;
	}

	if (nullptr != SRV)
	{
		SRV->Release();
		SRV = nullptr;
	}

	if (nullptr != RTV)
	{
		RTV->Release();
		RTV = nullptr;
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

	Texture2D->GetDesc(&Desc);

	CreateRenderTargetView();
}

void GameEngineTexture::CreateRenderTargetView()
{
	if (nullptr == Texture2D)
	{
		MsgAssert("�ؽ�ó�� �������� �ʴ� ����Ÿ�ٺ��� ���� ���� �����ϴ�.");
		return;
	}

	// ����Ÿ���� �������� ����� �ִ�.
	HRESULT Result = GameEngineDevice::GetDevice()->CreateRenderTargetView(Texture2D, nullptr, &RTV);

	if (S_OK != Result)
	{
		MsgAssert("����Ÿ�� �� ������ �����߽��ϴ�.");
		return;
	}
}

void GameEngineTexture::CreateDepthStencilView()
{
	if (nullptr == Texture2D)
	{
		MsgAssert("�ؽ�ó�� �������� �ʴµ� ���� ���ٽ� �� ���� ���� �����ϴ�.");
		return;
	}

	// ����Ÿ���� �������� ����� �ִ�.
	HRESULT Result = GameEngineDevice::GetDevice()->CreateDepthStencilView(Texture2D, nullptr, &DSV);

	if (S_OK != Result)
	{
		MsgAssert("���� ���ٽ� �� ������ �����߽��ϴ�.");
		return;
	}
}


void GameEngineTexture::ResLoad(const std::string_view& _Path) 
{
	// GameEnginePath NewPath = 

	GameEnginePath NewPath(_Path);

	std::string Ext = GameEngineString::ToUpper(NewPath.GetExtension());

	std::wstring Path = GameEngineString::AnsiToUniCode(NewPath.GetFullPath());

	if (Ext == ".TGA")
	{
		MsgAssert("���� �ε��� �� ���� �����Դϴ�." + std::string(_Path.data()));
	}
	else if (Ext == ".DDS")
	{
		MsgAssert("���� �ε��� �� ���� �����Դϴ�." + std::string(_Path.data()));
	}
	else if (S_OK != DirectX::LoadFromWICFile(Path.c_str(), DirectX::WIC_FLAGS_NONE, &Data, Image))
	{
		MsgAssert("�ؽ�ó �ε忡 �����߽��ϴ�." + std::string(_Path.data()));
	}

	if (S_OK != DirectX::CreateShaderResourceView
	(
		GameEngineDevice::GetDevice(),
		Image.GetImages(),
		Image.GetImageCount(),
		Image.GetMetadata(),
		&SRV
	))
	{
		MsgAssert("���̴� ���ҽ� �� ������ �����߽��ϴ�." + std::string(_Path.data()));
	}

	Desc.Width = static_cast<UINT>(Data.width);
	Desc.Height = static_cast<UINT>(Data.height);

	// Texture2D->GetDesc(&Desc);
}

void GameEngineTexture::VSSetting(UINT _Slot) 
{
	GameEngineDevice::GetContext()->VSSetShaderResources(_Slot, 1,&SRV);
}

void GameEngineTexture::PSSetting(UINT _Slot) 
{
	GameEngineDevice::GetContext()->PSSetShaderResources(_Slot, 1, &SRV);
}

void GameEngineTexture::ResCreate(const D3D11_TEXTURE2D_DESC& _Value) 
{
	Desc = _Value;

	GameEngineDevice::GetDevice()->CreateTexture2D(&Desc, nullptr, &Texture2D);

	if (D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL == Desc.BindFlags)
	{
		CreateDepthStencilView();
	}

	if (nullptr == Texture2D)
	{
		MsgAssert("�ؽ�ó ������ �����߽��ϴ�.");
	}
}