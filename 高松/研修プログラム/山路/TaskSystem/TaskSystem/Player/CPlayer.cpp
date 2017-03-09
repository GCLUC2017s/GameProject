#include "CPlayer.h"

CPlayer::CPlayer()
{
	printf("CPlayerコンストラクタ呼び出し\n");
}

CPlayer::~CPlayer()
{
	printf("CPlayerデストラクタ呼び出し\n");
}

void CPlayer::Update()
{
	printf("プレイヤー更新");
}

void CPlayer::Render()
{
	printf("プレイヤー描画");
}
