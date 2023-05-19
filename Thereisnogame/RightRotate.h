#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class RightRotate : public G_ActorBase
{
public:
	// constrcuter destructer
	RightRotate();
	~RightRotate();

	// delete Function
	RightRotate(const RightRotate& _Other) = delete;
	RightRotate(RightRotate&& _Other) noexcept = delete;
	RightRotate& operator=(const RightRotate& _Other) = delete;
	RightRotate& operator=(RightRotate&& _Other) noexcept = delete;

	//Text�� �������ִ� �Լ��߰�
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> RightRotates;
};

