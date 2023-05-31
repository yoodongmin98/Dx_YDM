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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelChangeStart() override;
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

