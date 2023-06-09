#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class FolderNote_Password : public G_ActorBase
{
public:
	// constrcuter destructer
	FolderNote_Password();
	~FolderNote_Password();

	// delete Function
	FolderNote_Password(const FolderNote_Password& _Other) = delete;
	FolderNote_Password(FolderNote_Password&& _Other) noexcept = delete;
	FolderNote_Password& operator=(const FolderNote_Password& _Other) = delete;
	FolderNote_Password& operator=(FolderNote_Password&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FolderNote_Passwords;
};

