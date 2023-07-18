#include "PrecompileHeader.h"
#include "Fake Program Level.h"
#include <GameEnginePlatform/GameEngineSound.h>


void FakeProgramLevel::SoundLoad()
{
	{
		GameEngineDirectory SoundDir;
		SoundDir.MoveParentToDirectory("ThereisnogameResource");
		SoundDir.Move("ThereisnogameResource");
		SoundDir.Move("SoundFiles");
		SoundDir.Move("Chapter2");

		std::vector<GameEngineFile> File = SoundDir.GetAllFile({ ".wav", });

		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineSound::Load(File[i].GetFullPath());
		}

	}
}

void FakeProgramLevel::ReSetBGM()
{
	MainBGM = GameEngineSound::Play("Chap02_ElevatorMusic.wav");
	MainBGM.SetVolume(0.1f);
	MainBGM.SetLoop(-1);
}

void FakeProgramLevel::StopBGM()
{
	MainBGM.Stop();
}

GameEngineSoundPlayer FakeProgramLevel::ChangeBGM(const std::string_view& _MusicName)
{
	MainBGM.Stop();
	MainBGM= GameEngineSound::Play(_MusicName);
	MainBGM.SetVolume(0.1f);
	MainBGM.SetLoop(-1);

	return MainBGM;
}

void FakeProgramLevel::BGMPauseOn()
{
	MainBGM.SetPause(true);
}
void FakeProgramLevel::BGMPauseOff()
{
	MainBGM.SetPause(false);
}

GameEngineSoundPlayer FakeProgramLevel::Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);

	return _ControlSoundName;
}