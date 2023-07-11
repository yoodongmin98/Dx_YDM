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

void FakeProgramLevel::FPlay(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);
}

void FakeProgramLevel::FPause(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(true);
}

void FakeProgramLevel::PausePlay(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(false);
}

void FakeProgramLevel::ChangeBGM(const std::string_view& _MusicName, float _Volume)
{
	//MainBGM= GameEngineSound::Play(_MusicName);
	//MainBGM.SetVolume(_Volume);
	//MainBGM.SetLoop(0);

}