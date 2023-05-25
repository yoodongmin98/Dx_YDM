#include "PrecompileHeader.h"
#include "GameEngineCollision.h"
#include "GameEngineLevel.h"

GameEngineCollision::GameEngineCollision() 
{
}

GameEngineCollision::~GameEngineCollision() 
{
}


void GameEngineCollision::Start() 
{
}

std::shared_ptr<GameEngineCollision> GameEngineCollision::Collision(int _TargetGroup, ColType _ThisColType, ColType _OtherColtype)
{
	if (false == this->IsUpdate())
	{
		return nullptr;
	}

	std::list<std::shared_ptr<GameEngineCollision>>& Group = GetLevel()->Collisions[_TargetGroup];

	if (_ThisColType == ColType::MAX)
	{
		_ThisColType = Type;
	}

	for (std::shared_ptr<GameEngineCollision>& _OtherCol : Group)
	{
		if (false == _OtherCol->IsUpdate())
		{
			continue;
		}

		if (_OtherColtype == ColType::MAX)
		{
			_OtherColtype = _OtherCol->Type;
		}

		if (GetTransform()->Collision({ _OtherCol->GetTransform(),_ThisColType, _OtherColtype }))
		{
			return _OtherCol;
		}
	}

	return nullptr;
}

void GameEngineCollision::SetOrder(int _Order) 
{
	std::shared_ptr<GameEngineCollision> ConThis = DynamicThis<GameEngineCollision>();

	// ������ �׷쿡�� ���� �����
	std::list<std::shared_ptr<GameEngineCollision>>& Group = GetLevel()->Collisions[GetOrder()];
	Group.remove(ConThis);

	GameEngineObjectBase::SetOrder(_Order);

	// ���ο� �׷쿡 ���� �߰��Ѵ�.
	GetLevel()->PushCollision(ConThis);
}

bool GameEngineCollision::CollisionAll(int _TargetGroup, std::vector<std::shared_ptr<GameEngineCollision>>& _Col, ColType _ThisColType, ColType _OtherColtype)
{
	if (false == this->IsUpdate())
	{
		return false;
	}

	_Col.clear();

	std::list<std::shared_ptr<GameEngineCollision>>& Group = GetLevel()->Collisions[_TargetGroup];

	if (0 == Group.size())
	{
		return false;
	}

	if (_ThisColType == ColType::MAX)
	{
		_ThisColType = Type;
	}

	for (std::shared_ptr<GameEngineCollision>& _OtherCol : Group)
	{
		if (false == _OtherCol->IsUpdate())
		{
			continue;
		}

		if (_OtherColtype == ColType::MAX)
		{
			_OtherColtype = _OtherCol->Type;
		}

		if (GetTransform()->Collision({ _OtherCol->GetTransform(),_ThisColType, _OtherColtype }))
		{
			_Col.push_back(_OtherCol);
		}
	}

	return _Col.size() != 0;

}