#include "PrecompileHeader.h"
#include "GameEngineTransform.h"
#include "GameEngineObject.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"

std::function<bool(GameEngineTransform*, GameEngineTransform*)> GameEngineTransform::ArrColFunction[static_cast<int>(ColType::MAX)][static_cast<int>(ColType::MAX)];

class InitColFunction 
{
public:
	InitColFunction() 
	{
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::SPHERE3D)][static_cast<int>(ColType::SPHERE3D)] = &GameEngineTransform::SphereToSpehre;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::SPHERE3D)][static_cast<int>(ColType::AABBBOX3D)] = &GameEngineTransform::SphereToAABB;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::SPHERE3D)][static_cast<int>(ColType::OBBBOX3D)] = &GameEngineTransform::SphereToOBB;

		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::AABBBOX3D)][static_cast<int>(ColType::SPHERE3D)] = &GameEngineTransform::AABBToSpehre;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::AABBBOX3D)][static_cast<int>(ColType::AABBBOX3D)] = &GameEngineTransform::AABBToAABB;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::AABBBOX3D)][static_cast<int>(ColType::OBBBOX3D)] = &GameEngineTransform::AABBToOBB;

		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::OBBBOX3D)][static_cast<int>(ColType::SPHERE3D)] = &GameEngineTransform::OBBToSpehre;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::OBBBOX3D)][static_cast<int>(ColType::AABBBOX3D)] = &GameEngineTransform::OBBToAABB;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::OBBBOX3D)][static_cast<int>(ColType::OBBBOX3D)] = &GameEngineTransform::OBBToOBB;

		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::SPHERE2D)][static_cast<int>(ColType::SPHERE2D)] = &GameEngineTransform::Sphere2DToSpehre2D;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::SPHERE2D)][static_cast<int>(ColType::AABBBOX2D)] = &GameEngineTransform::Sphere2DToAABB2D;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::SPHERE2D)][static_cast<int>(ColType::OBBBOX2D)] = &GameEngineTransform::Sphere2DToOBB2D;

		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::AABBBOX2D)][static_cast<int>(ColType::SPHERE2D)] = &GameEngineTransform::AABB2DToSpehre2D;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::AABBBOX2D)][static_cast<int>(ColType::AABBBOX2D)] = &GameEngineTransform::AABB2DToAABB2D;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::AABBBOX2D)][static_cast<int>(ColType::OBBBOX2D)] = &GameEngineTransform::AABB2DToOBB2D;

		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::OBBBOX2D)][static_cast<int>(ColType::SPHERE2D)] = &GameEngineTransform::OBB2DToSpehre2D;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::OBBBOX2D)][static_cast<int>(ColType::AABBBOX2D)] = &GameEngineTransform::OBB2DToAABB2D;
		GameEngineTransform::ArrColFunction[static_cast<int>(ColType::OBBBOX2D)][static_cast<int>(ColType::OBBBOX2D)] = &GameEngineTransform::OBB2DToOBB2D;

	}
};

InitColFunction InitFunction;

bool GameEngineTransform::SphereToSpehre(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.SPHERE.Intersects(_Right->ColData.SPHERE);
}

bool GameEngineTransform::SphereToAABB(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.SPHERE.Intersects(_Right->ColData.AABB);
}

bool GameEngineTransform::SphereToOBB(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.SPHERE.Intersects(_Right->ColData.OBB);
}

bool GameEngineTransform::AABBToSpehre(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.AABB.Intersects(_Right->ColData.SPHERE);
}

bool GameEngineTransform::AABBToAABB(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.AABB.Intersects(_Right->ColData.AABB);
}

bool GameEngineTransform::AABBToOBB(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.AABB.Intersects(_Right->ColData.OBB);
}

bool GameEngineTransform::OBBToSpehre(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.OBB.Intersects(_Right->ColData.SPHERE);
}

bool GameEngineTransform::OBBToAABB(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.OBB.Intersects(_Right->ColData.AABB);
}

bool GameEngineTransform::OBBToOBB(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	return _Left->ColData.OBB.Intersects(_Right->ColData.OBB);
}



bool GameEngineTransform::Sphere2DToSpehre2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.SPHERE.Intersects(RightData.SPHERE);
}

bool GameEngineTransform::Sphere2DToAABB2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.SPHERE.Intersects(RightData.AABB);
}

bool GameEngineTransform::Sphere2DToOBB2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.SPHERE.Intersects(RightData.OBB);
}

bool GameEngineTransform::AABB2DToSpehre2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.AABB.Intersects(RightData.SPHERE);
}

bool GameEngineTransform::AABB2DToAABB2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.AABB.Intersects(RightData.AABB);
}

bool GameEngineTransform::AABB2DToOBB2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.AABB.Intersects(RightData.OBB);
}

bool GameEngineTransform::OBB2DToSpehre2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.OBB.Intersects(RightData.SPHERE);
}

bool GameEngineTransform::OBB2DToAABB2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.OBB.Intersects(RightData.AABB);
}

