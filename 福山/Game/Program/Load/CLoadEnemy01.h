#include "../Graphic/CTexture.h"
#include"../Define/define.h"


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
	CTexture	*mAttack_tex[FRAME_LIMIT];
	CTexture	*mDie_tex[FRAME_LIMIT];


};


