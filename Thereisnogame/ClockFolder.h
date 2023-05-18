#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ClockFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockFolder();
	~ClockFolder();

	// delete Function
	ClockFolder(const ClockFolder& _Other) = delete;
	ClockFolder(ClockFolder&& _Other) noexcept = delete;
	ClockFolder& operator=(const ClockFolder& _Other) = delete;
	ClockFolder& operator=(ClockFolder&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockFolders;
	std::shared_ptr<class GameEngineCollision> ClockFoldersCollision;
};

