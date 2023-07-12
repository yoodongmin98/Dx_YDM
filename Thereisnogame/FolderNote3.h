#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class FolderNote3 : public G_ActorBase
{
public:
	// constrcuter destructer
	FolderNote3();
	~FolderNote3();

	// delete Function
	FolderNote3(const FolderNote3& _Other) = delete;
	FolderNote3(FolderNote3&& _Other) noexcept = delete;
	FolderNote3& operator=(const FolderNote3& _Other) = delete;
	FolderNote3& operator=(FolderNote3&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FolderNote3s;

	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
};

