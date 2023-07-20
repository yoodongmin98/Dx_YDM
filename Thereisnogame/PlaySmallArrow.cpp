#include "PrecompileHeader.h"
#include "PlaySmallArrow.h"
//PlatForm
//Core


PlaySmallArrow::PlaySmallArrow()
{
}

PlaySmallArrow::~PlaySmallArrow()
{
}


void PlaySmallArrow::Start()
{
	Arrow = Init(Arrow, "End_small_Arrow.png", { 44,32 }, { 120,50 });
	Arrow->SetFlipX();
	Sound = Play(Sound, "End_Pop01.wav", 0.1f);
}

void PlaySmallArrow::Update(float _DeltaTime)
{

}

void PlaySmallArrow::Render(float _Delta)
{

};


