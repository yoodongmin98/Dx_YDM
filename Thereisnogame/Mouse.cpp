 #include "PrecompileHeader.h"
#include "Mouse.h"
#include "ActorTypeEnum.h"


//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineCollision.h>


//Actor
#include "LevelStateManager.h"
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
	
	MouseIdle = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Mouse);
	MouseIdle->SetScaleToTexture("Idle.png");
	MouseIdle->GetTransform()->SetLocalScale({ 108,108,1.0f });
	MouseIdle->GetTransform()->SetLocalPosition({0,0,0});

	MouseInteractable = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Mouse);
	MouseInteractable->SetScaleToTexture("Interactable.png");
	MouseInteractable->GetTransform()->SetLocalScale({ 108,108,1.0f });
	MouseInteractable->GetTransform()->SetLocalPosition({ 0,0,0 });

	MouseHand = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Mouse);
	MouseHand->SetScaleToTexture("Hand.png");
	MouseHand->GetTransform()->SetLocalScale({ 108,108,1.0f });
	MouseHand->GetTransform()->SetLocalPosition({ 0,0,0 });

	MouseHandtake = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Mouse);
	MouseHandtake->SetScaleToTexture("HandTakeOver.png");
	MouseHandtake->GetTransform()->SetLocalScale({ 108,108,1.0f });
	MouseHandtake->GetTransform()->SetLocalPosition({ 0,0,0 });

	MouseUnavailable = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::Mouse);
	MouseUnavailable->SetScaleToTexture("UnavailableIndicator.png");
	MouseUnavailable->GetTransform()->SetLocalScale({ 85 ,85, 1 });
	MouseUnavailable->GetTransform()->SetLocalPosition({ 0,0,0 });

	Mousesituation.push_back(MouseIdle);
	Mousesituation.push_back(MouseInteractable);
	Mousesituation.push_back(MouseHand);
	Mousesituation.push_back(MouseHandtake);
	Mousesituation.push_back(MouseUnavailable);

	MouseCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Mouse);
	MouseCollision->GetTransform()->SetLocalScale({5,5,1 });


	whatisMouse=ChangeMouse(MouseIdle);
}

void Mouse::Update(float _DeltaTime)
{
	MouseStateCheck();
	InteractableCheck();
	ProgressMouseCollisionCheck();
	MousePositionUpdate(whatisMouse, MouseCollision);
}

void Mouse::Render(float _Delta)
{

};

//------------------------------------------------------------------------------------------------------------------------


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

void Mouse::InteractableCheck()
{
	if (GameEngineInput::IsPress("LeftMouse"))
	{
		Interactable = false;
	}
	else
	{
		Interactable = true;
	}
}

void Mouse::MouseStateCheck()
{
	if (true==IsScreenActors())
	{
		whatisMouse = ChangeMouse(MouseHand);
		if (GameEngineInput::IsPress("LeftMouse"))
		{
			whatisMouse = ChangeMouse(MouseHandtake);
		}
	}
	else if (true==IsBackActors())
	{
		whatisMouse = ChangeMouse(MouseInteractable);
	}
	else if (true == LevelStateManager::MG->GetIsProgress())
	{
		whatisMouse = ChangeMouse(MouseUnavailable);
	}
	else
	{
		whatisMouse = ChangeMouse(MouseIdle);
	}
}

void Mouse::ProgressMouseCollisionCheck()
{
	if (true == LevelStateManager::MG->GetIsProgress())
	{
		MouseCollision->Off();
	}
	else
	{
		MouseCollision->On();
	}
}

bool Mouse::IsScreenActors()
{
	if (MouseCollision->Collision(ActorTypeEnum::ScreenActor, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::Cup_Full, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::Nut_Close, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::Nut_Open, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::Decapsuleur, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::Excla, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Mouse::IsBackActors()
{
	if (MouseCollision->Collision(ActorTypeEnum::BackActor, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::ZipWip, ColType::AABBBOX2D, ColType::AABBBOX2D)
		|| MouseCollision->Collision(ActorTypeEnum::LockFolder, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		return true;
	}
	else
	{
		return false;
	}
}

