#include "PrecompileHeader.h"
#include "GameEngineTransform.h"
#include "GameEngineObject.h"

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
		float4x4 ParentWorldMatrix = Parent->GetWorldMatrixRef();
		float4 PScale, PRotation, PPosition;
		ParentWorldMatrix.Decompose(PScale, PRotation, PPosition);


		if (true == AbsoluteScale)
		{
			// �θ��� ����� �������� 1
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

	WorldDecompose();

	LocalDecompose();
		// ParentWorldMatrix.Decompose(PScale, PRoatation, PPosition);

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

}

void GameEngineTransform::SetParent(GameEngineTransform* _Parent)
{
	if (IsDebug())
	{
		int a = 0;
	}

	Parent = _Parent;

	// ���� �������� �޶����°� ����.

	// �� WorldMatrix;
	// �θ��� WorldMatrix;

	
	//TransformData ParentData = Parent->TransData;
	//TransformData ChildData = TransData;
	//ParentData.WorldMatrix;
	//ChildData.WorldMatrix;
	//float4x4 NewWorld = ChildData.WorldMatrix * ParentData.WorldMatrix.InverseReturn();

	TransData.LocalWorldMatrix = TransData.WorldMatrix * Parent->TransData.WorldMatrix.InverseReturn();
	LocalDecompose();

	TransData.Position = TransData.LocalPosition;
	TransData.Rotation = TransData.LocalRotation;
	TransData.Scale = TransData.LocalScale;

	TransformUpdate();

	AbsoluteReset();

	// ���� ���������� ���� ���� �̷��͵��� �־��µ�.
	// ���� ���ο� �θ� �����
	// ���� �̹� �ٸ� �θ� �ִٸ�

	Parent->Child.push_back(this);
}




void GameEngineTransform::CalChild()
{
	for (GameEngineTransform* ChildTrans : Child)
	{
		if (false == ChildTrans->AbsoluteScale)
		{
			ChildTrans->SetLocalScale(ChildTrans->GetLocalScale());
		}

		if (false == ChildTrans->AbsoluteRotation)
		{
			ChildTrans->SetLocalRotation(ChildTrans->GetLocalRotation());
		}

		if (false == ChildTrans->AbsolutePosition)
		{
			ChildTrans->SetLocalPosition(ChildTrans->GetLocalPosition());
		}
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

void GameEngineTransform::AbsoluteReset()
{
	AbsoluteScale = false;
	AbsoluteRotation = false;
	AbsolutePosition = false;
}