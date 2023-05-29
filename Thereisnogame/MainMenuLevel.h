#pragma once
#include <GameEngineCore\GameEngineLevel.h>

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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	MainMenuState StateValue = MainMenuState::Flag;

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
};

