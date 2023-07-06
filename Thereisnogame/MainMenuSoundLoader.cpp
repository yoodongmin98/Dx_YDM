#include "PrecompileHeader.h"
#include "MainMenuLevel.h"

#include <GameEnginePlatform/GameEngineSound.h>


void MainMenuLevel::SoundLoad()
{
	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParentToDirectory("ThereisnogameResource");
		SoundDir.Move("ThereisnogameResource");
		SoundDir.Move("SoundFiles");
		SoundDir.Move("MainMenus");

		GameEngineSound::Load(SoundDir.GetPlusFileName("MainMenu.wav").GetFullPath());
		GameEngineSound::Load(SoundDir.GetPlusFileName("MainMenu_LanguageIn.wav").GetFullPath());
		GameEngineSound::Load(SoundDir.GetPlusFileName("MainMenu_LanguageOut.wav").GetFullPath());
		GameEngineSound::Load(SoundDir.GetPlusFileName("MainMenu_PanelChoiceOut.wav").GetFullPath());
		GameEngineSound::Load(SoundDir.GetPlusFileName("MainMenu_PanelChoiceIn.wav").GetFullPath());
		GameEngineSound::Load(SoundDir.GetPlusFileName("MainMenu_TitleIn.wav").GetFullPath());





		MainBackSound = GameEngineSound::Play("MainMenu.wav");
		MainBackSound.SetVolume(0.1f);
	}
}

void MainMenuLevel::Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName,float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);
}
 
void MainMenuLevel::Pause(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(true);
}