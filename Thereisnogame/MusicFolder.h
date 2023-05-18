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

	void BoxCroixDeathCheck();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicFolders;
	std::shared_ptr<class GameEngineCollision> MusicFoldersCollision;

	std::shared_ptr<class MusicFolderPanel> MusicFolderPanelPtr = nullptr;
	std::shared_ptr<class MusicNote_Archive> MusicNote_ArchivePtr = nullptr;
	std::shared_ptr<class MusicNote_Radio> MusicNote_RadioPtr = nullptr;
	std::shared_ptr<class MusicNote_Rain> MusicNote_RainPtr = nullptr;
	std::shared_ptr<class MusicNote_Walnut> MusicNote_WalnutPtr = nullptr;
	std::shared_ptr<class MediaPlayer> MediaPlayerPtr = nullptr;
	std::shared_ptr<class MediaPlay> MediaPlayPtr = nullptr;
	std::shared_ptr<class MediaPause> MediaPausePtr = nullptr;
	std::shared_ptr<class MediaPicture> MediaPicturePtr = nullptr;
	std::shared_ptr<class BoxCroix_Music> BoxCroixPtr = nullptr;
};

