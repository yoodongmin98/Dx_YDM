#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class FolderNote : public G_ActorBase
{
public:
	// constrcuter destructer
	FolderNote();
	~FolderNote();

	// delete Function
	FolderNote(const FolderNote& _Other) = delete;
	FolderNote(FolderNote&& _Other) noexcept = delete;
	FolderNote& operator=(const FolderNote& _Other) = delete;
	FolderNote& operator=(FolderNote&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FolderNotes;

	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
};

