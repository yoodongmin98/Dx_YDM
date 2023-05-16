#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class Mouse : public G_ActorBase
{
public:
	static Mouse* MainMouse;
	// constrcuter destructer
	Mouse();
	~Mouse();

	// delete Function
	Mouse(const Mouse& _Other) = delete;
	Mouse(Mouse&& _Other) noexcept = delete;
	Mouse& operator=(const Mouse& _Other) = delete;
	Mouse& operator=(Mouse&& _Other) noexcept = delete;

	std::shared_ptr<GameEngineSpriteRenderer> ChangeMouse(std::shared_ptr<class GameEngineSpriteRenderer> _MouseOnRender);
	void MousePositionUpdate(std::shared_ptr<GameEngineSpriteRenderer> _Mouse);

	float4 GetMousePos()
	{
		return MousePos;
	}
	
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MouseIdle;
	std::shared_ptr<class GameEngineSpriteRenderer> MouseInteractable;
	std::shared_ptr<class GameEngineSpriteRenderer> MouseHand;
	std::shared_ptr<class GameEngineSpriteRenderer> MouseHandtake;
	std::shared_ptr<class GameEngineSpriteRenderer> MouseUnavailable;

	std::shared_ptr<class GameEngineSpriteRenderer> whatisMouse;

	std::vector<std::shared_ptr<class GameEngineSpriteRenderer>> Mousesituation;

	float4 MousePos = float4::Zero;
};
