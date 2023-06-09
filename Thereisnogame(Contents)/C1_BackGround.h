#pragma once
#include <GameEngineCore/GameEngineActor.h>


class C1_BackGround : public GameEngineActor
{
public:
	C1_BackGround();
	~C1_BackGround();

	C1_BackGround(const C1_BackGround& _Other) = delete;
	C1_BackGround(C1_BackGround&& _Other) noexcept = delete;
	C1_BackGround& operator=(const C1_BackGround& _Other) = delete;
	C1_BackGround& operator=(C1_BackGround&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BackGround;
};

