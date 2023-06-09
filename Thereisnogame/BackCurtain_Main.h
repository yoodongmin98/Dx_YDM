#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class BackCurtain_Main : public G_ActorBase
{
public:
	// constrcuter destructer
	BackCurtain_Main();
	~BackCurtain_Main();

	// delete Function
	BackCurtain_Main(const BackCurtain_Main& _Other) = delete;
	BackCurtain_Main(BackCurtain_Main&& _Other) noexcept = delete;
	BackCurtain_Main& operator=(const BackCurtain_Main& _Other) = delete;
	BackCurtain_Main& operator=(BackCurtain_Main&& _Other) noexcept = delete;


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

