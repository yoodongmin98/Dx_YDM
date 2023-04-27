#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "LetterBase.h"

// ���� :
class C_Letter_T : public LetterBase
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
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_H;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_E;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_R;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_e;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_I;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_S;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_N;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_O;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_G;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_A;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_M;
	std::shared_ptr<class GameEngineSpriteRenderer> Letter_E2;
	float TestTime = 0.0f;

};
