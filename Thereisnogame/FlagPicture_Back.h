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
	void CollisionInterCheck(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Chinese;
	std::shared_ptr<class GameEngineSpriteRenderer> F_French;
	std::shared_ptr<class GameEngineSpriteRenderer> F_Japan;
	std::shared_ptr<class GameEngineSpriteRenderer> F_Italian;
	std::shared_ptr<class GameEngineSpriteRenderer> F_German;
	std::shared_ptr<class GameEngineSpriteRenderer> F_Brazilian;
	std::shared_ptr<class GameEngineSpriteRenderer> F_Russian;
	std::shared_ptr<class GameEngineSpriteRenderer> F_Korea;
	std::shared_ptr<class GameEngineSpriteRenderer> F_Spanish;
	std::shared_ptr<class GameEngineSpriteRenderer> F_English;

	std::shared_ptr<class GameEngineSpriteRenderer> F_LockRender;
	std::shared_ptr<class GameEngineSpriteRenderer> F_LockOpenRender;
	std::shared_ptr<class GameEngineCollision> LockCollision;

	float LockFallTime = 0.0f;
	

	GameEngineSoundPlayer Sound;
};

