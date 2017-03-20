/*
*�{�X�G�l�~�[�̃v���O����
*�S���� �y�c���l&�����O��
*/
#ifndef CBOSS_HPP
#define CBOSS_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"


#define FLAME_LIMIT 6 //�t���[�����̏��

const	 CVector2 Boss_first_pos
= CVector2(character_limit_left*0.55, (character_limit_top + character_limit_bottom) / 2);	//�{�X�G�l�~�[�̏����ʒu

class  CBoss : public CBase
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
		E_HATTACK_L, E_HATTACK_R,
		E_DIE_L, E_DIE_R
	};

	int AnimePattern;
	int mSaveAnime; //���O�̃A�j�����������f�p
	int mFlameCount;		//�t���[�����J�E���g�p
	int mAnime;		//�A�j���[�V�����̃t���[����
	
	int direction;//���E����

	float rulerR; //�G�l�~�[�ƃL�����N�^�[�̋���
	float rulerL; //�G�l�~�[�ƃL�����N�^�[�̋���

	int motion;
	bool actionflag;
	
	int pattern;//�����_���p

	void Walk();
	void AnimeScene();
	void SetPos();

public:
	CBoss();
	~CBoss();
	void Init();
	void Render();
	void Update();

};

#endif