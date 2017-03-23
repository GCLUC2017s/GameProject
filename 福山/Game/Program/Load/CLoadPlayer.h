/*
プレイヤーテクスチャLood(時間があればまとめます)クラス
担当者 冨田健斗
*/

#include "../Graphic/CTexture.h"
#include "../Define/define.h"
#define FRAME_LIMIT8 8//フレーム数が違うようになったので注意 8のもの (現在)walk run Ex01
#define FRAME_LIMIT3 3//フレーム数が違うようになったので注意 3のもの (現在)Eat Jump
#define FRAME_LIMIT2 2//フレーム数が違うようになったので注意 2のもの (現在)break

class CLoadPlayer
{
private:
	static CLoadPlayer *mLoadPlayer;
public:
	static CLoadPlayer *GetInstance(); //GetInstance

	CTexture	*mStayTex[FRAME_LIMIT];									//待ちテクスチャ
	CTexture	*mWalkTex[FRAME_LIMIT8];									//歩くテクスチャ
	CTexture	*mRunTex[FRAME_LIMIT8];									//走るテクスチャ
	CTexture	*mNormalAttackTex[NORMALATTACK_PATTERN][FRAME_LIMIT];	//通常攻撃テクスチャ
	CTexture	*mJumpAttackTex[FRAME_LIMIT];

	CTexture	*mEatTex[FRAME_LIMIT3];									//捕食テクスチャ
	CTexture	*mEx01Tex[FRAME_LIMIT8];									//必殺技(消費)テクスチャ									

	CTexture	*mEx02Tex[FRAME_LIMIT];									//必殺技(継続)テクスチャ
	CTexture	*mFlameTex[FRAME_LIMIT];								//炎テクスチャ
	CTexture	*mBrakeTex[FRAME_LIMIT];								//ブレーキテクスチャ
	CTexture	*mJumpTex[FRAME_LIMIT3];												//ジャンプテクスチャ
	CTexture	*mShadowTex;											//影テクスチャチャ
	CTexture    *mCutFlyTex;												//斬撃横
	CTexture	*mCutJumpTex;											//斬撃ジャンプ

	CLoadPlayer();
	~CLoadPlayer();

};

