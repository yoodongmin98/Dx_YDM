#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class GlitchParticle : public G_ActorBase
{
public:
	GlitchParticle();
	~GlitchParticle();

	GlitchParticle(const GlitchParticle& _Other) = delete;
	GlitchParticle(GlitchParticle&& _Other) noexcept = delete;
	GlitchParticle& operator=(const GlitchParticle& _Other) = delete;
	GlitchParticle& operator=(GlitchParticle&& _Other) noexcept = delete;

	void SetGlitch(float _Right, float _Down, float4 _Position, float4 _Scale)
	{
		RightValue = _Right;
		DownValue = _Down;
		StartPosition = _Position;
		StartScale = _Scale;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> GlitchParticles;

	float4 StartPosition = float4::Zero;
	float4 StartScale = float4::Zero;

	bool Binarybool = true;
	float GlitchParticleTime = 0.0f;

	float RightValue = 0;
	float DownValue = 0;
};

