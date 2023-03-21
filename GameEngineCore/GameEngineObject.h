#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <list>
#include <memory>

// ���� :
class GameEngineObject
{
public:
	// constrcuter destructer
	GameEngineObject();
	// �Ҹ��ڿ� virtual���̴� ���� => �ڽļҸ��ڰ� ����� ȣ��ǰ� �ϱ� ���ؼ�
	// ���������Լ� ���� ���� => �ڽĿ��� �������̽��� �����ϱ� ���ؼ�
	// ���������Լ� ���� ���� => �� Ŭ������ ��üȭ �Ҽ� ���� ����� ���ؼ�.
	// �Ҹ��ڸ� ���������Լ��� ����� ����? => �߻�ȭ �Ҹ��Ѱ� ���� ���.
	virtual ~GameEngineObject() = 0;

	// delete Function
	GameEngineObject(const GameEngineObject& _Other) = delete;
	GameEngineObject(GameEngineObject&& _Other) noexcept = delete;
	GameEngineObject& operator=(const GameEngineObject& _Other) = delete;
	GameEngineObject& operator=(GameEngineObject&& _Other) noexcept = delete;

	int GetOrder()
	{
		return Order;
	}

	void SetOrder(int _Order)
	{
		Order = _Order;
	}

	void On()
	{
		IsActive = true;
	}

	void Off()
	{
		IsActive = false;
	}

	void Death()
	{
		IsDeath = true;
	}

	//                 "�巡��"
	// �����Ҵ� 1���� ���̷���.
	void SetName(const std::string_view& _Name)
	{
		Name = _Name;
	}

	void SetParent(GameEngineObject* _Parent)
	{
		Parent = _Parent;
	}

	GameEngineObject* GetParent()
	{
		return Parent;
	}

protected:
	virtual void Start() {}
	virtual void Update(float _DeltaTime) {}
	virtual void Render(float _DeltaTime) {}

private:
	std::string Name = "";
	bool IsActive = true; // ������ ������
	bool IsDeath = false; // �׾��� ��Ҵ�
	int Order = 0;

	GameEngineObject* Parent = nullptr;

	std::list<std::shared_ptr<GameEngineObject>> Child;

	////////////////////////////////////////////////////////////// Transform ���ϱ���

public:
	float4 GetPos()
	{
		return Pos;
	}

private:
	float4 Pos;

};
