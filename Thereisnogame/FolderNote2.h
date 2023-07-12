#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class FolderNote2 : public G_ActorBase
{
public:
	// constrcuter destructer
	FolderNote2();
	~FolderNote2();

	// delete Function
	FolderNote2(const FolderNote2& _Other) = delete;
	FolderNote2(FolderNote2&& _Other) noexcept = delete;
	FolderNote2& operator=(const FolderNote2& _Other) = delete;
	FolderNote2& operator=(FolderNote2&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FolderNote2s;

	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
	std::shared_ptr<class GameEngineFontRenderer> Font3;
	std::shared_ptr<class GameEngineFontRenderer> Font4;
	std::shared_ptr<class GameEngineFontRenderer> Font5;
};

