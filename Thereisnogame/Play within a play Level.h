#pragma once
#include <GameEngineCore\GameEngineLevel.h>


enum class Chap1LevelState
{
	None,
	ClickCordon,
	CreateBoard,
	DownBoard,
	ClearBoard,
	SlantBoard,
	Roshambo,
};
enum class RoshamboState
{
	None,
};
// Ό³Έν :
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
	std::shared_ptr<class FadeEffect> FEffect;

	void ChangeState(Chap1LevelState _State);
	void UpdateState(float _DeltaTime);

	Chap1LevelState GetLevelState()
	{
		return StateValue;
	}

	void MinusBlockCount()
	{
		BlockCount -= 1;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;
private:
	Chap1LevelState StateValue = Chap1LevelState::None;

	std::shared_ptr<class Mouse> MousePtr = nullptr;

	std::shared_ptr<class Vis> Vis1;
	std::shared_ptr<class Vis> Vis2;
	std::shared_ptr<class Vis> Vis3;
	std::shared_ptr<class Vis> Vis4;




	//Actor
	std::shared_ptr<class Cordon> CordonPtr;
	std::shared_ptr<class BackCurtain> BackCurtainPtr;
	std::shared_ptr<class AlphaCircle> AlphaCirclePtr;
	std::shared_ptr<class Chain> ChainPtr;
	std::shared_ptr<class Lope_Chain> Lope_ChainPtr;
	std::shared_ptr<class Lope_Corde> Lope_CordePtr;
	std::shared_ptr<class Board> BoardPtr;
	
	std::shared_ptr<class T_TitleCube> T_TitleCubePtr;
	std::shared_ptr<class H_TitleCube> H_TitleCubePtr;
	std::shared_ptr<class E_TitleCube> E_TitleCubePtr;
	std::shared_ptr<class R_TitleCube> R_TitleCubePtr;
	std::shared_ptr<class RE_TitleCube> RE_TitleCubePtr;
	std::shared_ptr<class I_TitleCube> I_TitleCubePtr;
	std::shared_ptr<class S_TitleCube> S_TitleCubePtr;
	std::shared_ptr<class N_TitleCube> N_TitleCubePtr;
	std::shared_ptr<class O_TitleCube> O_TitleCubePtr;
	std::shared_ptr<class G_TitleCube> G_TitleCubePtr;
	std::shared_ptr<class A_TitleCube> A_TitleCubePtr;
	std::shared_ptr<class M_TitleCube> M_TitleCubePtr;
	std::shared_ptr<class ME_TitleCube> ME_TitleCubePtr;
	std::shared_ptr<class Excla_TitleCube> Excla_TitleCubePtr;
	std::shared_ptr<class Ball_TitleCube> Ball_TitleCubePtr;

	std::shared_ptr<class T_TitleMetal> T_TitleMetalPtr;
	std::shared_ptr<class H_TitleMetal> H_TitleMetalPtr;
	std::shared_ptr<class E_TitleMetal> E_TitleMetalPtr;
	std::shared_ptr<class R_TitleMetal> R_TitleMetalPtr;
	std::shared_ptr<class RE_TitleMetal> RE_TitleMetalPtr;
	std::shared_ptr<class I_TitleMetal> I_TitleMetalPtr;
	std::shared_ptr<class S_TitleMetal> S_TitleMetalPtr;
	std::shared_ptr<class N_TitleMetal> N_TitleMetalPtr;
	std::shared_ptr<class O_TitleMetal> O_TitleMetalPtr;
	std::shared_ptr<class G_TitleMetal> G_TitleMetalPtr;
	std::shared_ptr<class A_TitleMetal> A_TitleMetalPtr;
	std::shared_ptr<class M_TitleMetal> M_TitleMetalPtr;
	std::shared_ptr<class ME_TitleMetal> ME_TitleMetalPtr;

	std::shared_ptr<class R_Sissor> R_SissorPtr;
	std::shared_ptr<class R_Rock> R_RockPtr;
	std::shared_ptr<class R_Paper> R_PaperPtr;
	std::shared_ptr<class R_EnemySissor> R_EnemySissorPtr;
	std::shared_ptr<class R_EnemyRock> R_EnemyRockPtr;
	std::shared_ptr<class R_EnemyPaper> R_EnemyPaperPtr;
	std::shared_ptr<class R_Dos> R_DosPtr;

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
	int BlockCount = 0;

	void ClearBoardStart();
	void ClearBoardUpdate(float _DeltaTime);
	void ClearBoardEnd();

	void SlantBoardStart();
	void SlantBoardUpdate(float _DeltaTime);
	void SlantBoardEnd();

	void RoshamboStart();
	void RoshamboUpdate(float _DeltaTime);
	void RoshamboEnd();
};

