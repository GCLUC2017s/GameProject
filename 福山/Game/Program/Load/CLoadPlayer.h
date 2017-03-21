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

	CTexture	*mStayTex[FRAME_LIMIT];									//�҂��e�N�X�`��
	CTexture	*mWalkTex[FRAME_LIMIT8];									//�����e�N�X�`��
	CTexture	*mRunTex[FRAME_LIMIT8];									//����e�N�X�`��
	CTexture	*mNormalAttackTex[NORMALATTACK_PATTERN][FRAME_LIMIT];	//�ʏ�U���e�N�X�`��
	CTexture	*mEatTex[FRAME_EAT];									//�ߐH�e�N�X�`��
	CTexture	*mEx01Tex[FRAME_LIMIT];									//�K�E�Z(����)�e�N�X�`��									
	CTexture	*mEx02Tex[FRAME_LIMIT];									//�K�E�Z(�p��)�e�N�X�`��
	CTexture	*mFlameTex[FRAME_LIMIT];								//���e�N�X�`��
	CTexture	*mBrakeTex[FRAME_LIMIT];								//�u���[�L�e�N�X�`��
	CTexture	*mJumpTex[FRAME_JUMP];												//�W�����v�e�N�X�`��
	CTexture	*mShadowTex;											//�e�e�N�X�`���`��
	CTexture    *mCutFlyTex;												//��Ԏa��

	CLoadPlayer();
	~CLoadPlayer();

};

