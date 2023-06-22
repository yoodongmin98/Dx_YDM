#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class FlagPicture : public G_ActorBase
{
public:
	FlagPicture();
	~FlagPicture();

	FlagPicture(const FlagPicture& _Other) = delete;
	FlagPicture(FlagPicture&& _Other) noexcept = delete;
	FlagPicture& operator=(const FlagPicture& _Other) = delete;
	FlagPicture& operator=(FlagPicture&& _Other) noexcept = delete;
	void PageAnimationSet();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Flag_s;
	


};

