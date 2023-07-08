#include "PrecompileHeader.h"
#include "Play within a play Level.h"
#include <GameEnginePlatform/GameEngineSound.h>


void PlaywithinaplayLevel::SoundLoad()
{
	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParentToDirectory("ThereisnogameResource");
		SoundDir.Move("ThereisnogameResource");
		SoundDir.Move("SoundFiles");
		SoundDir.Move("Chapter1");

		std::vector<GameEngineFile> File = SoundDir.GetAllFile({ ".wav", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineSound::Load(File[i].GetFullPath());
		}
		
	}
}

void PlaywithinaplayLevel::Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);
}

void PlaywithinaplayLevel::Pause(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(true);
}