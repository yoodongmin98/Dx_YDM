#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Panel_DrawaPixel : public G_ActorBase
{
public:
	// constrcuter destructer
	Panel_DrawaPixel();
	~Panel_DrawaPixel();

	// delete Function
	Panel_DrawaPixel(const Panel_DrawaPixel& _Other) = delete;
	Panel_DrawaPixel(Panel_DrawaPixel&& _Other) noexcept = delete;
	Panel_DrawaPixel& operator=(const Panel_DrawaPixel& _Other) = delete;
	Panel_DrawaPixel& operator=(Panel_DrawaPixel&& _Other) noexcept = delete;

	void Down(float _DeltaTime);
	void Up(float _DeltaTime);

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Panel_CNC;
	std::shared_ptr<class GameEngineSpriteRenderer> Panel_Book;
	std::shared_ptr<class GameEngineSpriteRenderer> Panel_Box;
};

