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
	//���� 1 �����Ҷ����� ������ �ϳ��� ���ȴٴ� ��
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
	//Note���� ������ Picture�� Rain���� üũ
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

