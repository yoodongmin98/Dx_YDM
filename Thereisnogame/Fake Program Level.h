#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// Ό³Έν :
class FakeProgramLevel : public GameEngineLevel
{
public:
	static FakeProgramLevel* FP;
	// constrcuter destructer
	FakeProgramLevel();
	~FakeProgramLevel();

	// delete Function
	FakeProgramLevel(const FakeProgramLevel& _Other) = delete;
	FakeProgramLevel(FakeProgramLevel&& _Other) noexcept = delete;
	FakeProgramLevel& operator=(const FakeProgramLevel& _Other) = delete;
	FakeProgramLevel& operator=(FakeProgramLevel&& _Other) noexcept = delete;
	std::shared_ptr<class FadeEffect> FEffect;

	void FPlay(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume);
	void FPause(GameEngineSoundPlayer _ControlSoundName);
	void PausePlay(GameEngineSoundPlayer _ControlSoundName);

	void SoundLoad();

	void FolderCreate();

	
	GameEngineSoundPlayer Sound;

	void ChangeBGM(const std::string_view& _MusicName, float _Volume);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;

private:

	std::shared_ptr<class Mouse> MousePtr = nullptr;
};

