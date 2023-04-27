#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>


class LetterBase : public GameEngineActor
{
public:

	LetterBase();
	~LetterBase();


	LetterBase(const LetterBase& _Other) = delete;
	LetterBase(LetterBase&& _Other) noexcept = delete;
	LetterBase& operator=(const LetterBase& _Other) = delete;
	LetterBase& operator=(LetterBase&& _Other) noexcept = delete;

	void Init(std::shared_ptr<GameEngineSpriteRenderer> _Render, const std::string_view& _ImageName, float4 _Scale, float4 _Position);
	void LetterRepeat(float _MoveValue, float _DeltaTime);
	//void LetterDown(float _EndYvalue, float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	

private:
	float ReverseTime = 0.0f;
	float LetterDownTime = 0.0f;


	float4 EndPos = float4::Zero;
	bool DownCheck = false;
};

