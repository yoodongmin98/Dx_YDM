#pragma once
#include <GameEngineCore/GameEngineActor.h>


class ColManager : public GameEngineActor
{
public:
	static ColManager* MG;
	// constrcuter destructer
	ColManager();
	~ColManager();

	// delete Function
	ColManager(const ColManager& _Other) = delete;
	ColManager(ColManager&& _Other) noexcept = delete;
	ColManager& operator=(const ColManager& _Other) = delete;
	ColManager& operator=(ColManager&& _Other) noexcept = delete;
	//값이 1 증가할때마다 폴더가 하나씩 열렸다는 뜻
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
	//Note에서 현재의 Picture가 Rain인지 체크
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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:
	int CollisionValue = 0;
	int NextCollisionValue = 0;

	int ClockValue = 0;

	bool IsRain = false;
	bool IsBigTree = false;
	bool IsTrashCanOpen = false;
};

