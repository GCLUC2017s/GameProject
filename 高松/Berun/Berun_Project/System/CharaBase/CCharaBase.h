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
#define CHARA_MOVE 4
#define ANIM_REVISION 1

struct T_AnimData {
	int pattrn;
	int speed;
};
//キャラクターの基礎構造体
struct T_CharacterData {
	char imageName[64];
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
	float xSize;	//Xサイズ
	float ySize;	//Yサイズ
	T_AnimData *animData;
};
enum {
	ePlayerMan,	//プレイヤー男
	ePlayerWoman,//プレイヤー女
	eCarrot,//ニンジン
	eBerry,//イチゴサングラス空中
	ePapurika,//ピーマン
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

class CCharaBase : public CBase
{
protected:
	enum ESTATE{
		eState_Idle,
		eState_Jump,
		eState_Move,
		eState_Attack,
		
	};
	enum {
		eAnim_Walk,
		eAnim_Idle,
		eAnim_Attack,
	};
	ESTATE m_state;
	CImage *m_chara;
	CImage *m_enemyHp;
	T_CharacterData  *mp_eData;
	
	int m_imgPtn;
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
	//アニメーションパターンの何行目かを格納する変数
	int m_animPaternX;
	//アニメーションパターンの何列目かを格納する変数
	int m_animPaternY;
	//アニメーションの切り替えカウンター
	int m_animCounter;
	//ダッシュする時のスピード
	int m_dashSpeed;
	//キャラクターのジャンプ力
	float m_jump;
	float m_xSize;//キャラクターのXサイズ
	float m_ySize;//キャラクターのYサイズ
	//キャラクターの向きを格納するフラグ
	bool m_charaDirection;
	bool m_right;
	bool m_left;
	bool m_up;
	bool m_down;
	//ダッシュ中かどうかを格納する変数(false = No,true = Yes)
	bool m_dash;
	//ジャンプする時に走っていたかどうかを格納する変数(false = No,true = Yes)
	bool m_jumpInDash;
	//ジャンプ中かどうかを格納する変数(false = No,true = Yes)
	bool m_jumpFlag;
	virtual void Key();
	void Idle();
	void Move();
	void Jump();
	void HpBar();
public:
	CCharaBase(int type, unsigned int updatePrio, unsigned int drawPrio);
	~CCharaBase();
	void Animation();
	void Update();
	virtual void Draw();
	void HitCheck();
};

#endif