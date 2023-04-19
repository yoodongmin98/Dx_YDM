#pragma once
#include "GameEngineComponent.h"
#include "GameEngineShader.h"

// ���� :
class GameEngineRenderer : public GameEngineComponent
{
public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	// ������������ ���õǾ� �ְ�
	// � ���̴��� ����ߴٴ� �� �˾ƾ� �ϰ�
	// �� ���̴����� � �ؽ�ó�� ����߰�
	// � ���÷� � ������۸� ����ߴ����� �˾ƾ� �Ѵ�.
	void SetPipeLine(const std::string_view& _Name);

	inline GameEngineShaderResHelper& GetShaderResHelper() 
	{
		return ShaderResHelper;
	}

protected:
	void Render(float _Delta) override;

private:
	// Pipe��
	// GameEngineShaderResHelper �� �������� ������ �� �Ǵ� ���� �˴ϴ�.
	std::shared_ptr<class GameEngineRenderingPipeLine > Pipe;

	GameEngineShaderResHelper ShaderResHelper;
};

