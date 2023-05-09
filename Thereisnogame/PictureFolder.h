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


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PictureFolders;

};

