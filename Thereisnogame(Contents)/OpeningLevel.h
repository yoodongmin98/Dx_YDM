#pragma once
#include <GameEngineCore\GameEngineLevel.h>


// Ό³Έν :
class OpeningLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	OpeningLevel();
	~OpeningLevel();

	// delete Function
	OpeningLevel(const OpeningLevel& _Other) = delete;
	OpeningLevel(OpeningLevel&& _Other) noexcept = delete;
	OpeningLevel& operator=(const OpeningLevel& _Other) = delete;
	OpeningLevel& operator=(OpeningLevel&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;
private:
};

