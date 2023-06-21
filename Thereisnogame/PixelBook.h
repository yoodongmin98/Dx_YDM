#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class PixelBook : public G_ActorBase
{
public:
	PixelBook();
	~PixelBook();

	PixelBook(const PixelBook& _Other) = delete;
	PixelBook(PixelBook&& _Other) noexcept = delete;
	PixelBook& operator=(const PixelBook& _Other) = delete;
	PixelBook& operator=(PixelBook&& _Other) noexcept = delete;
	void PageAnimationSet();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PixelBooks;
	std::shared_ptr<class GameEngineCollision> PixelBooksCollision;

	int AnimationValue = 0;
};

