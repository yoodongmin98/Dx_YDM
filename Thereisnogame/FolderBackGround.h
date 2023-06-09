#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class FolderBackGround : public G_ActorBase
{
public:
	// constrcuter destructer
	FolderBackGround();
	~FolderBackGround();

	// delete Function
	FolderBackGround(const FolderBackGround& _Other) = delete;
	FolderBackGround(FolderBackGround&& _Other) noexcept = delete;
	FolderBackGround& operator=(const FolderBackGround& _Other) = delete;
	FolderBackGround& operator=(FolderBackGround&& _Other) noexcept = delete;

	void CollisionInteractableCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FolderBackGrounds;
};

