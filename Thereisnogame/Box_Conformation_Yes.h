#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Box_Conformation_Yes : public G_ActorBase
{
public:
	// constrcuter destructer
	Box_Conformation_Yes();
	~Box_Conformation_Yes();

	// delete Function
	Box_Conformation_Yes(const Box_Conformation_Yes& _Other) = delete;
	Box_Conformation_Yes(Box_Conformation_Yes&& _Other) noexcept = delete;
	Box_Conformation_Yes& operator=(const Box_Conformation_Yes& _Other) = delete;
	Box_Conformation_Yes& operator=(Box_Conformation_Yes&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Boxs;
	
	std::shared_ptr<class GameEngineFontRenderer> Font;
};

