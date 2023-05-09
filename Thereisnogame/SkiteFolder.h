#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class SkiteFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	SkiteFolder();
	~SkiteFolder();

	// delete Function
	SkiteFolder(const SkiteFolder& _Other) = delete;
	SkiteFolder(SkiteFolder&& _Other) noexcept = delete;
	SkiteFolder& operator=(const SkiteFolder& _Other) = delete;
	SkiteFolder& operator=(SkiteFolder&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SkiteFolders;

};