bool GameEngineTransform::OBB2DToOBB2D(GameEngineTransform* _Left, GameEngineTransform* _Right)
{
	CollisionData LeftData = _Left->ColData;
	LeftData.OBB.Center.z = 0.0f;
	CollisionData RightData = _Right->ColData;
	RightData.OBB.Center.z = 0.0f;

	return LeftData.OBB.Intersects(RightData.OBB);
}



GameEngineTransform::GameEngineTransform()
{
	TransformUpdate();
}

GameEngineTransform::~GameEngineTransform()
{
}


void GameEngineTransform::TransformUpdate()
{
	TransData.ScaleMatrix.Scale(TransData.Scale);

	TransData.Rotation.w = 0.0f;
	TransData.Quaternion = TransData.Rotation.EulerDegToQuaternion();
	TransData.RotationMatrix = TransData.Quaternion.QuaternionToRotationMatrix();
	TransData.PositionMatrix.Pos(TransData.Position);

	TransData.LocalWorldMatrix = TransData.ScaleMatrix * TransData.RotationMatrix * TransData.PositionMatrix;


	if (nullptr == Parent)
	{
		TransData.WorldMatrix = TransData.LocalWorldMatrix;
	}
	else // ����
	{
		WorldCalculation();
	}

	WorldDecompose();
	LocalDecompose();
		// ParentWorldMatrix.Decompose(PScale, PRoatation, PPosition);

}

void GameEngineTransform::WorldCalculation()
{
	float4x4 ParentWorldMatrix = Parent->GetWorldMatrixRef();
	float4 PScale, PRotation, PPosition;
	ParentWorldMatrix.Decompose(PScale, PRotation, PPosition);


	if (true == AbsoluteScale)
	{
		PScale = float4::One;
	}
	if (true == AbsoluteRotation)
	{
		// �θ��� ȸ�� 
		PRotation = float4::Zero;
		PRotation.EulerDegToQuaternion();
	}
	if (true == AbsolutePosition)
	{
		PPosition = float4::Zero;
	}

	float4x4 MatScale, MatRot, MatPos;

	//scale
	MatScale.Scale(PScale);

	//rot
	MatRot = PRotation.QuaternionToRotationMatrix();

	//pos
	MatPos.Pos(PPosition);

	TransData.WorldMatrix = TransData.LocalWorldMatrix * (MatScale * MatRot * MatPos);
}

void GameEngineTransform::LocalDecompose() 
{
	TransData.LocalWorldMatrix.Decompose(TransData.LocalScale, TransData.LocalQuaternion, TransData.LocalPosition);
	TransData.LocalRotation = TransData.LocalQuaternion.QuaternionToEulerDeg();

}
void GameEngineTransform::WorldDecompose() 
{
	TransData.WorldMatrix.Decompose(TransData.WorldScale, TransData.WorldQuaternion, TransData.WorldPosition);
	TransData.WorldRotation = TransData.WorldQuaternion.QuaternionToEulerDeg();

	ColData.OBB.Center = TransData.WorldPosition.DirectFloat3;
	ColData.OBB.Extents = (TransData.WorldScale * 0.5f).DirectFloat3;
	ColData.OBB.Orientation = TransData.WorldQuaternion.DirectFloat4;
}

void GameEngineTransform::SetParent(GameEngineTransform* _Parent)
{
	if (IsDebug())
	{
		int a = 0;
	}

	if (nullptr == _Parent && nullptr == Master)
	{
		if (nullptr == dynamic_cast<GameEngineActor*>(Master))
		{
			MsgAssert("���͸��� ��Ʈ ����Ʈ�� �߰��ɼ� �ֽ��ϴ�.");
			return;
		}
	}

	if (nullptr == Parent && nullptr == _Parent)
	{
		return;
	}

	// ���� ���� ������ �θ� ������ �ִٸ�
	if (nullptr != Parent)
	{
		Parent->Child.remove(this);
		GameEngineObject* ParentMaster = Parent->Master;

		if (nullptr == ParentMaster)
		{
			MsgAssert("�����Ҽ� ���� ��Ȳ�Դϴ� Master�� nullptr�Դϴ�");
			return;
		}

		std::shared_ptr<GameEngineObject> MasterPtr = Master->shared_from_this();
		ParentMaster->Childs.remove(MasterPtr);
		Parent = nullptr;

	}

	Parent = _Parent;

	if (nullptr != Parent)
	{
		TransData.LocalWorldMatrix = TransData.WorldMatrix * Parent->TransData.WorldMatrix.InverseReturn();

		LocalDecompose();

		TransData.Position = TransData.LocalPosition;
		TransData.Rotation = TransData.LocalRotation;
		TransData.Scale = TransData.LocalScale;

		TransformUpdate();

		AbsoluteReset();

		GameEngineLevel* Level = Master->GetLevel();

		std::shared_ptr<GameEngineObject> MasterPtr = Master->shared_from_this();

		if (nullptr != dynamic_cast<GameEngineActor*>(Master))
		{
			Level->Actors[MasterPtr->GetOrder()].remove(std::dynamic_pointer_cast<GameEngineActor>(MasterPtr));
		}

		// ���� ���������� ���� ���� �̷��͵��� �־��µ�.
		// ���� ���ο� �θ� �����
		// ���� �̹� �ٸ� �θ� �ִٸ�

		Parent->Child.push_back(this);
		Parent->Master->Childs.push_back(Master->shared_from_this());
	}
	else 
	{
		WorldDecompose();

		TransData.Position = TransData.WorldPosition;
		TransData.Rotation = TransData.WorldRotation;
		TransData.Scale = TransData.WorldScale;
		TransformUpdate();
		AbsoluteReset();

		// ������ ����־�� �Ѵ�.

		GameEngineLevel* Level = Master->GetLevel();

		std::shared_ptr<GameEngineObject> MasterPtr = Master->shared_from_this();

		if (nullptr != dynamic_cast<GameEngineActor*>(Master))
		{
			Level->Actors[MasterPtr->GetOrder()].push_back(std::dynamic_pointer_cast<GameEngineActor>(MasterPtr));
		}
		else
		{
			MsgAssert("���͸��� ������ ��Ʈ ������Ʈ�� ������ �� �ֽ��ϴ�.");
		}

	}
}




