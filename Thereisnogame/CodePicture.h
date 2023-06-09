#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class CodePicture : public G_ActorBase
{
public:
	// constrcuter destructer
	CodePicture();
	~CodePicture();

	// delete Function
	CodePicture(const CodePicture& _Other) = delete;
	CodePicture(CodePicture&& _Other) noexcept = delete;
	CodePicture& operator=(const CodePicture& _Other) = delete;
	CodePicture& operator=(CodePicture&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CodePictures;
};

