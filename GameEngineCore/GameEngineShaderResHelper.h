#pragma once
#include "GameEngineConstantBuffer.h"
#include "GameEngineTexture.h"

// ��� �ؽ�ó�� ������۰� 
class GameEngineShaderResources
{
public:
	std::string Name;
	class GameEngineShader* ParentShader;
	int BindPoint = -1; // b0 t0 ���� ���° ���Կ� ���õǾ�� �ϴ����� ���� ����.

public:
	virtual void Setting() = 0;
};

class GameEngineConstantBufferSetter : public GameEngineShaderResources
{
public:
	std::shared_ptr<GameEngineConstantBuffer> Res;
	const void* CPUData;
	UINT CPUDataSize;

	void Setting() override;
};

class GameEngineTextureSetter : public GameEngineShaderResources
{
public:
	std::shared_ptr<GameEngineTexture> Res;
};

class GameEngineShaderResHelper
{
private:
	std::multimap<std::string, GameEngineConstantBufferSetter> ConstantBuffer;

public:
	void CreateConstantBufferSetter(const GameEngineConstantBufferSetter& _Buffer) 
	{
		ConstantBuffer.insert(std::make_pair(_Buffer.Name, _Buffer));
	}

	bool IsConstantBuffer(const std::string_view& _Name)
	{
		std::string UpperName = GameEngineString::ToUpper(_Name);

		std::multimap<std::string, GameEngineConstantBufferSetter>::iterator FindIter = ConstantBuffer.find(UpperName);

		if (ConstantBuffer.end() == FindIter)
		{
			return false;
		}

		return true;
	}

	template<typename DataType>
	void SetConstantBufferLink(const std::string_view& _Name, const DataType& _Data)
	{
		SetConstantBufferLink(_Name, reinterpret_cast<const void*>(&_Data), sizeof(DataType));
	}

	void SetConstantBufferLink(const std::string_view& _Name, const void* _Data, UINT _Size);

	void Copy(const GameEngineShaderResHelper& _ResHelper);

	void Setting();
};
