#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class RightRotate : public G_ActorBase
{
public:
	static RightRotate* MainRightRotate;
	// constrcuter destructer
	RightRotate();
	~RightRotate();

	// delete Function
	RightRotate(const RightRotate& _Other) = delete;
	RightRotate(RightRotate&& _Other) noexcept = delete;
	RightRotate& operator=(const RightRotate& _Other) = delete;
	RightRotate& operator=(RightRotate&& _Other) noexcept = delete;

	void ClearClickValue();

	void MinusHowManyClick()
	{
		HowManyClick -= 1;
	}

	int GetHowManyClick()
	{
		return HowManyClick;
	}

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> RightRotates;
	std::shared_ptr<class GameEngineCollision> RightRotatesCollision;

	int HowManyClick = 0;
};

