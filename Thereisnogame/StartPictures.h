#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class StartPictures : public G_ActorBase
{
public:
	// constrcuter destructer
	StartPictures();
	~StartPictures();

	// delete Function
	StartPictures(const StartPictures& _Other) = delete;
	StartPictures(StartPictures&& _Other) noexcept = delete;
	StartPictures& operator=(const StartPictures& _Other) = delete;
	StartPictures& operator=(StartPictures&& _Other) noexcept = delete;

	void PictureDown(float _DeltaTime);
	void PictureUp(float _DeltaTime);
	void CollisionInteractableCheck();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> RStartPictures;

	std::shared_ptr<class GameEngineSpriteRenderer> ChapterPictureOff;
	std::shared_ptr<class GameEngineSpriteRenderer> ChapterPictureOn;

	std::shared_ptr<class GameEngineCollision> StartPictureCollision;

};

