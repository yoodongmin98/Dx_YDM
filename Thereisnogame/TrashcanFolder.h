#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class TrashcanFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	TrashcanFolder();
	~TrashcanFolder();

	// delete Function
	TrashcanFolder(const TrashcanFolder& _Other) = delete;
	TrashcanFolder(TrashcanFolder&& _Other) noexcept = delete;
	TrashcanFolder& operator=(const TrashcanFolder& _Other) = delete;
	TrashcanFolder& operator=(TrashcanFolder&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TrashcanFolderClose;
	std::shared_ptr<class GameEngineSpriteRenderer> TrashcanFolderOpen;

	std::shared_ptr<class GameEngineCollision> TrashcanFolderCollision;

};

