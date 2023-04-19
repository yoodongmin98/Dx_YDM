#include "PrecompileHeader.h"
#include "GameEngineShader.h"
#include "GameEngineConstantBuffer.h"

GameEngineShader::GameEngineShader() 
{
}

GameEngineShader::~GameEngineShader() 
{
	if (nullptr != BinaryCode)
	{
		BinaryCode->Release();
		BinaryCode = nullptr;
	}
}

void GameEngineShader::CreateVersion(const std::string_view& _ShaderType, UINT _VersionHigt /*= 5*/, UINT _VersionLow /*= 0*/)
{
	// vs_5_0
	Version += _ShaderType;
	Version += "_";
	Version += std::to_string(_VersionHigt);
	Version += "_";
	Version += std::to_string(_VersionLow);
}


void GameEngineShader::ShaderResCheck()
{
	if (nullptr == BinaryCode)
	{
		MsgAssert("���̴��� ������ ���� �ʾƼ� ���̴��� ���ҽ��� ������ �� �����ϴ�.");
		return;
	}

	// Reflection 
	// RTTI�� ����� �������� 
	ID3D11ShaderReflection* CompileInfo = nullptr;

	if (S_OK != D3DReflect(BinaryCode->GetBufferPointer(), BinaryCode->GetBufferSize(), IID_ID3D11ShaderReflection, reinterpret_cast<void**>(&CompileInfo)))
	{
		MsgAssert("���̴� ���÷��ǿ� �����߽��ϴ�.");
		return;
	}

	D3D11_SHADER_DESC Info;

	CompileInfo->GetDesc(&Info);

	D3D11_SHADER_INPUT_BIND_DESC ResDesc;

	// ���� ����� ������� �ؽ�ó ���÷����� �����Դϴ�.
	for (UINT i = 0; i < Info.BoundResources; i++)
	{
		// ���ҽ� ������ ������ �ǰ�
		CompileInfo->GetResourceBindingDesc(i, &ResDesc);

		std::string Name = ResDesc.Name;

		D3D_SHADER_INPUT_TYPE Type = ResDesc.Type;

		switch (Type)
		{
		case D3D_SIT_CBUFFER:
		{
			std::string UpperName = GameEngineString::ToUpper(ResDesc.Name);

			ID3D11ShaderReflectionConstantBuffer* CBufferPtr = CompileInfo->GetConstantBufferByName(ResDesc.Name);

			D3D11_SHADER_BUFFER_DESC BufferDesc;
			CBufferPtr->GetDesc(&BufferDesc);

			
			
			std::shared_ptr<GameEngineConstantBuffer> Buffer = GameEngineConstantBuffer::CreateAndFind(BufferDesc.Size, UpperName, BufferDesc);

			GameEngineConstantBufferSetter Setter;

			Setter.ParentShader = this;
			Setter.Name = UpperName;
			Setter.BindPoint = ResDesc.BindPoint;
			Setter.Res = Buffer;

			ResHelper.CreateConstantBufferSetter(Setter);


			int a = 0;

			break;
		}
		case D3D_SIT_TEXTURE:
		{
			// �� ���ҽ��� �ؽ�ó �Դϴ�.
			break;
		}
		case D3D_SIT_SAMPLER:
		{
			// �� ���ҽ��� ���÷� �Դϴ�.
			break;
		}
		default:
			break;
		}

	}

	// CompileInfo
}