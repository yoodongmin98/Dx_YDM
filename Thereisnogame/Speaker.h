#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Speaker : public G_ActorBase
{
public:
	static Speaker* TM;
	Speaker();
	~Speaker();

	Speaker(const Speaker& _Other) = delete;
	Speaker(Speaker&& _Other) noexcept = delete;
	Speaker& operator=(const Speaker& _Other) = delete;
	Speaker& operator=(Speaker&& _Other) noexcept = delete;

	float4 GetSpeakerPosition()
	{
		return Speakers->GetTransform()->GetLocalPosition();
	}

	void SpeakerFall(float _DeltaTime);
	void ClickOnOffCheck(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Speakers;
	std::shared_ptr<class GameEngineSpriteRenderer> SpeakersOff;
	std::shared_ptr<class GameEngineCollision> SpeakersCollision;


	float Times = 0.0f;
};

