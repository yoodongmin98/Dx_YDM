#include "PrecompileHeader.h"
#include "LetterBase.h"
//Base
#include <GameEngineBase/GameEngineString.h>
//PlatForm
//Core
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineActor.h>


LetterBase::LetterBase()
{

}

LetterBase::~LetterBase()
{
}

void LetterBase::Start()
{

}
void LetterBase::Update(float _DeltaTime)
{
	
}


void LetterBase::LetterRepeat(float _MoveValue,float _DeltaTime)
{
	//if (true == DownCheck)
	{
		ReverseTime += _DeltaTime;
		if (ReverseTime < 1.0f)
		{
			GetTransform()->AddLocalPosition({ _MoveValue,0,0 });
		}
		if (ReverseTime > 1.0f)
		{
			GetTransform()->AddLocalPosition({ -_MoveValue,0,0 });
			if (ReverseTime > 2.0f)
			{
				ReverseTime = 0.0f;
			}
		}
	}
}

void LetterBase::Init(std::shared_ptr<GameEngineSpriteRenderer> _Render, const std::string_view& _ImageName,float4 _Scale, float4 _Position)
{
	
	_Render = CreateComponent<GameEngineSpriteRenderer>();
	
	
	_Render->SetTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);
}

//void LetterBase::LetterDown(float _EndYvalue,float _DeltaTime)
//{
//	LetterDownTime += _DeltaTime;
//	SetPos(float4::LerpClamp(GetPos(), {0,_EndYvalue }, _DeltaTime));
//	if (LetterDownTime > 1.0f)
//	{
//		DownCheck = true;
//	}
//}
