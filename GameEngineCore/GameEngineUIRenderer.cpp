#include "PrecompileHeader.h"
#include "GameEngineUIRenderer.h"
#include "GameEngineLevel.h"

GameEngineUIRenderer::GameEngineUIRenderer() 
{
}

GameEngineUIRenderer::~GameEngineUIRenderer() 
{
}


void GameEngineUIRenderer::Start() 
{
	PushCameraRender(-1);
	SpriteRenderInit();
}
