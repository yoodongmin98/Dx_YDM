#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class ProgramLoadingLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	ProgramLoadingLevel();
	~ProgramLoadingLevel();

	// delete Function
	ProgramLoadingLevel(const ProgramLoadingLevel& _Other) = delete;
	ProgramLoadingLevel(ProgramLoadingLevel&& _Other) noexcept = delete;
	ProgramLoadingLevel& operator=(const ProgramLoadingLevel& _Other) = delete;
	ProgramLoadingLevel& operator=(ProgramLoadingLevel&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:


};

