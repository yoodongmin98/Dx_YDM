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

	/*Font1=FontCreate(Font1,25)*/
}

void StartRedPanel::Update(float _DeltaTime)
{

}

void StartRedPanel::Render(float _Delta)
{

};
