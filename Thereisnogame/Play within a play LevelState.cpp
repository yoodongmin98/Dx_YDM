#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//Platform
//Core

//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"

void PlaywithinaplayLevel::ChangeState(Chap1LevelState _State)
{
	Chap1LevelState NextState = _State;
	Chap1LevelState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Chap1LevelState::ClickCordon:
		ClickCordonStart();
		break;
	case Chap1LevelState::Test:
		TestStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case Chap1LevelState::ClickCordon:
		ClickCordonEnd();
		break;
	case Chap1LevelState::Test:
		TestEnd();
		break;
	default:
		break;
	}
}

void PlaywithinaplayLevel::UpdateState(float _DeltaTime)
{
	switch (StateValue)
	{
	case Chap1LevelState::ClickCordon:
		ClickCordonUpdate(_DeltaTime);
		break;
	case Chap1LevelState::Test:
		TestUpdate(_DeltaTime);
		break;
	default:
		break;
	}
}

void PlaywithinaplayLevel::ClickCordonStart()
{
	AlphaCirclePtr = CreateActor<AlphaCircle>();
}
void PlaywithinaplayLevel::ClickCordonUpdate(float _DeltaTime)
{
	std::function<void()> Functions;
	Functions = std::bind(&BackCurtain::CurtainOpen, BackCurtainPtr.get());
	Functions();
}
void PlaywithinaplayLevel::ClickCordonEnd()
{

}

void PlaywithinaplayLevel::TestStart()
{

}
void PlaywithinaplayLevel::TestUpdate(float _DeltaTime)
{

}
void PlaywithinaplayLevel::TestEnd()
{

}