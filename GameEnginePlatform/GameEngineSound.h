#pragma once
#include <GameEnginePlatform/ThirdParty/FMOD/inc/fmod.hpp>
#include <string_view>
#include <unordered_map> 

class GameEngineSoundPlayer
{
private:
	FMOD::Channel* Channel = nullptr;

public:
	GameEngineSoundPlayer()
	{

	}

	GameEngineSoundPlayer(FMOD::Channel* _Channel)
		: Channel(_Channel)
	{

	}

	void Stop()
	{
		Channel->stop();
	}
	void SetPitch(float _Pitch)
	{
		//����ӵ� ����
		Channel->setPitch(_Pitch);
	}
	void SetVolume(float _Volume)
	{
		Channel->setVolume(_Volume);
	}
	void SetLoop(int _Count = -1)
	{
		// -1 -> ���ѷ��� / 0 -> ����X
		Channel->setLoopCount(_Count);
	}
	void SetMute(bool _Value)
	{
		Channel->setMute(_Value);
	}
	void SetPause(bool _Value)
	{
		Channel->setPaused(_Value);
	}
	void SetPosition(float _StartSecond, FMOD_TIMEUNIT _TimeUnit = FMOD_TIMEUNIT_MS)
	{
		//float���� _StartSecond�� �־��ָ� ms�� �����ؼ� �ش� �������� ����
		Channel->setPosition(static_cast<UINT>(_StartSecond * 1000.f), _TimeUnit);
	}
	void SetLoopPoint(float _StartSecond, float _EndSecond, FMOD_TIMEUNIT _TimeUnit = FMOD_TIMEUNIT_MS)
	{
		//_StartSecond ~_EndSecond ���� �ݺ�
		Channel->setLoopPoints(static_cast<UINT>(_StartSecond * 1000.f), _TimeUnit, static_cast<UINT>(_EndSecond * 1000.f), _TimeUnit);
	}
};

// ���� :
// �̳༮ ��ü�� ���� ���� ���ҵ� �մϴ�.
class GameEngineSound
{
private: // manager
	static std::unordered_map<std::string, std::shared_ptr<GameEngineSound>> AllSound;


public:
	static void ResourcesClear();

	static void SoundUpdate();

	GameEngineSound();
	~GameEngineSound();

	// delete Function
	GameEngineSound(const GameEngineSound& _Other) = delete;
	GameEngineSound(GameEngineSound&& _Other) noexcept = delete;
	GameEngineSound& operator=(const GameEngineSound& _Other) = delete;
	GameEngineSound& operator=(GameEngineSound&& _Other) noexcept = delete;

	static void Load(const std::string_view& _Path);

	static void Load(const std::string_view& _Name, const std::string_view& _Path);

	static GameEngineSoundPlayer Play(const std::string_view& _Name);

protected:

private:
	void SoundLoad(const std::string_view& _Path);
	FMOD::Channel* SoundPlay();
	// ������
	// ����
	// ���

	// map ����� ���� �����̳�
	// Hash��� ���Դϴ�. 

	FMOD::Sound* FMODSound = nullptr;

};

