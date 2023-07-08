#pragma once
#include <GameEngineCore/GameEngineActor.h>


class LevelStateManager : public GameEngineActor
{
public:
	static LevelStateManager* MG;
	// constrcuter destructer
	LevelStateManager();
	~LevelStateManager();

	// delete Function
	LevelStateManager(const LevelStateManager& _Other) = delete;
	LevelStateManager(LevelStateManager&& _Other) noexcept = delete;
	LevelStateManager& operator=(const LevelStateManager& _Other) = delete;
	LevelStateManager& operator=(LevelStateManager&& _Other) noexcept = delete;
	//Chapter2----------------------------------------------------------------------------------------------------------
	//폴더 몇개열려있냐?
	void PlusCollisionValue();
	void MinusCollisionValue();
	int GetCollisionValue()
	{
		return CollisionValue;
	}
	//0==상호작용x 1==비밀번호 풀린상태 2==Branch가 떨어진상태
	int GetClockValue()
	{
		return ClockValue;
	}
	void PlusClockValue()
	{
		ClockValue += 1;
	}
	//Note에서 현재의 Picture가 Rain이냐?
	void SetIsRainfalse()
	{
		IsRain = false;
	}
	void SetIsRaintrue()
	{
		IsRain = true;
	}
	bool GetIsRain()
	{
		return IsRain;
	}
	//나무에 물 줬냐 안줬냐
	void SetIsBigTreeTrue()
	{
		IsBigTree = true;
	}
	bool GetIsBigTree()
	{
		return IsBigTree;
	}
	//TrashCan뚜껑 열었냐 안열었냐
	void SetTrashCanOpen()
	{
		IsTrashCanOpen = true;
	}
	bool GetIsTrashCanOpen()
	{
		return IsTrashCanOpen;
	}
	//Note에서 현재의 Picture가 Walnut이냐?
	void SetIsWalNutfalse()
	{
		IsWalNut = false;
	}
	void SetIsWalNuttrue()
	{
		IsWalNut = true;
	}
	bool GetIsWalNut()
	{
		return IsWalNut;
	}
	//다람쥐한테 키 얻었냐?
	void SetIsGetTheKeyTrue()
	{
		IsGetTheKey = true;
	}
	bool GetIsGetTheKey()
	{
		return IsGetTheKey;
	}
	//private18폴더 열어봤냐?
	void Set18OpenTrue()
	{
		Is18FolderOpen = true;
	}
	bool Get18OpenTrue()
	{
		return Is18FolderOpen;
	}
	//지금 level진행상태냐?(Mouse용)
	void SetIsProgressTrue()
	{
		IsProgress = true;
	}
	void SetIsProgressFalse()
	{
		IsProgress = false;
	}
	bool GetIsProgress()
	{
		return IsProgress;
	}
	//ScreenActor Cup얻었냐?
	void SetIsGetTheCupTrue()
	{
		IsGetTheCup = true;
	}
	bool GetIsGetTheCup()
	{
		return IsGetTheCup;
	}
	//Chapter1----------------------------------------------------------------------------------------------------------
	//Board 다 내려왔냐?
	void SetIsBoardDownTrue()
	{
		IsBoardDown = true;
	}
	bool GetIsBoardDown()
	{
		return IsBoardDown;
	}
	//Raquette 만들어졌냐??
	void SetIsCreateRaquetteTrue()
	{
		IsCreateRaquette = true;
	}
	bool GetIsCreateRaquette()
	{
		return IsCreateRaquette;
	}
	//Lope 내려가야하냐?
	void SetLopeDownStartTrue()
	{
		LopeDownStart = true;
	}
	void SetLopeDownStartFalse()
	{
		LopeDownStart = false;
	}
	bool GetLopeDownStart()
	{
		return LopeDownStart;
	}
	//Board 기울어졌냐?
	void SetIsSlantBoardTrue()
	{
		IsSlantBoard = true;
	}
	bool GetIsSlantBoard()
	{
		return IsSlantBoard;
	}
	//Metal 몇번 두들겼냐
	void SetHMCMetalPlus()
	{
		HMCMetal += 1;
	}
	int GetHMCMetal()
	{
		return HMCMetal;
	}
	//Card다 올라왔냐?
	void SetIsSetCardTrue()
	{
		IsSetCard = true;
	}
	bool GetIsSetCard()
	{
		return IsSetCard;
	}
	//Roshambo 내Card 눌렀냐?
	void SetIsSelectCardTrue()
	{
		IsSelectCard = true;
	}
	void SetIsSelectCardFalse()
	{
		IsSelectCard = false;
	}
	bool GetIsSelectCard()
	{
		return IsSelectCard;
	}
	//가위냐?
	void SetIsSissorTrue()
	{
		IsSissor = true;
	}
	void SetIsSissorfalse()
	{
		IsSissor = false;
	}
	bool GetIsSissor()
	{
		return IsSissor;
	}
	//보냐?
	 void SetIsPaperTrue()
	{
		 IsPaper = true;
	}
	void SetIsPaperfalse()
	{
		IsPaper = false;
	}
	bool GetIsPaper()
	{
		return IsPaper;
	}
	//바위냐?
	void SetIsRockTrue()
	{
		IsRock = true;
	}
	void SetIsRockfalse()
	{
		IsRock = false;
	}
	bool GetIsRock()
	{
		return IsRock;
	}
	//가위 집었냐?
	void SetIsPickScissorTrue()
	{
		IsPickScissor = true;
	}
	void SetIsPickScissorFalse()
	{
		IsPickScissor = false;
	}
	bool GetIsPickScissor()
	{
		return IsPickScissor;
	}
	//Lope_weak 잘렸냐??
	void SetIsCutTheLopeTrue()
	{
		IsCutTheLope = true;
	}
	bool GetIsCutTheLope()
	{
		return IsCutTheLope;
	}
	//떨어진 알파벳 죽었냐?
	void SetIsDeathNTrue()
	{
		IsDeathN = true;
	}
	bool GetIsDeathN()
	{
		return IsDeathN;
	}
	//Balloon다 올라왔냐?
	void SetIsBalloonUpTrue()
	{
		IsBalloonUp = true;
	}
	bool GetIsBalloonUp()
	{
		return IsBalloonUp;
	}
	//Speaker눌렀냐?
	void SetIsClickSpeakerTrue()
	{
		IsClickSpeaker = true;
	}
	void SetIsClickSpeakerFalse()
	{
		IsClickSpeaker = false;
	}
	bool GetIsClickSpeaker()
	{
		return IsClickSpeaker;
	}
	//Balloon 터졌냐?
	void SetIsPopBalloonTrue()
	{
		IsPopBalloon = true;
	}
	bool GetIsPopBalloon()
	{
		return IsPopBalloon;
	}
	//카메라 위치(int value)뭐냐?
	void SetCameraMoveValuePlus()
	{
		CameraMoveValue += 1;
	}
	void SetCameraMoveValueMinus()
	{
		CameraMoveValue -= 1;
	}
	int GetCameraMoveValue()
	{
		return CameraMoveValue;
	}
	//카메라 움직일 수 있냐?
	void SetIsCameraMoveCheckTrue()
	{
		IsCameraMoveCheck = true;
	}
	void SetIsCameraMoveCheckFalse()
	{
		IsCameraMoveCheck = false;
	}
	bool GetIsCameraMoveCheck()
	{
		return IsCameraMoveCheck;
	}
	//Vis 돌리고있냐?
	void SetIsTurnVisTrue()
	{
		IsTurnVis = true;
	}
	void SetIsTurnVisFalse()
	{
		IsTurnVis = false;
	}
	bool GetIsTurnVis()
	{
		return IsTurnVis;
	}
	//Cog꽂았냐
	void SetIsCogStickTrue()
	{
		IsCogStick = true;
	}
	bool GetIsCogStick()
	{
		return IsCogStick;
	}
	//Rouge꽂았냐
	void SetIsRougeStickTrue()
	{
		IsRougeStick = true;
	}
	bool GetIsRougeStick()
	{
		return IsRougeStick;
	}
	//CoffrePanel열렸냐
	void SetIsPanelClick()
	{
		IsPanelClick = !IsPanelClick;
	}
	bool GetIsPanelClick()
	{
		return IsPanelClick;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;
private:
	//Mouse
	bool IsProgress = false;

	//Chapter1
	bool IsBoardDown = false;
	bool IsCreateRaquette = false;
	bool LopeDownStart = false;
	bool IsSlantBoard = false;
	int HMCMetal = 0; //How Many Click Metal
	bool IsSetCard = false;
	bool IsSelectCard = false;
	bool IsSissor = false;
	bool IsRock = false;
	bool IsPaper = false;
	bool IsPickScissor = false;
	bool IsCutTheLope = false;
	bool IsDeathN = false;
	bool IsBalloonUp = false;
	bool IsClickSpeaker = false;
	bool IsPopBalloon = false;
	int CameraMoveValue = 0;
	bool IsCameraMoveCheck = true;
	bool IsTurnVis = false;
	bool IsCogStick = false;
	bool IsRougeStick = false;
	bool IsPanelClick = false;

	//Chapter2
	int CollisionValue = 0;
	int NextCollisionValue = 0;
	int ClockValue = 0;
	bool IsRain = false;
	bool IsWalNut = false;
	bool IsBigTree = false;
	bool IsTrashCanOpen = false;
	bool IsGetTheKey = false;
	bool Is18FolderOpen = false;
	bool IsGetTheCup = false;
};

