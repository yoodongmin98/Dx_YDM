#pragma once
#include <GameEngineCore\GameEngineLevel.h>


enum class Chap1LevelState
{
	None,
	ClickCordon,
	CreateBoard,
	DownBoard,
	ClearBoard,
};
// ���� :
class PlaywithinaplayLevel : public GameEngineLevel
{
public:
	static PlaywithinaplayLevel* LM;
	// constrcuter destructer
	PlaywithinaplayLevel();
	~PlaywithinaplayLevel();

	// delete Function
	PlaywithinaplayLevel(const PlaywithinaplayLevel& _Other) = delete;
	PlaywithinaplayLevel(PlaywithinaplayLevel&& _Other) noexcept = delete;
	PlaywithinaplayLevel& operator=(const PlaywithinaplayLevel& _Other) = delete;
	PlaywithinaplayLevel& operator=(PlaywithinaplayLevel&& _Other) noexcept = delete;

	void ChangeState(Chap1LevelState _State);
	void UpdateState(float _DeltaTime);

	Chap1LevelState GetLevelState()
	{
		return StateValue;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	Chap1LevelState StateValue = Chap1LevelState::None;

	std::shared_ptr<class Vis> Vis1;
	std::shared_ptr<class Vis> Vis2;
	std::shared_ptr<class Vis> Vis3;
	std::shared_ptr<class Vis> Vis4;



	//Actor
	std::shared_ptr<class BackCurtain> BackCurtainPtr;
	std::shared_ptr<class AlphaCircle> AlphaCirclePtr;
	std::shared_ptr<class Chain> ChainPtr;
	std::shared_ptr<class Lope_Chain> Lope_ChainPtr;
	std::shared_ptr<class Lope_Corde> Lope_CordePtr;
	std::shared_ptr<class Board> BoardPtr;
	
	


	///State
	void ClickCordonStart();
	void ClickCordonUpdate(float _DeltaTime);
	void ClickCordonEnd();
	
	void CreateBoardStart();
	void CreateBoardUpdate(float _DeltaTime);
	void CreateBoardEnd();
	float CreateBoardTime = 0.0f;

	void DownBoardStart();
	void DownBoardUpdate(float _DeltaTime);
	void DownBoardEnd();

	void ClearBoardStart();
	void ClearBoardUpdate(float _DeltaTime);
	void ClearBoardEnd();

};

