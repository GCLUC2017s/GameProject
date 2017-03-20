/*
*�G�l�~�[�̃v���O����
*�S���� �y�c���l&�����O��
*/
#ifndef CENEMY01_HPP
#define CENEMY01_HPP
#include "../Base/CBase.h"
#include "../Task/CTaskManager.h"
#include "../Graphic/CRectangle.h"
#include "../Task/CTaskManager.h"
#include "../Define/define.h"

#define FLAME_LIMIT 6 //�t���[�����̏��


const	 CVector2 Enemy01_first_pos
= CVector2(character_limit_left*0.55, (character_limit_top + character_limit_bottom) / 2);	//�G�l�~�[�̏����ʒu
//���݂̓}�b�v���̂̍��[�����Ĕz�u���Ă���B

class  CEnemy01 : public CBase
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
		E_FLY_L, E_FLY_R,
		E_RUN_L, E_RUN_R,
		E_ATTACK_L, E_ATTACK_R,
		E_DIE_L, E_DIE_R
	};
	//const int mStatus;

	int mFlameCount;		//�t���[�����J�E���g�p
	int direction;	//���E�̊ȈՔ��f
	float rulerR; //�G�l�~�[�ƃL�����N�^�[�̋���
	float rulerL; 
	bool actionflag;
	int motion;
	int pattern;
	void Fly();
	void SetPos();
	void AnimeScene();

public:
	CEnemy01();
	~CEnemy01();
	void Init();
	void Render();
	void Update();

};

#endif