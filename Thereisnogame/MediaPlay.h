#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class MediaPlay : public G_ActorBase
{
public:
	static MediaPlay* MainMediaPlay;
	// constrcuter destructer
	MediaPlay();
	~MediaPlay();

	// delete Function
	MediaPlay(const MediaPlay& _Other) = delete;
	MediaPlay(MediaPlay&& _Other) noexcept = delete;
	MediaPlay& operator=(const MediaPlay& _Other) = delete;
	MediaPlay& operator=(MediaPlay&& _Other) noexcept = delete;

	void SetMediaPlayoff(int _Value);

	
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPlays;
	std::shared_ptr<class GameEngineSpriteRenderer> MediaPlayoffs;
	std::shared_ptr<class GameEngineCollision> MediaPlaysCollision;
};

