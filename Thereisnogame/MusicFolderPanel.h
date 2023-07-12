#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MusicFolderPanel : public G_ActorBase
{
public:
	// constrcuter destructer
	MusicFolderPanel();
	~MusicFolderPanel();

	// delete Function
	MusicFolderPanel(const MusicFolderPanel& _Other) = delete;
	MusicFolderPanel(MusicFolderPanel&& _Other) noexcept = delete;
	MusicFolderPanel& operator=(const MusicFolderPanel& _Other) = delete;
	MusicFolderPanel& operator=(MusicFolderPanel&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicFolderPanels;
	std::shared_ptr<class GameEngineSpriteRenderer> MusicTopFolderPanels;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

