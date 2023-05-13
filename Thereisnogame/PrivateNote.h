#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class PrivateNote : public G_ActorBase
{
public:
	// constrcuter destructer
	PrivateNote();
	~PrivateNote();

	// delete Function
	PrivateNote(const PrivateNote& _Other) = delete;
	PrivateNote(PrivateNote&& _Other) noexcept = delete;
	PrivateNote& operator=(const PrivateNote& _Other) = delete;
	PrivateNote& operator=(PrivateNote&& _Other) noexcept = delete;

	//Text�� �������ִ� �Լ��߰�
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateNotes;
};

