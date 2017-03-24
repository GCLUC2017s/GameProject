#ifndef CENEMYBASETEST_HPP
#define CENEMYBASETEST_HPP

#include "../Base/CBase.h"
#include "../CGame/CGame.h"

#define LEFT_PTT	(mTargetP.x<mPos.x)	//�^�[�Q�b�g�����ɂ���
#define RIGHT_PTT	(mTargetP.x>mPos.x)	//�^�[�Q�b�g���E�ɂ���
#define UP_PTT		(getAxis>mPos.y)	//�^�[�Q�b�g����ɂ���
#define DOWN_PTT	(getAxis<mPos.y)	//�^�[�Q�b�g�����ɂ���


#define ATTACK_PTTX   (rulerR <1.0f||rulerL <1.0f)  // �^�[�Q�b�g�Ƃ̋��������l�ȉ��̎��ɍU������ɕύX������B
#define ATTACK_BOSS   (rulerR <4||rulerL <4)  // �^�[�Q�b�g�Ƃ̋��������l�ȉ��̎��ɍU�����[�V�����ɕύX����B
#define ATTACK_PTTY   (upruler<0.5f||downruler<0.5f)  // Y���̍U������B
#define ATTACK_BOSS_Y   (upruler<2.1f||downruler<2.0f)  // Y���̍U������

#define ATTACK_PTT01_Y   (upruler<0.5f||downruler<1.0f)  // Y���̍U������B
#define HATTACK_PTT  (rulerR<4||rulerR<4)

#define ENEMY_VISI   (rulerR <6||rulerL <6)  // �G�l�~�[�̎��E���U�ɐݒ�B

#define ENEMY_ESCAPE   (rulerR >3||rulerL >3)  //��苗���߂Â������ɓ����鋗��
#define BOSS_ESCAPE   (rulerR >5||rulerL >5)  //��苗���߂Â������ɓ����鋗��

#define NO_ATTACK_PTTX   (rulerR >1.5f || rulerL >1.5f)  // �^�[�Q�b�g�������蔻��O�̎��̔���
#define NO_ATTACK_BOSS   (rulerR >4 || rulerL >4) 
#define RUSH_BOSS   (rulerR >2 || rulerL >2) //�{�X�̃��b�V���U���B�͈͊O�Ȃ烉�b�V���B

#define NO_ATTACK_PTTY   (upruler>1||downruler>1)  // Y���̍U������B

#define ENEMY_LIVE (mHitPoint>0)


#define ESCAPE_TIME			 (float) 2 
#define ESCAPE_TIME_BOSS		 (float) 1
#define ENEMY00_INTERVAL (float) 1 //�C���^�[�o�����P�b�ɐݒ�B
#define ENEMY00_DELAY (float) 1 //�C���^�[�o�����P�b�ɐݒ�B
#define ENEMY01_INTERVAL (float) 1
#define BOSS_INTERVAL	 (float) 1

	/*�ϐ����ω�����ꍇ�͂�����Ŕ��f*/
	enum EMotion{
		EM_STAY, EM_WALK,
		EM_RANGE, EM_DIE,
		EM_BACK_X, EM_BACK_Y,EM_MOVE_AT = 5,
		EM_ATTACK, EM_HIGH_AT,
		EM_LOW_AT,EM_BACK_UP,
		EM_UP,EM_DOWN,
		EM_Slanting
	};
#endif