#include "PrecompileHeader.h"
#include "SkiteBanner.h"

//PlatForm
//Core



bool SkiteBannerImageLoad = true;
SkiteBanner::SkiteBanner()
{
}

SkiteBanner::~SkiteBanner()
{
}

void SkiteBanner::Start()
{
	if (true == SkiteBannerImageLoad)
	{
		AnimationImageLoad("Banner");
		SkiteBannerImageLoad = false;
	}
	AnimationInit(SkiteBanners, "SkiteAd01_00.png", { 246,87 }, { 335,-190,0 },"BannerAd","Banner",2.0f);
}

void SkiteBanner::Update(float _DeltaTime)
{

}

void SkiteBanner::Render(float _Delta)
{

};
