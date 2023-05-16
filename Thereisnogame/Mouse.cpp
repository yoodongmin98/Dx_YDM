#include "PrecompileHeader.h"
#include "Mouse.h"
#include "ActorTypeEnum.h"


//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCollision.h>

Mouse* Mouse::MainMouse;

Mouse::Mouse()
{
	MainMouse = this;
}

Mouse::~Mouse()
{
}


void Mouse::Start()
{
	GameEngineInput::MouseCursorOff();
	
	MouseIdle = Init(MouseIdle, "Idle.png", {108,108},float4::Zero);
	MouseInteractable = Init(MouseInteractable, "Interactable.png", { 108,108 }, float4::Zero);
	MouseHand = Init(MouseHand, "Hand.png", { 108,108 }, float4::Zero);
	MouseHandtake = Init(MouseHandtake, "HandTakeOver.png", { 108,108 }, float4::Zero);
	MouseUnavailable = Init(MouseUnavailable, "UnavailableIndicator.png", { 55,55 }, float4::Zero);

	Mousesituation.push_back(MouseIdle);
	Mousesituation.push_back(MouseInteractable);
	Mousesituation.push_back(MouseHand);
	Mousesituation.push_back(MouseHandtake);
	Mousesituation.push_back(MouseUnavailable);



	MouseCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Mouse);
	MouseCollision->GetTransform()->SetLocalScale({ 108,108 });


	whatisMouse=ChangeMouse(MouseIdle);

}

void Mouse::Update(float _DeltaTime)
{
	MousePositionUpdate(whatisMouse, MouseCollision);
	InteractableCheck();
	//float4 asdq = MouseCollision->GetTransform()->GetLocalPosition();
}

void Mouse::Render(float _Delta)
{

};




std::shared_ptr<GameEngineSpriteRenderer> Mouse::ChangeMouse(std::shared_ptr<class GameEngineSpriteRenderer> _MouseOnRender)
{
	if (nullptr == _MouseOnRender)
	{
		MsgAssert("nullptr상태인 Mouse상태를 On하려고 했습니다.");
	}
	for (size_t i = 0; i<=4; ++i)
	{
		Mousesituation[i]->Off();
		if (Mousesituation[i] == _MouseOnRender)
		{
			Mousesituation[i]->On();
		}
	}
	return _MouseOnRender;
}

void Mouse::MousePositionUpdate(std::shared_ptr<GameEngineSpriteRenderer> _Mouse, std::shared_ptr<GameEngineCollision> _MouseCollision)
{
	MousePos = { GameEngineInput::GetMousePosition().x - GameEngineWindow::GetScreenSize().half().x ,
				-GameEngineInput::GetMousePosition().y + GameEngineWindow::GetScreenSize().half().y };

	_Mouse->GetTransform()->SetLocalPosition(MousePos);
	_MouseCollision->GetTransform()->SetLocalPosition(MousePos);
}

bool Mouse::InteractableCheck()
{
	if (GameEngineInput::IsPress("LeftMouse"))
	{
		return false;
	}
	else
	{
		return true;
	}
}

