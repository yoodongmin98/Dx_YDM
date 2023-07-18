#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>

// ���� :
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

	void ReSetBGM();
	void StopBGM();
	void BGMPauseOn();
	void BGMPauseOff();

	void SoundLoad();

	void FolderCreate();

	void StartFunctions(float _DeltaTime);
	GameEngineSoundPlayer MainBGM;

	GameEngineSoundPlayer ChangeBGM(const std::string_view& _MusicName);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;

private:

	std::shared_ptr<class Mouse> MousePtr = nullptr;

	float StartTime = 0.0f;

	std::shared_ptr<class StartRedPanel> StartRedPanelPtr = nullptr;
	std::shared_ptr<class BoxCroix_StartRedPanel> BoxCroix_StartRedPanelPtr = nullptr;
	std::shared_ptr<class FolderBackGround> FolderBackGroundPtr = nullptr;
};

