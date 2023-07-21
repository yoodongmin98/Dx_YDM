#include "PrecompileHeader.h"
#include "DisTortion.h"

#include <GameEnginePlatform/GameEngineInput.h>
DisTortion::DisTortion() 
{
}

DisTortion::~DisTortion() 
{
}

//
void DisTortion::Start(GameEngineRenderTarget* _Target)
{
	OldUnit = std::make_shared<GameEngineRenderUnit>();
	OldUnit->SetMesh("FullRect");
	OldUnit->SetPipeLine("OldTV");

	OldData.ScreenScale = GameEngineWindow::GetScreenSize();

	OldUnit->ShaderResHelper.SetConstantBufferLink("RenderBaseValue", OldData);


	ResultTarget = GameEngineRenderTarget::Create(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, GameEngineWindow::GetScreenSize(), float4::Null);
}

void DisTortion::Effect(GameEngineRenderTarget* _Target, float _DeltaTime)
{
   
        OldData.Mouse = GameEngineWindow::GetMousePosition();
        OldData.Mouse.z = GameEngineInput::IsPress("EngineMouseLeft");
        OldData.Mouse.w = GameEngineInput::IsPress("EngineMouseLeft");

        OldData.Time.x += _DeltaTime*0.5f;
        OldData.Time.y = _DeltaTime*0.5f;

       ResultTarget->Clear();
       OldUnit->ShaderResHelper.SetTexture("DiffuseTex", _Target->GetTexture(0));
       ResultTarget->Setting();
       OldUnit->Render(_DeltaTime);
       OldUnit->ShaderResHelper.AllResourcesReset();

       _Target->Clear();
       _Target->Merge(ResultTarget);
    


}