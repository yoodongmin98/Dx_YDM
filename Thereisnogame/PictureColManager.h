#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class PictureState
{
	None,
	PictureIcon,
	PictureInPicture
};

class PictureColManager : public GameEngineActor
{
public:
	static PictureColManager* MG;
	// constrcuter destructer
	PictureColManager();
	~PictureColManager();

	// delete Function
	PictureColManager(const PictureColManager& _Other) = delete;
	PictureColManager(PictureColManager&& _Other) noexcept = delete;
	PictureColManager& operator=(const PictureColManager& _Other) = delete;
	PictureColManager& operator=(PictureColManager&& _Other) noexcept = delete;
	void PictureStateCheck();
	void ChangePictureState(PictureState _State);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
private:
	PictureState StateValue = PictureState::None;
};

