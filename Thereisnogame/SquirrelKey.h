#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// ���� :
class SquirrelKey : public S_ActorBase
{
public:
	// constrcuter destructer
	SquirrelKey();
	~SquirrelKey();

	// delete Function
	SquirrelKey(const SquirrelKey& _Other) = delete;
	SquirrelKey(SquirrelKey&& _Other) noexcept = delete;
	SquirrelKey& operator=(const SquirrelKey& _Other) = delete;
	SquirrelKey& operator=(SquirrelKey&& _Other) noexcept = delete;

	//Text�� �������ִ� �Լ��߰�
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelKeys;
};

