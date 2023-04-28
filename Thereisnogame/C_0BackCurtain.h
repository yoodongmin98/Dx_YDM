#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class C_0BackCurtain : public GameEngineActor
{
public:
	// constrcuter destructer
	C_0BackCurtain();
	~C_0BackCurtain();

	// delete Function
	C_0BackCurtain(const C_0BackCurtain& _Other) = delete;
	C_0BackCurtain(C_0BackCurtain&& _Other) noexcept = delete;
	C_0BackCurtain& operator=(const C_0BackCurtain& _Other) = delete;
	C_0BackCurtain& operator=(C_0BackCurtain&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftCurtain;
	std::shared_ptr<class GameEngineSpriteRenderer> RightCurtain;

};

