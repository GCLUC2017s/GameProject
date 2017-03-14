#include "CPlayer.h"

T_PlayerData g_playerData[] =
{
	//ID,レベル,最大HP,現在HP,最大SP,現在SP,攻撃力,防御力,取得経験値,必要経験値,移動速度,ジャンプ力
	{ 0,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
	{ 1,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
};
CPlayer::CPlayer(int type):CCharaBase(0)
{
	mp_pData = &g_playerData[type];
	
	m_hp = mp_pData->hp;
	
}
CPlayer::~CPlayer()
{

}


