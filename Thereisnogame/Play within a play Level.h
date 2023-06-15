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
	TiltBoard,
	BalloonUp,
};
enum class RoshamboState
{
	None,
	SelectCard,
	EnemyCard,
	CardDownAndOff,
};
// 설명 :
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

	void RSBChangeState(RoshamboState _State);
	void RSBUpdateState(float _DeltaTime);

	Chap1LevelState GetLevelState()
	{
		return StateValue;
	}

	RoshamboState GetRoShamboState()
	{
		return RSBStateValue;
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
	RoshamboState RSBStateValue = RoshamboState::None;

	int DebugIntValue = 0;

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
	std::shared_ptr<class BalloonSecure> BalloonSecurePtr;
	
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

	std::shared_ptr<class TransparencyActor> TransparencyActorPtr;

	//이마저도 노가다로 만들어버리는 무식한 나
	std::shared_ptr<class Binary0> Binary0Ptr1;
	std::shared_ptr<class Binary0> Binary0Ptr2;
	std::shared_ptr<class Binary0> Binary0Ptr3;
	std::shared_ptr<class Binary0> Binary0Ptr4;
	std::shared_ptr<class Binary0> Binary0Ptr5;
	std::shared_ptr<class Binary0> Binary0Ptr6;
	std::shared_ptr<class Binary0> Binary0Ptr7;
	std::shared_ptr<class Binary0> Binary0Ptr8;
	std::shared_ptr<class Binary0> Binary0Ptr9;
	std::shared_ptr<class Binary0> Binary0Ptr10;
	std::shared_ptr<class Binary0> Binary0Ptr11;

	std::shared_ptr<class Binary1> Binary1Ptr1;
	std::shared_ptr<class Binary1> Binary1Ptr2;
	std::shared_ptr<class Binary1> Binary1Ptr3;
	std::shared_ptr<class Binary1> Binary1Ptr4;
	std::shared_ptr<class Binary1> Binary1Ptr5;
	std::shared_ptr<class Binary1> Binary1Ptr6;
	std::shared_ptr<class Binary1> Binary1Ptr7;
	std::shared_ptr<class Binary1> Binary1Ptr8;
	std::shared_ptr<class Binary1> Binary1Ptr9;
	std::shared_ptr<class Binary1> Binary1Ptr10;

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
	float CardTime = 0.0f;
	//-------Roshambo State-------//
	void SelectCardStart();
	void SelectCardUpdate(float _DeltaTime);
	void SelectCardEnd();

	void EnemyCardStart();
	void EnemyCardUpdate(float _DeltaTime);
	void EnemyCardEnd();
	float EnemyCardTime = 0.0f;

	void CardDownAndOffStart();
	void CardDownAndOffUpdate(float _DeltaTime);
	void CardDownAndOffEnd();
	//----------------------------//

	void TiltBoardStart();
	void TiltBoardUpdate(float _DeltaTime);
	void TiltBoardEnd();
	float NOTime = 0.0f;

	void BalloonUpStart();
	void BalloonUpUpdate(float _DeltaTime);
	void BalloonUpEnd();
};

