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

const	 CVector2 Enemy00_first_pos
= CVector2(character_limit_left*0.55, (character_limit_top + character_limit_bottom) / 2);	//�G�l�~�[�̏����ʒu
//���݂̓}�b�v���̂̍��[�����Ĕz�u���Ă���B

class  CEnemy00 : public CBase
{
private:

	float mVelocity;//�ړ�����Ƃ��Ɏg��

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
		E_DIE_L, E_DIE_R,
		E_LEFT,E_RIGHT
	};

	//const int mStatus;
	int mAnimePattern;				//�S�̂̃A�j���[�V�����p�^�[��
	int mSaveAnime; //���O�̃A�j�����������f�p
	int mFrameCount;		//�t���[�����J�E���g�p

	CVector2 mSavePos;//�������ʒu�̕ۑ�

	int direction;	//���E�̊ȈՔ��f

	float rulerR; //�G�l�~�[�ƃL�����N�^�[�̋���
	float rulerL; //�G�l�~�[�ƃL�����N�^�[�̋���
	float upruler; //�G�l�~�[�ƃL�����N�^�[�̋���
	float downruler; //�G�l�~�[�ƃL�����N�^�[�̋���



	bool actionflag; //�A�N�V���������Ă��鎞�͗��Ă�

	float getAxis;	//�v���C���[�̐ڒn�_�擾�p
	float downAxis;//�����ړ��p
	float upAxis;	//�㎲�ړ��p

	
	float escapetime;//��������
	float attacktime;//�U������
	float delay;	//�f�B���C

	int pattern;	//�p�^�[���̌��胉���_���Ŏg�p
	
	int motion;		//���[�V�����̎��


	void Walk();
	void AnimeScene();
	void Motion();

public:
	CEnemy00();
	~CEnemy00();
	void Init();
	void Render();
	void Update();

};

#endif
