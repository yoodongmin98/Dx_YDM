#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
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

	std::shared_ptr<GameEngineSpriteRenderer> ChangeMusicRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender);
	void ChangeMusicPicture(int _Value);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> WalnutPicture;
	std::shared_ptr<class GameEngineSpriteRenderer> ArchivePicture;
	std::shared_ptr<class GameEngineSpriteRenderer> RainPicture;
	std::shared_ptr<class GameEngineSpriteRenderer> RadioPicture;

	std::vector<std::shared_ptr<class GameEngineSpriteRenderer>> PictureSelectVector;

	std::shared_ptr<class GameEngineSpriteRenderer> WhatisPicture;
};

