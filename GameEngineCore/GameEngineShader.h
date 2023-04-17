#pragma once

// ���� :
class GameEngineShader
{
public:
	// constrcuter destructer
	GameEngineShader();
	~GameEngineShader();

	// delete Function
	GameEngineShader(const GameEngineShader& _Other) = delete;
	GameEngineShader(GameEngineShader&& _Other) noexcept = delete;
	GameEngineShader& operator=(const GameEngineShader& _Other) = delete;
	GameEngineShader& operator=(GameEngineShader&& _Other) noexcept = delete;

	void CreateVersion(const std::string_view& _ShaderType, UINT _VersionHigt = 5, UINT _VersionLow = 0);
	inline void SetEntryPoint(const std::string_view& _EntryPoint) 
	{
		EntryPoint = _EntryPoint;
	}

protected:
	// Hlsl ������� ���� �ƿ� �ϰ���
	// ���̴� �ڵ带 2�������ͷ� ���������� �װ� �׷���ī�尡 ���ο� �����
	// ���̴��� ���̳ʸ� �ڵ�
	ID3DBlob* BinaryCode = nullptr;
	std::string Version = "";
	std::string EntryPoint = "";

private:
};

