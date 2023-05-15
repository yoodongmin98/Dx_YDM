#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// ���� :
class Nut_Open : public S_ActorBase
{
public:
	// constrcuter destructer
	Nut_Open();
	~Nut_Open();

	// delete Function
	Nut_Open(const Nut_Open& _Other) = delete;
	Nut_Open(Nut_Open&& _Other) noexcept = delete;
	Nut_Open& operator=(const Nut_Open& _Other) = delete;
	Nut_Open& operator=(Nut_Open&& _Other) noexcept = delete;

	//Text�� �������ִ� �Լ��߰�
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Nut_Opens;
};

