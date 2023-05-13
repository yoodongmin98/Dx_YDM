#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
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

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PrivateNotes;
};

