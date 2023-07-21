#pragma once
#include <GameEngineCore/GameEngineRenderTarget.h>
#include <GameEngineCore/GameEngineSprite.h>

// 카메라를 1개 더만들고 말지.
// 설명 :
class DisTortion : public GameEnginePostProcess
{
public:
	// constrcuter destructer
	DisTortion();
	~DisTortion();

	// delete Function
	DisTortion(const DisTortion& _Other) = delete;
	DisTortion(DisTortion&& _Other) noexcept = delete;
	DisTortion& operator=(const DisTortion& _Other) = delete;
	DisTortion& operator=(DisTortion&& _Other) noexcept = delete;

protected:
	void Start(GameEngineRenderTarget* _Target) override;
	void Effect(GameEngineRenderTarget* _Target, float _DeltaTime) override;

private:
	std::shared_ptr<GameEngineRenderUnit> OldUnit;
	std::shared_ptr<GameEngineSprite> OldSprite;

	RenderBaseValue OldData;

	int Index = 0;
};

