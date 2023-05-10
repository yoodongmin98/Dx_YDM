#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MusicNote_Walnut : public G_ActorBase
{
public:
	// constrcuter destructer
	MusicNote_Walnut();
	~MusicNote_Walnut();

	// delete Function
	MusicNote_Walnut(const MusicNote_Walnut& _Other) = delete;
	MusicNote_Walnut(MusicNote_Walnut&& _Other) noexcept = delete;
	MusicNote_Walnut& operator=(const MusicNote_Walnut& _Other) = delete;
	MusicNote_Walnut& operator=(MusicNote_Walnut&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MusicNote_Walnuts;

};

