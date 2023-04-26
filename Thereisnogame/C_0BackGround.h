#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class C_0BackGround : public GameEngineActor
{
public:
	// constrcuter destructer
	C_0BackGround();
	~C_0BackGround();

	// delete Function
	C_0BackGround(const C_0BackGround& _Other) = delete;
	C_0BackGround(C_0BackGround&& _Other) noexcept = delete;
	C_0BackGround& operator=(const C_0BackGround& _Other) = delete;
	C_0BackGround& operator=(C_0BackGround&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftCurtain;
	std::shared_ptr<class GameEngineSpriteRenderer> RightCurtain;

};

