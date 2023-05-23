#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class DayTree : public G_ActorBase
{
public:
	// constrcuter destructer
	DayTree();
	~DayTree();

	// delete Function
	DayTree(const DayTree& _Other) = delete;
	DayTree(DayTree&& _Other) noexcept = delete;
	DayTree& operator=(const DayTree& _Other) = delete;
	DayTree& operator=(DayTree&& _Other) noexcept = delete;

	void RotatePositionSet(std::shared_ptr<GameEngineSpriteRenderer> _Render, float4 _Pos, int _Value);
	std::shared_ptr<GameEngineSpriteRenderer> ChangeTreeRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender);
	void WhatisTreeRender();
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Tree_BigDay;
	std::shared_ptr<class GameEngineSpriteRenderer> Tree_BigNight;
	std::shared_ptr<class GameEngineSpriteRenderer> Tree_SmallDay;
	std::shared_ptr<class GameEngineSpriteRenderer> Tree_SmallNight;

	std::shared_ptr<class GameEngineSpriteRenderer> WhatisTree;

	std::vector<std::shared_ptr<class GameEngineSpriteRenderer>> TreeVector;

	std::shared_ptr<class GameEngineCollision> Tree_SmallCollision;
	std::shared_ptr<class GameEngineCollision> Tree_BigCollision;

};

