#include "../Graphic/CTexture.h"
#include "../Define/define.h"
#define FRAME_LIMIT8 8
#define FRAME_JUMP 3
#define FRAME_EAT 3  
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
	CTexture	*mEatTex[FRAME_EAT];									//捕食テクスチャ
	CTexture	*mEx01Tex[FRAME_LIMIT];									//必殺技(消費)テクスチャ									
	CTexture	*mEx02Tex[FRAME_LIMIT];									//必殺技(継続)テクスチャ
	CTexture	*mFlameTex[FRAME_LIMIT];								//炎テクスチャ
	CTexture	*mBrakeTex[FRAME_LIMIT];								//ブレーキテクスチャ
	CTexture	*mJumpTex[FRAME_JUMP];												//ジャンプテクスチャ
	CTexture	*mShadowTex;											//影テクスチャチャ
	CTexture    *mCutFlyTex;												//飛ぶ斬撃

	CLoadPlayer();
	~CLoadPlayer();

};

