#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MusicNote_Archive : public G_ActorBase
{
public:
	// constrcuter destructer
	MusicNote_Archive();
	~MusicNote_Archive();

	// delete Function
	MusicNote_Archive(const MusicNote_Archive& _Other) = delete;
	MusicNote_Archive(MusicNote_Archive&& _Other) noexcept = delete;
	MusicNote_Archive& operator=(const MusicNote_Archive& _Other) = delete;
	MusicNote_Archive& operator=(MusicNote_Archive&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicNote_Archives;
	std::shared_ptr<class GameEngineCollision> MusicNote_ArchivesCollision;
};

