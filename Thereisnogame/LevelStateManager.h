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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:
	//Mouse
	bool IsProgress = false;

	//Chapter1
	bool IsBoardDown = false;
	bool IsCreateRaquette = false;
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

