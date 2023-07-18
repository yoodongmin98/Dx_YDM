#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Chap2StartTextActor : public G_ActorBase
{
public:
	Chap2StartTextActor();
	~Chap2StartTextActor();

	Chap2StartTextActor(const Chap2StartTextActor& _Other) = delete;
	Chap2StartTextActor(Chap2StartTextActor&& _Other) noexcept = delete;
	Chap2StartTextActor& operator=(const Chap2StartTextActor& _Other) = delete;
	Chap2StartTextActor& operator=(Chap2StartTextActor&& _Other) noexcept = delete;

	void SoundAndText(float _DeltaTime);
	void CallingText(float _DeltaTime);
	void ClockText(float _DeltaTime);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	float SoundTime = 0.0f;
	float CallingTime = 0.0f;
	float ClockTime = 0.0f;
	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
	std::shared_ptr<class GameEngineFontRenderer> Font6;
	std::shared_ptr<class GameEngineFontRenderer> Font7;
	std::shared_ptr<class GameEngineFontRenderer> Font8;
	std::shared_ptr<class GameEngineFontRenderer> Font9;
	std::shared_ptr<class GameEngineFontRenderer> Font10;
	std::shared_ptr<class GameEngineFontRenderer> Font11;
	std::shared_ptr<class GameEngineFontRenderer> Font12;
	std::shared_ptr<class GameEngineFontRenderer> Font13;
	std::shared_ptr<class GameEngineFontRenderer> Font14;
	std::shared_ptr<class GameEngineFontRenderer> Font15;
	
	std::shared_ptr<class GameEngineFontRenderer> CallingFont;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont2;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont3;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont4;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont5;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont6;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont7;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont8;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont9;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont10;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont11;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont12;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont13;
	std::shared_ptr<class GameEngineFontRenderer> CallingFont14;

	std::shared_ptr<class GameEngineFontRenderer> ClockFont;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont2;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont3;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont4;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont5;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont6;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont7;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont8;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont9;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont10;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont11;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont12;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont13;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont14;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont15;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont16;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont17;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont18;
	std::shared_ptr<class GameEngineFontRenderer> ClockFont19;

	bool TSDeathBool = true;
	bool TSDeathBool2 = true;
};

