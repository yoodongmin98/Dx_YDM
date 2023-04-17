#pragma once
#include "GameEngineComponent.h"

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

	void SetPipeLine(const std::string_view& _Name);

protected:
	void Render(float _Delta) override;

private:
	std::shared_ptr<class GameEngineRenderingPipeLine > Pipe;

};

