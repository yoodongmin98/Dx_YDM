#include "PrecompileHeader.h"
#include "GameEngineRenderTarget.h"

GameEngineRenderTarget::GameEngineRenderTarget() 
{
}

GameEngineRenderTarget::~GameEngineRenderTarget() 
{
	DepthTexture = nullptr;
}


void GameEngineRenderTarget::ResCreate(std::shared_ptr<GameEngineTexture> _Texture, float4 _Color)
{
	Color = _Color;
	Texture = _Texture;
}

void GameEngineRenderTarget::Clear()
{
	ID3D11RenderTargetView* RTV = Texture->GetRTV();

	if (nullptr == RTV)
	{
		MsgAssert("����Ÿ�� �䰡 �������� �ʾƼ� Ŭ��� �Ұ����մϴ�.");
		return;
	}

	GameEngineDevice::GetContext()->ClearRenderTargetView(RTV, Color.Arr1D);

	ID3D11DepthStencilView* DSV
		= DepthTexture != nullptr ? DepthTexture->GetDSV() : nullptr;

	if (nullptr != DSV)
	{
		GameEngineDevice::GetContext()->ClearDepthStencilView(DSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	}
}

void GameEngineRenderTarget::Setting() 
{
	ID3D11RenderTargetView* RTV = Texture->GetRTV();

	if (nullptr == RTV)
	{
		MsgAssert("����Ÿ�� �䰡 �������� �ʾƼ� Ŭ��� �Ұ����մϴ�.");
	}

	ID3D11DepthStencilView* DSV 
		= DepthTexture != nullptr ? DepthTexture->GetDSV() : nullptr;

	// ���� ������ z���� ���� �ʰڽ��ϴ�.
	GameEngineDevice::GetContext()->OMSetRenderTargets(1, &RTV, DSV);
}

void GameEngineRenderTarget::Reset()
{
	ID3D11RenderTargetView* RTV[8] = {nullptr};

	GameEngineDevice::GetContext()->OMSetRenderTargets(8, RTV, nullptr);
}

void GameEngineRenderTarget::CreateDepthTexture()
{
	D3D11_TEXTURE2D_DESC Desc = {0,};

	Desc.ArraySize = 1;
	Desc.Width = Texture->GetWidth();
	Desc.Height = Texture->GetHeight();

	//            4����Ʈ�� 3����Ʈ�� 0~1.0f ǥ���ϴµ� ����ϰ�
	//            ������ �ڿ��ִ� 1����Ʈ�� ���ٽ� ���̶�� �ϴ� �ɷ� ����Ҽ� �ְ� �ϴ� ����.
	Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;

	Desc.MipLevels = 1;
	Desc.Usage = D3D11_USAGE_DEFAULT;

	Desc.CPUAccessFlags = 0;
	Desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
	DepthTexture = GameEngineTexture::Create(Desc);
}