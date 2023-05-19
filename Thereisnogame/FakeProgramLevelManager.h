#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class FakeProgramLevelManager
{
public:
	// constrcuter destructer
	FakeProgramLevelManager();
	~FakeProgramLevelManager();

	// delete Function
	FakeProgramLevelManager(const FakeProgramLevelManager& _Other) = delete;
	FakeProgramLevelManager(FakeProgramLevelManager&& _Other) noexcept = delete;
	FakeProgramLevelManager& operator=(const FakeProgramLevelManager& _Other) = delete;
	FakeProgramLevelManager& operator=(FakeProgramLevelManager&& _Other) noexcept = delete;

protected:
	
private:


};

