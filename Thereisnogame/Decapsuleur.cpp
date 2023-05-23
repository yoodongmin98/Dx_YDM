#include "PrecompileHeader.h"
#include "Decapsuleur.h"
#include "ActorTypeEnum.h"
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
	Decapsuleurs = Init(Decapsuleurs, "Decapsuleur.png", { 157,157 }, Position);
	Decapsuleurs_overlap = Init(Decapsuleurs_overlap, "Decapsuleur_Overlap.png", { 186,186 }, { Position.x - 3,Position.y + 3 });

	DecapsuleursCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Decapsuleur);
	DecapsuleursCollision->GetTransform()->SetLocalScale({ 157,157,1 });
	DecapsuleursCollision->GetTransform()->SetLocalPosition(Position);
}

void Decapsuleur::Update(float _DeltaTime)
{
	Fall(Decapsuleurs, Decapsuleurs_overlap, DecapsuleursCollision, 78.5f, _DeltaTime);
	CatchCheck(Decapsuleurs, Decapsuleurs_overlap, DecapsuleursCollision);
}

void Decapsuleur::Render(float _Delta)
{

};
