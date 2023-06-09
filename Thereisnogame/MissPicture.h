#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class MissPicture : public G_ActorBase
{
public:
	static MissPicture* MP;
	// constrcuter destructer
	MissPicture();
	~MissPicture();

	// delete Function
	MissPicture(const MissPicture& _Other) = delete;
	MissPicture(MissPicture&& _Other) noexcept = delete;
	MissPicture& operator=(const MissPicture& _Other) = delete;
	MissPicture& operator=(MissPicture&& _Other) noexcept = delete;

	std::shared_ptr<GameEngineSpriteRenderer> ChangeMissPictureRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender);
	void ChangeMissPicture(int _Value);

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MissFR;
	std::shared_ptr<class GameEngineSpriteRenderer> MissUS;
	std::shared_ptr<class GameEngineSpriteRenderer> MissJP;

	std::shared_ptr<class GameEngineSpriteRenderer> WhatisPicture;

	std::vector<std::shared_ptr<class GameEngineSpriteRenderer>> PictureSelectVector;
};

