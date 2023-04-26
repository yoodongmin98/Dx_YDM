#include "PrecompileHeader.h"
#include "GameEngineRenderingPipeLine.h"
#include <GameEngineCore/GameEngineDevice.h>
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"
#include "GameEngineVertexShader.h"
#include "GameEngineRasterizer.h"
#include "GameEnginePixelShader.h"
#include "GameEngineBlend.h"
#include "GameEngineInputLayOut.h"

GameEngineRenderingPipeLine::GameEngineRenderingPipeLine() 
{
	InputLayOutPtr = std::make_shared<GameEngineInputLayOut>();
}

GameEngineRenderingPipeLine::~GameEngineRenderingPipeLine() 
{
}

// �Ž� + ��Ƽ����

// ���� ���� ������ �غ��ϰ�
void GameEngineRenderingPipeLine::InputAssembler1() 
{
	if (nullptr == InputLayOutPtr)
	{
		MsgAssert("��ǲ ���̾ƿ��� �������� �ʾƼ� ��ǲ�����1 ������ ������ �� �����ϴ�.");
		return;
	}

	// �������� ���ؼ��� ������ ���� ����°� �⺻�̴�.
	// �׷���ī��� ���� ��� ������ ������ �ִ��� ���� ���Ѵ�.
	InputLayOutPtr->Setting();

	if (nullptr == VertexBufferPtr)
	{
		MsgAssert("���ؽ� ���۰� �������� �ʾƼ� ��ǲ�����1 ������ ������ �� �����ϴ�.");
		return;
	}

	// D3D11 ERROR: ID3D11DeviceContext::DrawIndexed: The Vertex Shader expects 
	// application provided input data (which is to say data other than hardware 
	// auto-generated values such as VertexID or InstanceID). Therefore an Input 
	// Assembler object is expected, but none is bound. 
	// [ EXECUTION ERROR #349: DEVICE_DRAW_INPUTLAYOUT_NOT_SET]

	VertexBufferPtr->Setting();
	// GameEngineDevice::GetContext()->IASetVertexBuffers()
}
// ���ÿ� �����ϴ� ���� �츮�� ���� ����� ���ؼ� ��ȯ�ϰ�.
void GameEngineRenderingPipeLine::VertexShader()
{
	if (nullptr == VertexShaderPtr)
	{
		MsgAssert("���ؽ� ���̴��� �������� �ʾƼ� ���ؽ� ���̴� ������ ������ �� �����ϴ�.");
		return;
	}

	VertexShaderPtr->Setting();
}

// ���� ������ ���� � ������ �׸��� ���ϰ�
void GameEngineRenderingPipeLine::InputAssembler2() 
{
	// �׸��� ������ ���� �����͸� �־��ش�.
	if (nullptr == IndexBufferPtr)
	{
		MsgAssert("�ε��� ���۰� �������� �ʾƼ� ��ǲ �����2 ������ ������ �� �����ϴ�.");
		return;
	}

	// 012023
	IndexBufferPtr->Setting();

	// 012 023 <=3���� ��� ������ ������� ���⼭ ó���� �Ǿ���.
	GameEngineDevice::GetContext()->IASetPrimitiveTopology(TOPOLOGY);
}

// ���⼭����
void GameEngineRenderingPipeLine::HullShader() 
{

}
void GameEngineRenderingPipeLine::Tessellator() 
{

}
void GameEngineRenderingPipeLine::DomainShader() 
{

}
void GameEngineRenderingPipeLine::GeometryShaeder() 
{

}
// ��������� ȭ����� ��� ���� ����

