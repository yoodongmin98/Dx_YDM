#include "PrecompileHeader.h"
#include "TitleLevel.h"
#include <GameEngineBase\GameEngineDebug.h>

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Start() 
{
	// TimeEvent.AddEvent(5.0f, std::bind(&TitleLevel::TestMsg, this), true);

	//std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> Test0 =
	//	[](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
	//{
	//	MsgTextBox("����");
	//};

	//// ���� ����
	//// �̸��� ���� �Լ��� ������ ����.
	//std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> Test = 
	//	[=](GameEngineTimeEvent::TimeEvent& _Event, GameEngineTimeEvent* _Manager)
	//{
	//	MsgTextBox("����");

	//	_Manager->AddEvent(3.0f, Test0, false);
	//};

	// TimeEvent.AddEvent(3.0f, Test, false);
}

