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
	void SetIsRantrue()
	{
		IsRain = true;
	}
	bool GetIsRain()
	{
		return IsRain;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:
	int CollisionValue = 0;
	int NextCollisionValue = 0;

	int ClockValue = 0;

	bool IsRain = false;
};

