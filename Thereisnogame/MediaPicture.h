#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class MediaPicture : public G_ActorBase
{
public:
	// constrcuter destructer
	MediaPicture();
	~MediaPicture();

	// delete Function
	MediaPicture(const MediaPicture& _Other) = delete;
	MediaPicture(MediaPicture&& _Other) noexcept = delete;
	MediaPicture& operator=(const MediaPicture& _Other) = delete;
	MediaPicture& operator=(MediaPicture&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPictures;

};

