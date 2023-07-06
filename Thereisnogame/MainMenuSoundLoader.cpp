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









		FlagIn = GameEngineSound::Play("MainMenu_LanguageIn.wav");
		FlagIn.SetVolume(0.1f);

		MainBackSound = GameEngineSound::Play("MainMenu.wav");
		MainBackSound.SetVolume(0.1f);
	}
}

void MainMenuLevel::SoundPlay(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName,float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
}
 
void MainMenuLevel::SoundPause(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(true);
}