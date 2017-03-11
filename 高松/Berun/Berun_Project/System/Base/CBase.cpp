#include "CBase.h"

//配列数を追加に応じて合わせる
#define P_ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))
#define E_ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

T_PlayerData g_playerData[] =
{
	//ID,レベル,最大HP,現在HP,最大SP,現在SP,攻撃力,防御力,取得経験値,必要経験値,移動速度,ジャンプ力
	{ 0,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
	{ 1,1,0,0,0,0,0,0,0,0,0.0f,0.0f },
};
#define P_ARRAY_SIZE(g_playerData);

T_EnemyData g_enemyData[] =
{
	//ID,最大HP,現在HP,攻撃力,防御力,経験値,移動速度
	{ 0,0,0,0,0,0,0.0f},
};
#define E_ARRAY_SIZE(g_enemyData);

CBase::CBase() : mp_pData(nullptr),mp_eData(nullptr),m_id(0),m_level(0),
				 m_maxHp(0),m_hp(0),m_maxSp(0),m_sp(0),m_power(0),
				 m_defence(0),m_xp(0),m_exp(0),m_speed(0.0f),m_jump(0.0f)
{
}

CBase::~CBase()
{
}
