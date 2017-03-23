#ifndef CLOWBOSS_HPP
#define CLOWBOSS_HPP


#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"


const	 CVector2 LowBoss_first_pos
= CVector2(character_limit_right*0.7f, (character_limit_top + character_limit_bottom) / 2);	//���{�X�̏����ʒu

class  CLowBoss : public CBase
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
		E_LEFT, E_RIGHT
	};

	int AnimePattern;
	int mSaveAnime; //���O�̃A�j�����������f�p
	int mFrameCount;		//�t���[�����J�E���g�p

	int direction;//���E����

	float rulerR; //�G�l�~�[�ƃL�����N�^�[�̋���
	float rulerL; //�G�l�~�[�ƃL�����N�^�[�̋���
	float upruler;
	float downruler;
	float getAxis;
	int motion;
	bool actionflag;

	int pattern;//�����_���p

	void Motion();
	void Walk();
	void AnimeScene();
	void SetPos();

public:
	CLowBoss();
	~CLowBoss();
	void Init();
	void Render();
	void Update();
};
#endif