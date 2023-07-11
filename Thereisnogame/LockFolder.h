#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class LockFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	LockFolder();
	~LockFolder();

	// delete Function
	LockFolder(const LockFolder& _Other) = delete;
	LockFolder(LockFolder&& _Other) noexcept = delete;
	LockFolder& operator=(const LockFolder& _Other) = delete;
	LockFolder& operator=(LockFolder&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LockFolders;
	std::shared_ptr<class GameEngineCollision> LockFoldersCollision;\

		std::shared_ptr<class GameEngineFontRenderer> Font;
};

