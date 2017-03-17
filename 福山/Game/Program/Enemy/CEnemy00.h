/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l&�����O��
*/
#ifndef CENEMY00_HPP
#define CENEMY00_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"
#include"../Player/CPlayer.h"

#define FLAME_LIMIT 6 //�t���[�����̏��


#define LEFT_PTT	mTargetP.x<mPos.x	//�^�[�Q�b�g�����ɂ���
#define RIGHT_PTT	mTargetP.x>mPos.x	//�^�[�Q�b�g���E�ɂ���
#define UP_PTT		mTargetP.y<mPos.y&&mAxis < character_limit_top - SIZE_ENEMY00_Y	//�^�[�Q�b�g����ɂ���
#define DOWN_PTT	mTargetP.y>mPos.y&& mAxis > character_limit_bottom + SIZE_ENEMY00_Y	//�^�[�Q�b�g�����ɂ���
#define ATTACK_PTT   rulerR <3||rulerL <3  // �^�[�Q�b�g�����ɂ��鎞�̓����蔻��
#define NO_ATTACK_PTT   rulerR >3 || rulerL >3  // �^�[�Q�b�g�����ɂ��鎞�̓����蔻��

const	 CVector2 Enemy00_first_pos
= CVector2(character_limit_left*0.55,
		  (character_limit_top + character_limit_bottom) / 2);	//�G�l�~�[�̏����ʒu
//���݂̓}�b�v���̂̍��[�����Ĕz�u���Ă���B

class  CEnemy00 : public CBase
{
private:

	float mVelocity;//�ړ�����Ƃ��Ɏg��

	CTexture	*mStay_tex[FLAME_LIMIT];
	CTexture	*mWalk_tex[FLAME_LIMIT];
	CTexture	*mAttack_tex[FLAME_LIMIT];
	CTexture	*mDie_tex[FLAME_LIMIT];

	/*
	�������ǂ̃A�j���[�V���������f�p
	enum��
	*/
	enum MyEnum
	{
		E_STAY_L, E_STAY_R,
		E_WALK_L, E_WALK_R,
		E_RUN_L, E_RUN_R,
		E_ATTACK_L, E_ATTACK_R,
		E_DIE_L, E_DIE_R
	};
	//const int mStatus;
	MyEnum eAnime = E_STAY_L;
	int AnimePattern;				//�S�̂̃A�j���[�V�����p�^�[��
	int mSaveAnime; //���O�̃A�j�����������f�p
	int mFlameCount;		//�t���[�����J�E���g�p
	int mAnime;		//�A�j���[�V�����̃t���[����
	CVector2 mSuvePos;//�������ʒu�̕ۑ�

	int direction;	

	float rulerR; //�G�l�~�[�ƃL�����N�^�[�̋���
	float rulerL; //�G�l�~�[�ƃL�����N�^�[�̋���

	float npNum;
	float npNum2;

	int motion;
	
	void Walk(){};
	void AnimeFlame();
	void SetPos();

public:
	CEnemy00();
	~CEnemy00();
	void Init();
	void Render();
	void Update();

};

#endif