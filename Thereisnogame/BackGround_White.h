#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BackGroundWhite : public GameEngineActor
{
public:
	// constrcuter destructer
	BackGroundWhite();
	~BackGroundWhite();

	// delete Function
	BackGroundWhite(const BackGroundWhite& _Other) = delete;
	BackGroundWhite(BackGroundWhite&& _Other) noexcept = delete;
	BackGroundWhite& operator=(const BackGroundWhite& _Other) = delete;
	BackGroundWhite& operator=(BackGroundWhite&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> WhiteBackGround;
};

