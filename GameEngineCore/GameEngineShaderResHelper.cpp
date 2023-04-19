#include "PrecompileHeader.h"
#include "GameEngineShaderResHelper.h"
#include "GameEngineShader.h"
#include "GameEngineConstantBuffer.h"


void GameEngineShaderResHelper::Copy(const GameEngineShaderResHelper& _ResHelper) 
{

	for (const std::pair<std::string, GameEngineConstantBufferSetter>& Setter : _ResHelper.ConstantBuffer)
	{
		ConstantBuffer.insert(Setter);
	}
	

}

void GameEngineConstantBufferSetter::Setting() 
{
	Res->ChangeData(CPUData, CPUDataSize);

	ShaderType Type = ParentShader->GetType();

	switch (Type)
	{
	case ShaderType::None:
	{
		MsgAssert("� ���̴��� ���õ��� �˼����� ������� �Դϴ�.");
		break;
	}
	case ShaderType::Vertex:
	{
		Res->VSSetting(BindPoint);
		break;
	}
	case ShaderType::Pixel:
	{
		Res->PSSetting(BindPoint);
		break;
	}
	default:
		break;
	}

}


void GameEngineShaderResHelper::Setting() 
{
	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator StartIter = ConstantBuffer.begin();
	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator EndIter = ConstantBuffer.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		GameEngineConstantBufferSetter& Setter = StartIter->second;
		Setter.Setting();
	}
}

void GameEngineShaderResHelper::SetConstantBufferLink(const std::string_view& _Name, const void* _Data, UINT _Size)
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator FindIter = ConstantBuffer.find(UpperName);
	
	if (ConstantBuffer.end() == FindIter)
	{
		MsgAssert("�������� �ʴ� ������۸� �����Ϸ��� �߽��ϴ�." + UpperName);
		return;
	}

	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator NameStartIter = ConstantBuffer.lower_bound(UpperName);
	std::multimap<std::string, GameEngineConstantBufferSetter>::iterator NameEndIter = ConstantBuffer.upper_bound(UpperName);

	for (; NameStartIter != NameEndIter; ++NameStartIter)
	{
		GameEngineConstantBufferSetter& Setter = NameStartIter->second;

		if (Setter.Res->GetBufferSize() != _Size)
		{
			MsgAssert("������ۿ� �����Ϸ��� �������� ũ�Ⱑ �ٸ��ϴ�. ������� : " + std::to_string(Setter.Res->GetBufferSize()) + "������ ������ ������" + std::to_string(_Size) + UpperName);
			return;
		}
		
		Setter.CPUData = _Data;
		Setter.CPUDataSize = _Size;
	}

}