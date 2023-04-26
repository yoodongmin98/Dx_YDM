#include "PrecompileHeader.h"
#include "GameEngineRenderer.h"
#include <GameEnginePlatform/GameEngineWindow.h>


#include "GameEngineLevel.h"
#include "GameEngineCamera.h"
#include "GameEngineRenderingPipeLine.h"
#include "GameEngineVertexShader.h"
#include "GameEnginePixelShader.h"
#include "GameEngineShaderResHelper.h"

GameEngineRenderer::GameEngineRenderer() 
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}


void GameEngineRenderer::Render(float _Delta) 
{
	std::shared_ptr<GameEngineCamera> MainCamera = GetLevel()->GetMainCamera();

	if (nullptr == MainCamera)
	{
		assert(false);
		return;
	}

	GetTransform()->SetCameraMatrix(MainCamera->GetView(), MainCamera->GetProjection());


	// GameEngineDevice::GetContext()->VSSetConstantBuffers();
	// GameEngineDevice::GetContext()->PSSetConstantBuffers();

	// �ؽ�ó ���� ������� ���� �̷��͵��� ���δ� ó�� �ȴ�.

	Pipe->RenderingPipeLineSetting();

	ShaderResHelper.Setting();

	// �̰��ϱ� ���� �� ������ �Ϻ��ϰ� �Ǿ������� �ȴ�.
	Pipe->Render();
}

void GameEngineRenderer::SetPipeLine(const std::string_view& _Name)
{
	Pipe = GameEngineRenderingPipeLine::Find(_Name);

	{
		const GameEngineShaderResHelper& Res = Pipe->GetVertexShader()->GetShaderResHelper();
		ShaderResHelper.Copy(Res);
	}

	{
		const GameEngineShaderResHelper& Res = Pipe->GetPixelShader()->GetShaderResHelper();
		ShaderResHelper.Copy(Res);
	}

	if (true == ShaderResHelper.IsConstantBuffer("TransformData"))
	{
		const TransformData& Data = GetTransform()->GetTransDataRef();
		ShaderResHelper.SetConstantBufferLink("TransformData", Data);
	}


	GetTransform()->GetWorldMatrix();
}