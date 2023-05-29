#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class Vis : public G_ActorBase
{
public:
	Vis();
	~Vis();

	Vis(const Vis& _Other) = delete;
	Vis(Vis&& _Other) noexcept = delete;
	Vis& operator=(const Vis& _Other) = delete;
	Vis& operator=(Vis&& _Other) noexcept = delete;

	void SetVisPosition(float4 _Position)
	{
		Position = _Position;
	}
	void SetVisRotate(float4 _Rotate)
	{
		RotateValue = _Rotate;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Viss;
	std::shared_ptr<class GameEngineCollision> VissCollision;

	float4 Position = float4::Zero;
	float4 RotateValue = float4::Zero;

	bool SettingBools = true;
};

