#include "../Graphic/CTexture.h"
#include "../Define/define.h"

class CLoadEnemy00
{
private:
	static CLoadEnemy00 *mLoadEnemy00;
public:
	static CLoadEnemy00 *GetInstance(); //GetInstance

	CTexture	*mStay_tex[FRAME_LIMIT];
	CTexture	*mWalk_tex[FRAME_LIMIT];
	CTexture	*mAttack_tex[FRAME_LIMIT];
	CTexture	*mDie_tex[FRAME_LIMIT];

	CLoadEnemy00();
	~CLoadEnemy00();

};
