#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class FakeProgramLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	FakeProgramLevel();
	~FakeProgramLevel();

	// delete Function
	FakeProgramLevel(const FakeProgramLevel& _Other) = delete;
	FakeProgramLevel(FakeProgramLevel&& _Other) noexcept = delete;
	FakeProgramLevel& operator=(const FakeProgramLevel& _Other) = delete;
	FakeProgramLevel& operator=(FakeProgramLevel&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:


};

