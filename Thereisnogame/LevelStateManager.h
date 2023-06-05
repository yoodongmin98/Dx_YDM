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

