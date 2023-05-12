#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class DayPicture : public G_ActorBase
{
public:
	// constrcuter destructer
	DayPicture();
	~DayPicture();

	// delete Function
	DayPicture(const DayPicture& _Other) = delete;
	DayPicture(DayPicture&& _Other) noexcept = delete;
	DayPicture& operator=(const DayPicture& _Other) = delete;
	DayPicture& operator=(DayPicture&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Picture_Day;
	std::shared_ptr<class GameEngineSpriteRenderer> Picture_Night;
	
};

