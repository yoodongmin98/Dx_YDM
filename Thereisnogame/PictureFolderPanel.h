#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PictureFolderPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	PictureFolderPanel();
	~PictureFolderPanel();

	// delete Function
	PictureFolderPanel(const PictureFolderPanel& _Other) = delete;
	PictureFolderPanel(PictureFolderPanel&& _Other) noexcept = delete;
	PictureFolderPanel& operator=(const PictureFolderPanel& _Other) = delete;
	PictureFolderPanel& operator=(PictureFolderPanel&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PictureFolderPanels;
	std::shared_ptr<class GameEngineSpriteRenderer> PictureTopFolderPanels;

	std::shared_ptr<class BoxCroix_Music> Croix;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

