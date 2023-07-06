#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>


enum class MainMenuState
{
	None,
	Flag,
	DrawaPixel,
	Menu,
	Select,
};
// ¼³¸í :
class MainMenuLevel : public GameEngineLevel
{
public:
	static MainMenuLevel* ML;
	// constrcuter destructer
	MainMenuLevel();
	~MainMenuLevel();

	// delete Function
	MainMenuLevel(const MainMenuLevel& _Other) = delete;
	MainMenuLevel(MainMenuLevel&& _Other) noexcept = delete;
	MainMenuLevel& operator=(const MainMenuLevel& _Other) = delete;
	MainMenuLevel& operator=(MainMenuLevel&& _Other) noexcept = delete;
	std::shared_ptr<class FadeEffect> FEffect;

	void Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume);
	void Pause(GameEngineSoundPlayer _ControlSoundName);



	void CreateMainMenuArrow();
	void CreateLetter();
	void CreateFlag();

	
	void ChangeState(MainMenuState _State);
	void UpdateState(float _DeltaTime);

	void Letterfunction(float _DeltaTime);
	void Arrowfunction(float _DeltaTime);
	void Flagfunction(float _DeltaTime);

	float FlagValueSet(int SetValue,int _iValue);
	
	//ÇÃ·¡±× ´­·¶³Ä?
	void SetIsClicktheFlagTrue()
	{
		IsClicktheFlag = true;
	}
	//BackPanel´­·¶³Ä?
	void SetIsClickBackPanelTrue()
	{
		IsClickBackPanel = true;
	}
	//StartBox´­·¶³Ä?
	void SetIsClickStartButtonTrue()
	{
		IsClickStartButton = true;
	}

	void SoundLoad();

	GameEngineSoundPlayer MainBackSound;
	GameEngineSoundPlayer FlagIn;
	GameEngineSoundPlayer FlagOut;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;

private:
	MainMenuState StateValue = MainMenuState::Flag;

	std::shared_ptr<class Mouse> MousePtr = nullptr;

	std::shared_ptr<class Panel_Continue> PanelContinuePtr = nullptr;
	std::shared_ptr<class Panel_Back> PanelBackPtr = nullptr;
	std::shared_ptr<class SelectBox> SelectBoxPtr = nullptr;
	std::shared_ptr<class Arrow> ArrowPtr = nullptr;
	std::shared_ptr<class Panel_DrawaPixel> PixelPtr = nullptr;
	std::shared_ptr<class StartPictures> PicturesPtr = nullptr;

	void FlagStart();
	void FlagUpdate(float _DeltaTime);
	void FlagEnd();

	void DrawaPixelStart();
	void DrawaPixelUpdate(float _DeltaTime);
	void DrawaPixelEnd();

	void MenuStart();
	void MenuUpdate(float _DeltaTime);
	void MenuEnd();

	void SelectStart();
	void SelectUpdate(float _DeltaTime);
	void SelectEnd();


	std::vector<std::shared_ptr<class G_ActorBase>> LetterVector;
	std::vector<std::shared_ptr<class G_ActorBase>> ArrowVector;
	std::vector<std::shared_ptr<class G_ActorBase>> FlagVector;

	float FlagTime = 0.0f;
	float DrawaPixelTime = 0.0f;
	float MenuTime = 0.0f;
	
	bool IsClicktheFlag = false;
	bool IsClickBackPanel = false;
	bool IsClickStartButton = false;



	bool S1 = true;
	bool S2 = true;
	bool S3 = true;
	bool S4 = true;
	bool S5 = true;
	bool S6 = true;
	bool S7 = true;
	bool S8 = true;
	bool S9 = true;
	bool S10 = true;
	bool S11 = true;
	bool S12 = true;
	bool S13 = true;
	bool S14 = true;
	bool S15 = true;
	bool S16 = true;
	bool S17 = true;
	bool S18 = true;
	bool S19 = true;
	bool S20 = true;
	bool S21 = true;
	bool S22 = true;
	bool S23 = true;
};

