#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class CodeIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	CodeIcon();
	~CodeIcon();

	// delete Function
	CodeIcon(const CodeIcon& _Other) = delete;
	CodeIcon(CodeIcon&& _Other) noexcept = delete;
	CodeIcon& operator=(const CodeIcon& _Other) = delete;
	CodeIcon& operator=(CodeIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CodeIcons;
};