void GameEngineTransform::CalChild()
{
	for (GameEngineTransform* ChildTrans : Child)
	{
		ChildTrans->WorldCalculation();
		ChildTrans->WorldDecompose();
		ChildTrans->CalChild();
	}
}



float4 GameEngineTransform::GetLocalPosition()
{
	return TransData.LocalPosition;
}

float4 GameEngineTransform::GetLocalScale()
{
	return TransData.LocalScale;
}

float4 GameEngineTransform::GetLocalRotation()
{
	return TransData.LocalRotation;
}

float4 GameEngineTransform::GetLocalQuaternion()
{
	return TransData.LocalQuaternion;
}

float4 GameEngineTransform::GetWorldPosition()
{
	return TransData.WorldPosition;
}

float4 GameEngineTransform::GetWorldScale()
{
	return TransData.WorldScale;
}

float4 GameEngineTransform::GetWorldRotation()
{
	return TransData.WorldRotation;
}

float4 GameEngineTransform::GetWorldQuaternion()
{
	return TransData.WorldQuaternion;
}

void GameEngineTransform::AbsoluteReset()
{
	AbsoluteScale = false;
	AbsoluteRotation = false;
	AbsolutePosition = false;
}

void GameEngineTransform::SetMaster(GameEngineObject* _Master)
{
	Master = _Master;
}

void GameEngineTransform::AllAccTime(float _DeltaTime)
{
	if (nullptr == Master)
	{
		return;
	}

	if (false == Master->IsUpdate())
	{
		return;
	}

	Master->AccLiveTime(_DeltaTime);

	for (GameEngineTransform* Trans : Child)
	{
		Trans->AllAccTime(_DeltaTime);
	}
}

void GameEngineTransform::AllUpdate(float _DeltaTime) 
{

	if (nullptr == Master)
	{
		return;
	}

	if (false == Master->IsUpdate())
	{
		return;
	}

	Master->Update(_DeltaTime);

	for (GameEngineTransform* Trans : Child)
	{
		Trans->AllUpdate(_DeltaTime);
	}
}


void GameEngineTransform::AllRender(float _DeltaTime) 
{
	if (nullptr == Master)
	{
		return;
	}

	if (false == Master->IsUpdate())
	{
		return;
	}

	Master->Render(_DeltaTime);

	for (GameEngineTransform* Trans : Child)
	{
		Trans->AllRender(_DeltaTime);
	}
}

void GameEngineTransform::AllRelease()
{
	if (nullptr == Master)
	{
		return;
	}

	if (false == Master->IsUpdate())
	{
		return;
	}

	Master->Release();

	for (GameEngineTransform* Trans : Child)
	{
		Trans->AllRelease();
	}
}

void GameEngineTransform::ChildRelease()
{
	std::list<GameEngineTransform*>::iterator ReleaseStartIter = Child.begin();
	std::list<GameEngineTransform*>::iterator ReleaseEndIter = Child.end();

	for (; ReleaseStartIter != ReleaseEndIter; )
	{
		GameEngineTransform* Trans = *ReleaseStartIter;

		if (nullptr == Trans->Master)
		{
			MsgAssert("�� �߸��� ���󿡸��� �θ���.");
		}

		if (false == Trans->Master->IsDeath())
		{
			++ReleaseStartIter;
			continue;
		}

		ReleaseStartIter = Child.erase(ReleaseStartIter);
	}
}


bool GameEngineTransform::Collision(const CollisionParameter& Data)
{
	if (nullptr == Data._OtherTrans)
	{
		MsgAssert("nullptr�� Ʈ���� ������ �浹�� �Ҽ��� �����ϴ�.");
	}

	return ArrColFunction[static_cast<int>(Data.ThisType)][static_cast<int>(Data.OtherType)](this, Data._OtherTrans);
}