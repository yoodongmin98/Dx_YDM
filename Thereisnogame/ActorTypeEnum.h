#pragma once

enum class ActorTypeEnum
{
	//Render용
	BackActor,
	Curtain,
	Cordon,
	FolderBackGround,
	ScreenActor,


	//상호작용(Collision)
	Nut_Close,
	Nut_Open,
	Cup_Full,
	Decapsuleur,
	Picture,
	ZipWip,
	LockFolder,
	//Chap1
	Cursor,
	Speaker,
	//Chapter1 BallGame
	Block,
	Excla,
	Ball,
	//Chap1Etc
	DownCheck,

	//AlphaCircle,Mouse,FrontBack
	Alpha,
	Mouse,
	WhiteFront
};