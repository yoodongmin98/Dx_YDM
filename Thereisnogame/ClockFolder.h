#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class ClockFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	ClockFolder();
	~ClockFolder();

	// delete Function
	ClockFolder(const ClockFolder& _Other) = delete;
	ClockFolder(ClockFolder&& _Other) noexcept = delete;
	ClockFolder& operator=(const ClockFolder& _Other) = delete;
	ClockFolder& operator=(ClockFolder&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ClockFolders;
	std::shared_ptr<class GameEngineCollision> ClockFoldersCollision;

	std::shared_ptr<class ClockPaddle0> ClockPaddle0Ptr;
	std::shared_ptr<class ClockPaddle1> ClockPaddle1Ptr;
	std::shared_ptr<class ClockPaddle2> ClockPaddle2Ptr;
	std::shared_ptr<class ClockPaddle3> ClockPaddle3Ptr;
	std::shared_ptr<class ClockPaddle4> ClockPaddle4Ptr;
	std::shared_ptr<class ClockPaddle5> ClockPaddle5Ptr;
	std::shared_ptr<class ClockPaddle6> ClockPaddle6Ptr;
	std::shared_ptr<class ClockPaddle7> ClockPaddle7Ptr;
	std::shared_ptr<class ClockPaddle8> ClockPaddle8Ptr;
	std::shared_ptr<class ClockPaddle9> ClockPaddle9Ptr;
	//언더바
	std::shared_ptr<class ClockUnderBar> ClockUnderBarPtr;
	//박스
	std::shared_ptr<class BoxCroix_ClockPanel> BoxCroix_ClockPanelPtr;
	//패널
	//std::shared_ptr<class GameEngineCollision> ClockFoldersCollision;

};

