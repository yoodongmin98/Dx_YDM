#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class C_Letter_T : public GameEngineActor
{
public:
	// constrcuter destructer
	C_Letter_T();
	~C_Letter_T();

	// delete Function
	C_Letter_T(const C_Letter_T& _Other) = delete;
	C_Letter_T(C_Letter_T&& _Other) noexcept = delete;
	C_Letter_T& operator=(const C_Letter_T& _Other) = delete;
	C_Letter_T& operator=(C_Letter_T&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_T;
	
	float TestTime = 0.0f;

};

