/*
Enemy01テクスチャLood(時間があればまとめます)クラス
担当者 冨田健斗
*/

#include "../Graphic/CTexture.h"
#include"../Define/define.h"

#define FRAME_LIMIT11 11//現在フレーム数がばらけているのでコメントDIE　
#define FRAME_LIMIT9 9	//フレーム数9のもの　アタック


class CLoadEnemy01
{
private:

	static CLoadEnemy01 *mLoadEnemy01;
	CLoadEnemy01();
	~CLoadEnemy01();
public:

	static CLoadEnemy01 *GetInstance(); //GetInstance
	CTexture	*mStay_tex[FRAME_LIMIT];
	CTexture	*mFly_tex[FRAME_LIMIT];
	CTexture	*mAttack_tex[FRAME_LIMIT9];
	CTexture	*mDie_tex[FRAME_LIMIT11];

};


