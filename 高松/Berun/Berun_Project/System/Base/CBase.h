/**
*@file
*@brief  基底クラス
*@author 山路
*/

#ifndef CBASE_GUARD
#define CBASE_GUARD

//プレイヤーの構造体
struct T_PlayerData
{
	int id;			//ID
	int level;		//レベル
	int maxHp;		//最大HP
	int hp;			//現在HP
	int maxSp;		//最大SP
	int sp;			//現在SP
	int power;		//攻撃力
	int defense;	//防御力
	int xp;			//取得経験値
	int exp;		//必要経験値
	float speed;	//移動速度
	float jump;		//ジャンプ力
};
//敵の構造体
struct T_EnemyData
{
	int m_id;		//ID
	int maxHp;		//最大HP
	int hp;			//現在HP
	int power;		//攻撃力
	int defense;	//防御力
	int xp;			//経験値
	float speed;	//移動速度
};

class CBase
{
private:
	T_PlayerData *mp_pData;
	T_EnemyData  *mp_eData;
	int   m_id;
	int   m_level;
	int   m_maxHp;
	int   m_hp;
	int   m_maxSp;
	int   m_sp;
	int   m_power;
	int   m_defence;
	int   m_xp;
	int   m_exp;
	float m_speed;
	float m_jump;
public:
	CBase();
	~CBase();
};

extern T_PlayerData g_playerData[];
extern T_EnemyData g_enemyData[];

#endif