/*
* @file		CCharaBase.h
* @brief	キャラクター(敵・味方)の基本機能
*
* @author	Ryoji Anzai
*/

#ifndef CHARABASE_INCLUDE_GUARD
#define CHARABASE_INCLUDE_GUARD
#include "../Base/CBase.h"
#include "../Game/Item/CItem.h"

#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))
#define NORMAL_SPEED 1
#define DASH_SPEED 2
#define ANIM_REVISION 1
#define DAMAGE_TIME 2
#define WINDOW_UP_LIMIT	600
#define WINDOW_DOWN_LIMIT 100
#define WINDOW_LEFT_LIMIT 50
#define FLASH_INTERBAL MILLI_SECOUND(0.2f)


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
	int charaType;	//キャラのタイプ
	SVector2D size;
	T_AnimData *animData;
	SVector2D texSize;
	SVector2D senter;	//キャラクターの中心点
	CRect rect;			//キャラクターの矩形
};
enum {
	ePlayerMan,	//プレイヤー男
	ePlayerWoman,//プレイヤー女
	eCarrot,//ニンジン
	eChick,//鳥
	eFish,//魚
	ePig,//豚
	eVegetavelboss,//野菜ボス（ウサギ）
	eBerry,//イチゴサングラス空中
	ePapurika,//ピーマン
	eStrawberry,//イチゴ地上
	eMeatboss,//肉ボス（鶏）
	eSquid,//イカ
	eFishboss,//魚介ボス（鮫）
	eRice,//米
	eBread,//パン
	eGrainboss,//穀物ボス（茶碗武士）
	eCharacterMax
};

class CCharaBase : public CBase, public CCollisionA
{
protected:
	enum ESTATE{
		eState_Jump,
		eState_Move,
		eState_Attack,
		eState_Damage,
		eState_Down
	};
	enum EANIM {
		eAnim_Idle,
		eAnim_Walk,
		eAnim_Dash,
		eAnim_Jump,
		eAnim_Attack,
		eAnim_Down,
	};
	ESTATE m_state;
	CImage *m_chara;
	CImage *m_enemyHp;
	CImage *m_red;
	
	const T_CharacterData  *mp_eData;
	
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
	//アニメーションをループさせるかどうかを格納する変数(false = No,true = Yes)
	int m_animLoop;
	//アニメーションの切り替えカウンター
	int m_animCounter;
	//ダッシュする時のスピード
	int m_dashSpeed;
	int m_flashTyming;
	//ダメージを受けているかどうかを格納する変数
	bool m_damage;
	//ダメージを関数の通過が初めてかどうかを格納する変数
	bool m_damageFirst;
	//ダメージをがどちら側から受けたかを格納する関数(false = 左,true = 右)
	bool m_damageDirection;
	//ダメージを受けた後の無敵時間を格納する変数
	int m_damageTime;
	int m_type;
	CVector3D m_oldPos;

	unsigned int m_anim;
	//キャラクターの向きを格納するフラグ
	bool m_charaDirection;
	bool m_right;
	bool m_left;
	bool m_up;
	bool m_down;
	bool m_jump;
	//ダッシュ中かどうかを格納する変数(false = No,true = Yes)
	bool m_dash;
	//ジャンプ中かどうかを格納する変数(false = No,true = Yes)
	bool m_jumpFlag;
	bool m_attack;
	bool m_death;
	void ResetKey();
	virtual void Contlol();
	void Move();
	void Jump();
	void Attack();
public:
	CCharaBase(int type, int id, unsigned int updatePrio, unsigned int drawPrio);
	~CCharaBase();
	void Animation();
	void ChangeAnimation(EANIM type,bool loop);
	void Update();
	virtual void Draw(); 
	virtual void HitCallBack(CCollisionA * p);
	bool CheckHit(CCollisionA *t);
	void Damage();
	virtual void Down();
	CVector3D GetPos()
	{
		return m_pos;
	}
	int GetAttack()
	{
		return m_power;
	}
	int CheckType()
	{
		return m_type;
	}
	int CheckState()
	{
		return m_state;
	}
	bool GetDeath()
	{
		return m_death;
	}

};
#endif