/*
* @file		CCharaBase.h
* @brief	キャラクター(敵・味方)の基本機能
*
* @author	Ryoji Anzai
*/

#ifndef CHARABASE_INCLUDE_GUARD
#define CHARABASE_INCLUDE_GUARD
#include "../Base/CBase.h"

#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))

//キャラクターの基礎構造体
struct T_CharacterData {
	char imageName[64];
};
enum {
	ePlayerMan,	//プレイヤー男
	ePlayerWoman,//プレイヤー女
	eCarrot,//ニンジン
	ePapurika,//ピーマン
	eBerry,//イチゴサングラス空中
	eStrawberry,//イチゴ地上
	eVegetavelboss,//野菜ボス（ウサギ）
	ePig,//豚
	eBird,//鳥
	eMeatboss,//肉ボス（鶏）
	eSquid,//イカ
	eFish,//魚
	eFishboss,//魚介ボス（鮫）
	eRice,//米
	eBread,//パン
	eGrainboss,//穀物ボス（茶碗武士）
	eCharacterMax
};
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
class CCharaBase : public CBase
{
protected:
	enum ESTATE{
		eState_Idle,
		eState_Jump,
	};
	ESTATE m_state;
	CImage *m_chara;

	T_CharacterData  *mp_eData;

	//キャラクターのサイズを格納する変数
	int m_charaWidth;
	int m_charaHeight;
	//キャラクターのレベル
	int   m_level;
	//キャラクターの最大体力
	int   m_maxHp;
	//キャラクターの体力
	int   m_hp;
	//キャラクターの最大スキルポイント
	int   m_maxSp;
	//キャラクターのスキルポイント
	int   m_sp;
	//キャラクターの攻撃力
	int   m_power;
	//キャラクターの防御力
	int   m_defence;
	//キャラクターの現在経験値
	int   m_xp;
	//キャラクターの必要経験値
	int   m_exp;
	//キャラクターのスピード
	float m_speed;
	//キャラクターのジャンプ力
	float m_jump;
	//キャラクターの向きを格納するフラグ
	bool m_charaDirection;

	bool m_right;
	virtual void _key();
	void _idle();
public:
	CCharaBase(int type);
	~CCharaBase();
	void Animation();
	void Update();
	void Draw();
	void HitCheck();
};
extern T_PlayerData g_playerData[];
extern T_EnemyData g_enemyData[];
#endif