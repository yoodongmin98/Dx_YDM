#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BackCurtain_Ending : public G_ActorBase
{
public:
	// constrcuter destructer
	BackCurtain_Ending();
	~BackCurtain_Ending();

	// delete Function
	BackCurtain_Ending(const BackCurtain_Ending& _Other) = delete;
	BackCurtain_Ending(BackCurtain_Ending&& _Other) noexcept = delete;
	BackCurtain_Ending& operator=(const BackCurtain_Ending& _Other) = delete;
	BackCurtain_Ending& operator=(BackCurtain_Ending&& _Other) noexcept = delete;


	void CurtainOpen();
	void CurtainClose();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftCurtain;
	std::shared_ptr<class GameEngineSpriteRenderer> RightCurtain;

};

