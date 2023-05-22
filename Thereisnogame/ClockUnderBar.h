#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockUnderBar : public G_ActorBase
{
public:
	static ClockUnderBar* CM;
	// constrcuter destructer
	ClockUnderBar();
	~ClockUnderBar();

	// delete Function
	ClockUnderBar(const ClockUnderBar& _Other) = delete;
	ClockUnderBar(ClockUnderBar&& _Other) noexcept = delete;
	ClockUnderBar& operator=(const ClockUnderBar& _Other) = delete;
	ClockUnderBar& operator=(ClockUnderBar&& _Other) noexcept = delete;

	void ClockPasswordPush(int _Number)
	{
		PassWordCheck.push_back(_Number);
	}

	void PushIntCheck(int _Value);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars1;
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars2;
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars3;
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars4;
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars5;
	std::shared_ptr<class GameEngineSpriteRenderer> ClockUnderBars6;

	std::vector<int> PassWordCheck;
	std::vector<std::shared_ptr<GameEngineSpriteRenderer>> PasswordUnderBar;

	float4 NumberPosition = float4::Zero;
};

