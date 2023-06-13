#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Binary0 : public G_ActorBase
{
public:
	Binary0();
	~Binary0();

	Binary0(const Binary0& _Other) = delete;
	Binary0(Binary0&& _Other) noexcept = delete;
	Binary0& operator=(const Binary0& _Other) = delete;
	Binary0& operator=(Binary0&& _Other) noexcept = delete;

	void SetBinary(float _Right, float _Down, float4 _Position,float4 _Scale)
	{
		RightValue = _Right;
		DownValue = _Down;
		StartPosition = _Position;
		StartScale = _Scale;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Binary0s;

	float4 StartPosition = float4::Zero;
	float4 StartScale = float4::Zero;

	bool Binarybool = true;
	float Binary0Time = 0.0f;

	float RightValue = 0;
	float DownValue = 0;
	
};