// w�����⸦ ���ݴϴ�. 
// ����Ʈ�� �����ݴϴ�.
// ȭ�� �ø� 
// �ȼ� ������
void GameEngineRenderingPipeLine::Rasterizer() 
{
	if (nullptr == RasterizerPtr)
	{
		MsgAssert("�����Ͷ������� �������� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	RasterizerPtr->SetFILL_MODE(FILL_MODE);
	RasterizerPtr->Setting();

	// GameEngineDevice::GetContext()->RSSetState
}


void GameEngineRenderingPipeLine::PixelShader() 
{
	if (nullptr == PixelShaderPtr)
	{
		MsgAssert("�ȼ� ���̴��� �������� �ʾƼ� �ȼ� ���̴� ������ ������ �� �����ϴ�.");
		return;
	}

	PixelShaderPtr->Setting();


	// GameEngineDevice::GetContext()->PSSetShader
}
void GameEngineRenderingPipeLine::OutputMerger() 
{
	if (nullptr == BlendPtr)
	{
		MsgAssert("���尡 �������� �ʾ� �ƿ�ǲ ���� ������ �Ϸ��Ҽ��� �����ϴ�.");
		return;
	}


	BlendPtr->Setting();
	

	// GameEngineDevice::GetContext()->OMSetRenderTargets
}


void GameEngineRenderingPipeLine::SetVertexBuffer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	VertexBufferPtr = GameEngineVertexBuffer::Find(UpperName);

	if (nullptr == VertexBufferPtr)
	{
		MsgAssert("�������� �ʴ� ���ؽ� ���۸� ����Ϸ��� �߽��ϴ�.");
	}

	if (nullptr == VertexShaderPtr)
	{
		return;
	}

	InputLayOutPtr->ResCreate(VertexBufferPtr, VertexShaderPtr);
}


void GameEngineRenderingPipeLine::SetIndexBuffer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	IndexBufferPtr = GameEngineIndexBuffer::Find(UpperName);

	if (nullptr == IndexBufferPtr)
	{
		MsgAssert("�������� �ʴ� ���ؽ� ���۸� ����Ϸ��� �߽��ϴ�.");
	}
}


void GameEngineRenderingPipeLine::SetVertexShader(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	VertexShaderPtr = GameEngineVertexShader::Find(UpperName);

	if (nullptr == VertexShaderPtr)
	{
		MsgAssert("�������� �ʴ� ���ؽ� ���̴��� ����Ϸ��� �߽��ϴ�.");
	}

	if (nullptr == VertexBufferPtr)
	{
		return;
	}

	InputLayOutPtr->ResCreate(VertexBufferPtr, VertexShaderPtr);
}


void GameEngineRenderingPipeLine::SetPixelShader(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	PixelShaderPtr = GameEnginePixelShader::Find(UpperName);

	if (nullptr == PixelShaderPtr)
	{
		MsgAssert("�������� �ʴ� �ȼ� ���̴��� ����Ϸ��� �߽��ϴ�.");
	}
}

void GameEngineRenderingPipeLine::SetBlend(const std::string_view& _Value) 
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	BlendPtr = GameEngineBlend::Find(UpperName);

	if (nullptr == BlendPtr)
	{
		MsgAssert("�������� �ʴ� ���带 �����Ϸ��� �߽��ϴ�.");
		return;
	}
}

void GameEngineRenderingPipeLine::SetRasterizer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	RasterizerPtr = GameEngineRasterizer::Find(UpperName);

	if (nullptr == RasterizerPtr)
	{
		MsgAssert("�������� �ʴ� �����Ͷ������� ����Ϸ��� �߽��ϴ�.");
	}
}

void GameEngineRenderingPipeLine::RenderingPipeLineSetting()
{
	// ������� �ϴ� �κ��� ������ ������������ �ѹٲ� ������ ��.
	InputAssembler1();
	VertexShader();
	InputAssembler2();
	HullShader();
	Tessellator();
	DomainShader();
	GeometryShaeder();
	Rasterizer();
	PixelShader();
	OutputMerger();
}

void GameEngineRenderingPipeLine::Render()
{
	UINT IndexCount = IndexBufferPtr->GetIndexCount();
	GameEngineDevice::GetContext()->DrawIndexed(IndexCount, 0, 0);
}