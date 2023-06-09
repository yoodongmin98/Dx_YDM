#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class C2_BackGround : public GameEngineActor
{
public:
	// constrcuter destructer
	C2_BackGround();
	~C2_BackGround();

	// delete Function
	C2_BackGround(const C2_BackGround& _Other) = delete;
	C2_BackGround(C2_BackGround&& _Other) noexcept = delete;
	C2_BackGround& operator=(const C2_BackGround& _Other) = delete;
	C2_BackGround& operator=(C2_BackGround&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
};

