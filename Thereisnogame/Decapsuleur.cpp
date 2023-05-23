#include "PrecompileHeader.h"
#include "Decapsuleur.h"

//PlatForm
//Core



Decapsuleur::Decapsuleur()
{
}

Decapsuleur::~Decapsuleur()
{
}

void Decapsuleur::Start()
{
	float4 Position = float4::Zero;
	Decapsuleurs = Init(Decapsuleurs, "CupObj_Empty.png", { 157,157 }, Position);
	Decapsuleurs_overlap = Init(Decapsuleurs_overlap, "CupObj_Empty_Overlap.png", { 157,157 }, { Position.x - 3,Position.y + 3 });
	DecapsuleursCollision = CollisionInit(DecapsuleursCollision, { 157,157,1 }, Position);
}

void Decapsuleur::Update(float _DeltaTime)
{
	Fall(Decapsuleurs, Decapsuleurs_overlap, DecapsuleursCollision, 78.5f, _DeltaTime);
	CatchCheck(Decapsuleurs, Decapsuleurs_overlap, DecapsuleursCollision);
}

void Decapsuleur::Render(float _Delta)
{

};
