#pragma once

// Ό³Έν :
class GameCore
{
public:
	// constrcuter destructer
	GameCore();
	~GameCore();

	// delete Function
	GameCore(const GameCore& _Other) = delete;
	GameCore(GameCore&& _Other) noexcept = delete;
	GameCore& operator=(const GameCore& _Other) = delete;
	GameCore& operator=(GameCore&& _Other) noexcept = delete;

	static void GameStart();
	static void GameEnd();

protected:

private:
};

