#include "PrecompileHeader.h"
#include "GlitchParticle.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
GlitchParticle::GlitchParticle()
{
}

GlitchParticle::~GlitchParticle()
{
}
bool GlitchLoadBool = true;
void GlitchParticle::Start()
{
	if (true == GlitchLoadBool)
	{
		AnimationImageLoad("GlichParticle");
		GlitchLoadBool = false;
	}
	GlitchParticles = AnimationInit(GlitchParticles, "Glitch_Particle1_0.png", { 72,72 }, float4::Zero, "GlichParticles", "GlichParticle", 11, 0.1f, true);
	GlitchParticles->ColorOptionValue.MulColor.a = 1;
}

void GlitchParticle::Update(float _DeltaTime)
{
	GlitchParticles->ColorOptionValue.MulColor.a -= 0.0025f;
	if (GlitchParticles->ColorOptionValue.MulColor.a <= 0)
	{
		Death();
	}
	GlitchParticles->GetTransform()->SetLocalPosition(StartPosition);
	GlitchParticles->GetTransform()->SetLocalScale(StartScale);
	GlitchParticleTime += _DeltaTime;
	RightFallRigid(RightValue, DownValue, Binarybool, GlitchParticleTime);
}

void GlitchParticle::Render(float _Delta)
{

};
