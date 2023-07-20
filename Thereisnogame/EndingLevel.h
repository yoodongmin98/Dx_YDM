#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// Ό³Έν :
class EndingLevel : public GameEngineLevel
{
public:
	static EndingLevel* EL;
	// constrcuter destructer
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;
	std::shared_ptr<class FadeEffect> FEffect;

	void StopBGM();
	void BGMPauseOn();
	void BGMPauseOff();
	void SoundLoad();
	void KeySetting();
	GameEngineSoundPlayer MainBGM;
	GameEngineSoundPlayer Sound;
	GameEngineSoundPlayer ChangeBGM(const std::string_view& _MusicName);

	GameEngineSoundPlayer Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;
private:
	std::shared_ptr<class Mouse> MousePtr = nullptr;
	std::shared_ptr<class BackCurtain_Ending> BackCurtain_EndingPtr = nullptr;
	std::shared_ptr<class AlphaCircle> AlphaCirclePtr = nullptr;

	float LevelTime = 0.0f;
};

