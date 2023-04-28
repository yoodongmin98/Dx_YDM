#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SelectBox : public GameEngineActor
{
public:
	// constrcuter destructer
	SelectBox();
	~SelectBox();

	// delete Function
	SelectBox(const SelectBox& _Other) = delete;
	SelectBox(SelectBox&& _Other) noexcept = delete;
	SelectBox& operator=(const SelectBox& _Other) = delete;
	SelectBox& operator=(SelectBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Box_1;
	std::shared_ptr<class GameEngineSpriteRenderer> Box_2;
	std::shared_ptr<class GameEngineSpriteRenderer> Box_3;
	

};

