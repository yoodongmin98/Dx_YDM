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

void PlaywithinaplayLevel::ReSetBGM()
{
	MainBGM = GameEngineSound::Play("MusicStart.wav");
	MainBGM.SetVolume(0.1f);
	MainBGM.SetLoop(0);
}

void PlaywithinaplayLevel::StopBGM()
{
	MainBGM.Stop();
}

GameEngineSoundPlayer PlaywithinaplayLevel::ChangeBGM(const std::string_view& _MusicName)
{
	MainBGM.Stop();
	MainBGM = GameEngineSound::Play(_MusicName);
	MainBGM.SetVolume(0.1f);
	MainBGM.SetLoop(-1);

	return MainBGM;
}