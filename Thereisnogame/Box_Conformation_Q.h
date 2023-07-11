#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"
// Ό³Έν :
class Box_Conformation_Q : public G_ActorBase
{
public:
	// constrcuter destructer
	Box_Conformation_Q();
	~Box_Conformation_Q();

	// delete Function
	Box_Conformation_Q(const Box_Conformation_Q& _Other) = delete;
	Box_Conformation_Q(Box_Conformation_Q&& _Other) noexcept = delete;
	Box_Conformation_Q& operator=(const Box_Conformation_Q& _Other) = delete;
	Box_Conformation_Q& operator=(Box_Conformation_Q&& _Other) noexcept = delete;

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Boxs;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

