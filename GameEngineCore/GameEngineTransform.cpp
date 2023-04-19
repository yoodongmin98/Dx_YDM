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
	TransData.LocalScaleMatrix.Scale(TransData.LocalScale);

	TransData.LocalRotation.w = 0.0f;
	TransData.LocalQuaternion = TransData.LocalRotation.EulerDegToQuaternion();
	TransData.LocalRotationMatrix = TransData.LocalQuaternion.QuaternionToRotationMatrix();
	TransData.LocalPositionMatrix.Pos(TransData.LocalPosition);
	TransData.LocalWorldMatrix = TransData.LocalScaleMatrix * TransData.LocalRotationMatrix * TransData.LocalPositionMatrix;

	if (nullptr == Parent)
	{
		TransData.WorldMatrix = TransData.LocalWorldMatrix;
	}
	else 
	{
		TransData.WorldMatrix = TransData.LocalWorldMatrix * Parent->GetWorldMatrixRef();
	}
}

void GameEngineTransform::SetParent(GameEngineTransform* _Parent)
{
	Parent = _Parent;

	// ���� �̹� �ٸ� �θ� �ִٸ�

	Parent->Child.push_back(this);

	TransformUpdate();
}


