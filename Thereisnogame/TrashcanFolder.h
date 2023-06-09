#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class TrashcanFolder : public G_ActorBase
{
public:
	// constrcuter destructer
	TrashcanFolder();
	~TrashcanFolder();

	// delete Function
	TrashcanFolder(const TrashcanFolder& _Other) = delete;
	TrashcanFolder(TrashcanFolder&& _Other) noexcept = delete;
	TrashcanFolder& operator=(const TrashcanFolder& _Other) = delete;
	TrashcanFolder& operator=(TrashcanFolder&& _Other) noexcept = delete;

	void RenderAndCollisionCheck();
	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TrashcanFolderClose;
	std::shared_ptr<class GameEngineSpriteRenderer> TrashcanFolderOpen;

	std::shared_ptr<class GameEngineCollision> TrashcanFolderCollision;

	std::shared_ptr<class GoodbyeIcon> GoodbyeIconPtr;
	std::shared_ptr<class PasswordIcon> PasswordIconPtr;
	std::shared_ptr<class PinBall_Icon> PinBall_IconPtr;
	
	std::shared_ptr<class TrashCanFolderPanel> TrashCanFolderPanelPtr;

	std::shared_ptr<class FolderBackGround> FolderBackGroundPtr = nullptr;
	std::shared_ptr<class BoxCroix_TrashCanFolder> BoxCroix_TrashCanFolderPtr;



};

