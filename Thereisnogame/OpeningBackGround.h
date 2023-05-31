#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class OpeningBackGround : public G_ActorBase
{
public:
	OpeningBackGround();
	~OpeningBackGround();

	OpeningBackGround(const OpeningBackGround& _Other) = delete;
	OpeningBackGround(OpeningBackGround&& _Other) noexcept = delete;
	OpeningBackGround& operator=(const OpeningBackGround& _Other) = delete;
	OpeningBackGround& operator=(OpeningBackGround&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> OpeningBackGrounds;
};

