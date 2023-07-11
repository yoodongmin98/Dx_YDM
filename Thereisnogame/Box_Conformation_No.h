#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Box_Conformation_No : public G_ActorBase
{
public:
	// constrcuter destructer
	Box_Conformation_No();
	~Box_Conformation_No();

	// delete Function
	Box_Conformation_No(const Box_Conformation_No& _Other) = delete;
	Box_Conformation_No(Box_Conformation_No&& _Other) noexcept = delete;
	Box_Conformation_No& operator=(const Box_Conformation_No& _Other) = delete;
	Box_Conformation_No& operator=(Box_Conformation_No&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Boxs;
	std::shared_ptr<class GameEngineCollision> BoxsCollision;

	bool IsClick = false;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

