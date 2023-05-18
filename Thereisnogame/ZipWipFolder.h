#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class ZipWipFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	ZipWipFolder();
	~ZipWipFolder();

	// delete Function
	ZipWipFolder(const ZipWipFolder& _Other) = delete;
	ZipWipFolder(ZipWipFolder&& _Other) noexcept = delete;
	ZipWipFolder& operator=(const ZipWipFolder& _Other) = delete;
	ZipWipFolder& operator=(ZipWipFolder&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> ZipWipFolders;
	std::shared_ptr<class GameEngineCollision> ZipWipFoldersCollision;

};

