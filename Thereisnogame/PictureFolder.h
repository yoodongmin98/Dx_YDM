#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PictureFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	PictureFolder();
	~PictureFolder();

	// delete Function
	PictureFolder(const PictureFolder& _Other) = delete;
	PictureFolder(PictureFolder&& _Other) noexcept = delete;
	PictureFolder& operator=(const PictureFolder& _Other) = delete;
	PictureFolder& operator=(PictureFolder&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PictureFolders;
	std::shared_ptr<class GameEngineCollision> PictureFoldersCollision;

	std::shared_ptr<class PictureFolderPanel> PictureFolderPanelPtr = nullptr;
	std::shared_ptr<class DayIcon> DayIconPtr = nullptr;
	std::shared_ptr<class DrawerIcon> DrawerIconPtr = nullptr;
	std::shared_ptr<class CodeIcon> CodeIconPtr = nullptr;
	std::shared_ptr<class FolderBackGround> FolderBackGroundPtr = nullptr;
	std::shared_ptr<class BoxCroix_PictureFolder> BoxCroix_PictureFolderPtr = nullptr;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

