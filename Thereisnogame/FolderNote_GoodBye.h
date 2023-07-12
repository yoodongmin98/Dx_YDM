#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class FolderNote_GoodBye : public G_ActorBase
{
public:
	// constrcuter destructer
	FolderNote_GoodBye();
	~FolderNote_GoodBye();

	// delete Function
	FolderNote_GoodBye(const FolderNote_GoodBye& _Other) = delete;
	FolderNote_GoodBye(FolderNote_GoodBye&& _Other) noexcept = delete;
	FolderNote_GoodBye& operator=(const FolderNote_GoodBye& _Other) = delete;
	FolderNote_GoodBye& operator=(FolderNote_GoodBye&& _Other) noexcept = delete;

	//Text�� �������ִ� �Լ��߰�
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FolderNote_GoodByes;

	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
};

