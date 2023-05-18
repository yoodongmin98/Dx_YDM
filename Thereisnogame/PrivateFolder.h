#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PrivateFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivateFolder();
	~PrivateFolder();

	// delete Function
	PrivateFolder(const PrivateFolder& _Other) = delete;
	PrivateFolder(PrivateFolder&& _Other) noexcept = delete;
	PrivateFolder& operator=(const PrivateFolder& _Other) = delete;
	PrivateFolder& operator=(PrivateFolder&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateFolders;
	std::shared_ptr<class GameEngineCollision> PrivateFoldersCollision;
};

