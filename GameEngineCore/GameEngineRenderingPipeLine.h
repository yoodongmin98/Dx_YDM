#pragma once
#include "GameEngineResource.h"

// ���� :
class GameEngineRenderingPipeLine : public GameEngineResource<GameEngineRenderingPipeLine>
{
public:
	// constrcuter destructer
	GameEngineRenderingPipeLine();
	~GameEngineRenderingPipeLine();

	// delete Function
	GameEngineRenderingPipeLine(const GameEngineRenderingPipeLine& _Other) = delete;
	GameEngineRenderingPipeLine(GameEngineRenderingPipeLine&& _Other) noexcept = delete;
	GameEngineRenderingPipeLine& operator=(const GameEngineRenderingPipeLine& _Other) = delete;
	GameEngineRenderingPipeLine& operator=(GameEngineRenderingPipeLine&& _Other) noexcept = delete;

	void SetVertexBuffer(const std::string_view& _Value);
	void SetIndexBuffer(const std::string_view& _Value);
	void SetVertexShader(const std::string_view& _Value);
	void SetRasterizer(const std::string_view& _Value);
	void SetPixelShader(const std::string_view& _Value);

	inline void SetFILL_MODE(D3D11_FILL_MODE _Value)
	{
		FILL_MODE = _Value;
	}

	void Render();

protected:

private:

	// Directx11 ������ ������������ �ܰ迡�� 2���� ������ �ִµ�.
	// ������� �ܰ� => ���� �ɼ������� �Ѱܼ� ����� �ܰ�
	// ���α׷��� ���� �ܰ� => Ư�� ��Ģ�� ��Ű�� �������� ���� ���� ������� ©�� �ִ� �ܰ踦 �ǹ��Ѵ�.
	// ���̴� �迭�� �� ���α׷��� ���� �ܰ� �ܰ�� 
	// ���������� ������� �ܰ��� �θ���.

	void InputAssembler1();
	void VertexShader();
	void InputAssembler2();
	void HullShader(); 
	void Tessellator(); 
	void DomainShader(); 
	void GeometryShaeder(); 
	void Rasterizer();
	void PixelShader();
	void OutputMerger();


	D3D11_FILL_MODE FILL_MODE = D3D11_FILL_MODE::D3D11_FILL_SOLID;
	D3D11_PRIMITIVE_TOPOLOGY TOPOLOGY = D3D11_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	std::shared_ptr<class GameEngineInputLayOut> InputLayOutPtr;
	std::shared_ptr<class GameEngineVertexBuffer> VertexBufferPtr;
	std::shared_ptr<class GameEngineIndexBuffer> IndexBufferPtr;
	std::shared_ptr<class GameEngineVertexShader> VertexShaderPtr;
	std::shared_ptr<class GameEngineRasterizer> RasterizerPtr;
	std::shared_ptr<class GameEnginePixelShader> PixelShaderPtr;

};

