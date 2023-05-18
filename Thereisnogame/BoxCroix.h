#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class BoxCroix : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix();
	~BoxCroix();

	// delete Function
	BoxCroix(const BoxCroix& _Other) = delete;
	BoxCroix(BoxCroix&& _Other) noexcept = delete;
	BoxCroix& operator=(const BoxCroix& _Other) = delete;
	BoxCroix& operator=(BoxCroix&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;
	std::shared_ptr<class GameEngineCollision> BoxCroixsCollision;

	std::shared_ptr<class MusicFolderPanel> MusicFolderPanels;
	std::shared_ptr<class MusicNote_Archive> MusicNote_Archives;
	std::shared_ptr<class MusicNote_Radio> MusicNote_Radios;
	std::shared_ptr<class MusicNote_Rain> MusicNote_Rains;
	std::shared_ptr<class MusicNote_Walnut> MusicNote_Walnuts;
	std::shared_ptr<class MediaPlayer> MediaPlayers;
	std::shared_ptr<class MediaPlay> MediaPlays;
	std::shared_ptr<class MediaPause> MediaPauses;
	std::shared_ptr<class MediaPicture> MediaPictures;
};

