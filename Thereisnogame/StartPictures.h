#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
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
	void CollisionInteractableCheck(float _DeltaTime);
	GameEngineSoundPlayer Sound;
	GameEngineSoundPlayer Sound2;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
	std::shared_ptr<class FadeEffect> FEffect;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> RStartPictures;

	std::shared_ptr<class GameEngineSpriteRenderer> ChapterPictureOff;
	std::shared_ptr<class GameEngineSpriteRenderer> ChapterPictureOn;

	std::shared_ptr<class GameEngineCollision> StartPictureCollision;

	float FadeTime = 0.0f;
	bool IsClick = false;
};

