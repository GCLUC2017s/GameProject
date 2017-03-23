/*
�v���C���[�e�N�X�`��Lood(���Ԃ�����΂܂Ƃ߂܂�)�N���X
�S���� �y�c���l
*/

#include "../Graphic/CTexture.h"
#include "../Define/define.h"
#define FRAME_LIMIT8 8//�t���[�������Ⴄ�悤�ɂȂ����̂Œ��� 8�̂��� (����)walk run Ex01
#define FRAME_LIMIT3 3//�t���[�������Ⴄ�悤�ɂȂ����̂Œ��� 3�̂��� (����)Eat Jump
#define FRAME_LIMIT2 2//�t���[�������Ⴄ�悤�ɂȂ����̂Œ��� 2�̂��� (����)break

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
	CTexture	*mJumpAttackTex[FRAME_LIMIT];

	CTexture	*mEatTex[FRAME_LIMIT3];									//�ߐH�e�N�X�`��
	CTexture	*mEx01Tex[FRAME_LIMIT8];									//�K�E�Z(����)�e�N�X�`��									

	CTexture	*mEx02Tex[FRAME_LIMIT];									//�K�E�Z(�p��)�e�N�X�`��
	CTexture	*mFlameTex[FRAME_LIMIT];								//���e�N�X�`��
	CTexture	*mBrakeTex[FRAME_LIMIT];								//�u���[�L�e�N�X�`��
	CTexture	*mJumpTex[FRAME_LIMIT3];												//�W�����v�e�N�X�`��
	CTexture	*mShadowTex;											//�e�e�N�X�`���`��
	CTexture    *mCutFlyTex;												//�a����
	CTexture	*mCutJumpTex;											//�a���W�����v

	CLoadPlayer();
	~CLoadPlayer();

};

