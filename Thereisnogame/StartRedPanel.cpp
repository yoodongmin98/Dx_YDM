#include "PrecompileHeader.h"
#include "StartRedPanel.h"

//PlatForm
//Core
//Actor



StartRedPanel::StartRedPanel()
{
}

StartRedPanel::~StartRedPanel()
{
}

void StartRedPanel::Start()
{
	Init(StartRedPanels, "MainMenu_SaveBoxBig.png", { 777,198 }, float4::Zero);
	Sound = Play(Sound, "ErrorAlert.wav", 0.1f);

	Font1 = FontCreate(Font1, 32, "���α׷��� ����ġ ���� ������ ����Ǿ���\n�ϴ�.", float4::Up*70, GetTransform(), 2);
	Font2 = FontCreate(Font2, 32, "��ǻ�͸� ����� ���ּ���.", float4::Down*20, GetTransform(), 2);
}

void StartRedPanel::Update(float _DeltaTime)
{

}

void StartRedPanel::Render(float _Delta)
{

};
