#ifndef CENEMYBASETEST_HPP
#define CENEMYBASETEST_HPP

#include "../Base/CBase.h"
#include "../CGame/CGame.h"

#define LEFT_PTT	(mTargetP.x<mPos.x)	//�^�[�Q�b�g�����ɂ���
#define RIGHT_PTT	(mTargetP.x>mPos.x)	//�^�[�Q�b�g���E�ɂ���
#define UP_PTT		(mTargetP.y<mPos.y)	//�^�[�Q�b�g����ɂ���
#define DOWN_PTT	(mTargetP.y>mPos.y)	//�^�[�Q�b�g�����ɂ���


#define ATTACK_PTT   (rulerR <2||rulerL <2)  // �^�[�Q�b�g�Ƃ̋��������l�ȉ��̎��ɍU��������B

#define HATTACK_PTT  (rulerR<4||rulerR<4)

#define ENEMY_VISI   (rulerR <6||rulerL <6)  // �G�l�~�[�̎��E���U�ɐݒ�B
#define ENEMY_ESCAPE   (rulerR >5||rulerL >5)  //��苗���߂Â������ɓ����鋗��
#define DOWNAXIS	(getAxis-2)
#define UPAXIS		(getAxis+2)
#define NO_ATTACK_PTT   (rulerR >3 || rulerL >3)  // �^�[�Q�b�g�������蔻��O�̎��̔���

	/*�ϐ����ω�����ꍇ�͂�����Ŕ��f*/
	enum EMotion{
		EM_STAY, EM_WALK,
		EM_RANGE, EM_DIE,
		EM_BACK_X, EM_BACK_Y,EM_MOVE_AT = 5,
		EM_ATTCK, EM_HIGH_AT,
		EM_LOW_AT

	};
#endif