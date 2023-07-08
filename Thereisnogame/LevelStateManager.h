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
	//���� ������ֳ�?
	void PlusCollisionValue();
	void MinusCollisionValue();
	int GetCollisionValue()
	{
		return CollisionValue;
	}
	//0==��ȣ�ۿ�x 1==��й�ȣ Ǯ������ 2==Branch�� ����������
	int GetClockValue()
	{
		return ClockValue;
	}
	void PlusClockValue()
	{
		ClockValue += 1;
	}
	//Note���� ������ Picture�� Rain�̳�?
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
	//������ �� ��� �����
	void SetIsBigTreeTrue()
	{
		IsBigTree = true;
	}
	bool GetIsBigTree()
	{
		return IsBigTree;
	}
	//TrashCan�Ѳ� ������ �ȿ�����
	void SetTrashCanOpen()
	{
		IsTrashCanOpen = true;
	}
	bool GetIsTrashCanOpen()
	{
		return IsTrashCanOpen;
	}
	//Note���� ������ Picture�� Walnut�̳�?
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
	//�ٶ������� Ű �����?
	void SetIsGetTheKeyTrue()
	{
		IsGetTheKey = true;
	}
	bool GetIsGetTheKey()
	{
		return IsGetTheKey;
	}
	//private18���� ����ó�?
	void Set18OpenTrue()
	{
		Is18FolderOpen = true;
	}
	bool Get18OpenTrue()
	{
		return Is18FolderOpen;
	}
	//���� level������³�?(Mouse��)
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
	//ScreenActor Cup�����?
	void SetIsGetTheCupTrue()
	{
		IsGetTheCup = true;
	}
	bool GetIsGetTheCup()
	{
		return IsGetTheCup;
	}
	//Chapter1----------------------------------------------------------------------------------------------------------
	//Board �� �����Գ�?
	void SetIsBoardDownTrue()
	{
		IsBoardDown = true;
	}
	bool GetIsBoardDown()
	{
		return IsBoardDown;
	}
	//Raquette ���������??
	void SetIsCreateRaquetteTrue()
	{
		IsCreateRaquette = true;
	}
	bool GetIsCreateRaquette()
	{
		return IsCreateRaquette;
	}
	//Lope ���������ϳ�?
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
	//Board ��������?
	void SetIsSlantBoardTrue()
	{
		IsSlantBoard = true;
	}
	bool GetIsSlantBoard()
	{
		return IsSlantBoard;
	}
	//Metal ��� �ε���
	void SetHMCMetalPlus()
	{
		HMCMetal += 1;
	}
	int GetHMCMetal()
	{
		return HMCMetal;
	}
	//Card�� �ö�Գ�?
	void SetIsSetCardTrue()
	{
		IsSetCard = true;
	}
	bool GetIsSetCard()
	{
		return IsSetCard;
	}
	//Roshambo ��Card ������?
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
	//������?
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
	//����?
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
	//������?
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
	//���� ������?
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
	//Lope_weak �߷ȳ�??
	void SetIsCutTheLopeTrue()
	{
		IsCutTheLope = true;
	}
	bool GetIsCutTheLope()
	{
		return IsCutTheLope;
	}
	//������ ���ĺ� �׾���?
	void SetIsDeathNTrue()
	{
		IsDeathN = true;
	}
	bool GetIsDeathN()
	{
		return IsDeathN;
	}
	//Balloon�� �ö�Գ�?
	void SetIsBalloonUpTrue()
	{
		IsBalloonUp = true;
	}
	bool GetIsBalloonUp()
	{
		return IsBalloonUp;
	}
	//Speaker������?
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
	//Balloon ������?
	void SetIsPopBalloonTrue()
	{
		IsPopBalloon = true;
	}
	bool GetIsPopBalloon()
	{
		return IsPopBalloon;
	}
	//ī�޶� ��ġ(int value)����?
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
	//ī�޶� ������ �� �ֳ�?
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
	//Vis �������ֳ�?
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
	//Cog�Ⱦҳ�
	void SetIsCogStickTrue()
	{
		IsCogStick = true;
	}
	bool GetIsCogStick()
	{
		return IsCogStick;
	}
	//Rouge�Ⱦҳ�
	void SetIsRougeStickTrue()
	{
		IsRougeStick = true;
	}
	bool GetIsRougeStick()
	{
		return IsRougeStick;
	}
	//CoffrePanel���ȳ�
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

