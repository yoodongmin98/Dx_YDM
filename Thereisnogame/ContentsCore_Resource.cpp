#include "PrecompileHeader.h"
#include "ContentsCore.h"

#include <GameEngineCore/GameEngineRenderingPipeLine.h>

void ContentsCore::ResourceInit(std::string_view _ShaderName, std::string_view _PipeName)
{
	std::shared_ptr<GameEngineRenderingPipeLine> PipeLine = GameEngineRenderingPipeLine::Create(_PipeName);
	//PipeLine->SetVertexBuffer("FullRect");
	//PipeLine->SetIndexBuffer("FullRect");
	PipeLine->SetVertexShader(_ShaderName);
	PipeLine->SetRasterizer("Engine2DBase");
	PipeLine->SetPixelShader(_ShaderName);
	PipeLine->SetBlendState("AlphaBlend");
	PipeLine->SetDepthState("EngineDepth");
}