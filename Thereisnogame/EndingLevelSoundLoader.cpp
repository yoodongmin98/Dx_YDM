#include "PrecompileHeader.h"
#include "EndingLevel.h"
#include <GameEnginePlatform/GameEngineSound.h>


void EndingLevel::SoundLoad()
{
	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParentToDirectory("ThereisnogameResource");
		SoundDir.Move("ThereisnogameResource");
		SoundDir.Move("SoundFiles");
		SoundDir.Move("Chapter3(Ending)");

		std::vector<GameEngineFile> File = SoundDir.GetAllFile({ ".wav", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineSound::Load(File[i].GetFullPath());
		}

	}
}

void EndingLevel::StopBGM()
{
	MainBGM.Stop();
}

GameEngineSoundPlayer EndingLevel::ChangeBGM(const std::string_view& _MusicName)
{
	MainBGM.Stop();
	MainBGM = GameEngineSound::Play(_MusicName);
	MainBGM.SetVolume(0.1f);
	MainBGM.SetLoop(-1);

	return MainBGM;
}

void EndingLevel::BGMPauseOn()
{
	MainBGM.SetPause(true);
}
void EndingLevel::BGMPauseOff()
{
	MainBGM.SetPause(false);
}

GameEngineSoundPlayer EndingLevel::Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);

	return _ControlSoundName;
}