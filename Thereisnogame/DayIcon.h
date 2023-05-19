#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class DayIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	DayIcon();
	~DayIcon();

	// delete Function
	DayIcon(const DayIcon& _Other) = delete;
	DayIcon(DayIcon&& _Other) noexcept = delete;
	DayIcon& operator=(const DayIcon& _Other) = delete;
	DayIcon& operator=(DayIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Icon_BigDay;
	std::shared_ptr<class GameEngineSpriteRenderer> Icon_BigNight;
	std::shared_ptr<class GameEngineSpriteRenderer> Icon_SmallDay;
	std::shared_ptr<class GameEngineSpriteRenderer> Icon_SmallNight;

	std::shared_ptr<class GameEngineCollision> DayIconCollision;

	std::shared_ptr<class DayPicture> DayPicturePtr;
	std::shared_ptr<class DayTree> DayTreePtr;

};

