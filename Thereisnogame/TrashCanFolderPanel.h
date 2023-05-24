#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class TrashCanFolderPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	TrashCanFolderPanel();
	~TrashCanFolderPanel();

	// delete Function
	TrashCanFolderPanel(const TrashCanFolderPanel& _Other) = delete;
	TrashCanFolderPanel(TrashCanFolderPanel&& _Other) noexcept = delete;
	TrashCanFolderPanel& operator=(const TrashCanFolderPanel& _Other) = delete;
	TrashCanFolderPanel& operator=(TrashCanFolderPanel&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TrashCanFolderPanels;
	std::shared_ptr<class GameEngineSpriteRenderer> TrashCanTopFolderPanels;

	std::shared_ptr<class BoxCroix_Music> Croix;

};

