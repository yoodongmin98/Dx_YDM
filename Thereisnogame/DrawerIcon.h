#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class DrawerIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	DrawerIcon();
	~DrawerIcon();

	// delete Function
	DrawerIcon(const DrawerIcon& _Other) = delete;
	DrawerIcon(DrawerIcon&& _Other) noexcept = delete;
	DrawerIcon& operator=(const DrawerIcon& _Other) = delete;
	DrawerIcon& operator=(DrawerIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> DrawerIcons;
	std::shared_ptr<class GameEngineCollision> DrawerIconsCollision;

	std::shared_ptr<class DrawerPicture> DrawerPicturePtr;
	//박스 머시기머시기
};

