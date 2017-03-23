/*
Enemy00 テクスチャLood(時間があればまとめます)クラス
担当者 冨田健斗
*/

#include "../Graphic/CTexture.h"
#include "../Define/define.h"

class CLoadEnemy00
{
private:
	static CLoadEnemy00 *mLoadEnemy00;
	CLoadEnemy00();
	~CLoadEnemy00();
public:
	static CLoadEnemy00 *GetInstance(); //GetInstance

	CTexture	*mStay_tex[FRAME_LIMIT];
	CTexture	*mWalk_tex[FRAME_LIMIT];
	CTexture	*mAttack_tex[FRAME_LIMIT];
	CTexture	*mDie_tex[FRAME_LIMIT];

};
