#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class PlaywithinaplayLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PlaywithinaplayLevel();
	~PlaywithinaplayLevel();

	// delete Function
	PlaywithinaplayLevel(const PlaywithinaplayLevel& _Other) = delete;
	PlaywithinaplayLevel(PlaywithinaplayLevel&& _Other) noexcept = delete;
	PlaywithinaplayLevel& operator=(const PlaywithinaplayLevel& _Other) = delete;
	PlaywithinaplayLevel& operator=(PlaywithinaplayLevel&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<class Vis> Vis1;
	std::shared_ptr<class Vis> Vis2;
	std::shared_ptr<class Vis> Vis3;
	std::shared_ptr<class Vis> Vis4;
};

