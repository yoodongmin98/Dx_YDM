#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BackCurtain : public GameEngineActor
{
public:
	// constrcuter destructer
	BackCurtain();
	~BackCurtain();

	// delete Function
	BackCurtain(const BackCurtain& _Other) = delete;
	BackCurtain(BackCurtain&& _Other) noexcept = delete;
	BackCurtain& operator=(const BackCurtain& _Other) = delete;
	BackCurtain& operator=(BackCurtain&& _Other) noexcept = delete;


	void CurtainOpen(int _Speed);
	void CurtainClose(int _Speed);
	
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftCurtain;
	std::shared_ptr<class GameEngineSpriteRenderer> RightCurtain;

};

