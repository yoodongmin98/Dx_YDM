#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MusicFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	MusicFolder();
	~MusicFolder();

	// delete Function
	MusicFolder(const MusicFolder& _Other) = delete;
	MusicFolder(MusicFolder&& _Other) noexcept = delete;
	MusicFolder& operator=(const MusicFolder& _Other) = delete;
	MusicFolder& operator=(MusicFolder&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicFolders;
	std::shared_ptr<class GameEngineCollision> MusicFoldersCollision;

	std::shared_ptr<class BoxCroix> Croix;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision=nullptr;

};

