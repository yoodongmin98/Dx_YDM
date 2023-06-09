#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MusicNote_Radio : public G_ActorBase
{
public:
	// constrcuter destructer
	MusicNote_Radio();
	~MusicNote_Radio();

	// delete Function
	MusicNote_Radio(const MusicNote_Radio& _Other) = delete;
	MusicNote_Radio(MusicNote_Radio&& _Other) noexcept = delete;
	MusicNote_Radio& operator=(const MusicNote_Radio& _Other) = delete;
	MusicNote_Radio& operator=(MusicNote_Radio&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicNote_Radios;
	std::shared_ptr<class GameEngineCollision> MusicNote_RadiosCollision;

};

