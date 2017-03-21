#include "../Graphic/CTexture.h"
#include "../Define/define.h"

class CLoadBoss
{
private:
	static CLoadBoss *mLoadBoss;
	CLoadBoss();
	~CLoadBoss();
public:
	static CLoadBoss *GetInstance(); //GetInstance

	CTexture	*mStay_tex[FRAME_LIMIT];
	CTexture	*mWalk_tex[FRAME_LIMIT];
	CTexture	*mAttack_tex[FRAME_LIMIT];
	CTexture	*mHattack_tex[FRAME_LIMIT];
	CTexture	*mDie_tex[FRAME_LIMIT];



};

