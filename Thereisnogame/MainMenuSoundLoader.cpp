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

		std::vector<GameEngineFile> File = SoundDir.GetAllFile({ ".wav", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineSound::Load(File[i].GetFullPath());
		}
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