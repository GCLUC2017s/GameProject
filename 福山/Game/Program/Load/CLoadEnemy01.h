/*
Enemy01�e�N�X�`��Lood(���Ԃ�����΂܂Ƃ߂܂�)�N���X
�S���� �y�c���l
*/

#include "../Graphic/CTexture.h"
#include"../Define/define.h"

#define FRAME_LIMIT11 11//���݃t���[�������΂炯�Ă���̂ŃR�����gDIE�@
#define FRAME_LIMIT9 9	//�t���[����9�̂��́@�A�^�b�N


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


