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
// ���� :
class MainMenuLevel : public GameEngineLevel
{
public:
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
	
	void ChangeState(MainMenuState _State);
	void UpdateState(float _DeltaTime);

	void LetterDownfunction(float _DeltaTime);
	void LetterUpfunction(float _DeltaTime);
	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	MainMenuState StateValue = MainMenuState::Flag;

	std::shared_ptr<class Panel_Continue> PanelContinuePtr = nullptr;

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


	std::vector<std::shared_ptr<class G_ActorBase>> ActorVector;


};

