#pragma once
#include "GameEngineComponent.h"
#include "GameEngineShader.h"

class GameEngineRenderUnit 
{
public:
	std::shared_ptr<class GameEngineRenderingPipeLine > Pipe;
	GameEngineShaderResHelper ShaderResHelper;

public:
	void SetPipeLine(const std::string_view& _Name);
	void Render(float _DeltaTime);
};


// ���� :
class GameEngineRenderer : public GameEngineComponent
{
	friend class GameEngineCamera;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	// ������������ ���õǾ� �ְ�
	// � ���̴��� ����ߴٴ� �� �˾ƾ� �ϰ�
	// �� ���̴����� � �ؽ�ó�� ����߰�
	// � ���÷� � ������۸� ����ߴ����� �˾ƾ� �Ѵ�.
	void SetPipeLine(const std::string_view& _Name);

	inline GameEngineShaderResHelper& GetShaderResHelper() 
	{
		return ShaderResHelper;
	}

	void CameraCullingOn() 
	{
		IsCameraCulling = true;
	}


	// ������Ʈ���� �Ұ��̱� ������ �׳� �ϰڽ��ϴ�. 
	// ���� ���߿� ī�޶� �ٲٰų� �Ѵٸ� �̻��� ���� �߻��Ҽ� �ִ�.

protected:
	void Start();

	void Render(float _Delta) override;

	void PushCameraRender(int _CameraOrder);

private:
	bool IsCameraCulling = false;

	// Pipe��
	// GameEngineShaderResHelper �� �������� ������ �� �Ǵ� ���� �˴ϴ�.
	std::shared_ptr<class GameEngineRenderingPipeLine > Pipe;
	GameEngineShaderResHelper ShaderResHelper;

	void RenderTransformUpdate(GameEngineCamera* _Camera);
};

