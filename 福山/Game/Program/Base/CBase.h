#ifndef BASE_HPP
#define BASE_HPP
#define SIZE_PLAYER_Y 1  //�v���C���[�̃T�C�Y_Y
#define SIZE_PLAYER_X 0.5 //�v���C���[�̃T�C�Y_X
#define SIZE_SHADOW_X 0.4 //�e�̃T�C�YX
#define SIZE_SHADOW_Y 0.4 //�e�̃T�C�YY
#include "../Task/CTask.h"
#include "../Vector/CVector2.h"
#include "../Define/define.h"

const float character_limit_left = -MAP_LIMIT_X / 2;			//�i�߂���(��)
const float character_limit_top = MAP_LIMIT_Y / 4;			   //�i�߂���(��)
const float character_limit_right = MAP_LIMIT_X / 2;		 //�i�߂���(�E)
const float character_limit_bottom = -MAP_LIMIT_Y / 2;		//�i�߂���(��)




/*
�g����

CTask�ɂ��鏑���Ă���

int mPriorityR; //Rander()�̃i���o�[
int mPriorityU;//Update()�̃i���o�[

CBase ���p��������̂ɂ͕K������邱��
���������������̂ق�

*/


class CBase : public CTask{
public:
	CVector2 mPos;		//�ʒu
	CVector2 mForward;	//����
	float mAxis;			//���@�g�����@mPos��'Y'��������(�W�����v�̎��ȂǁC�ړ��ȊO��'Y'�͑�����Ȃ�)
	bool mEnabled;		//�L���t���O
	CBase *mpPlayer;
	float mHitPoint; //�q�b�g�|�C���g

	int mAlertCnt;

	CBase() : mEnabled(true), mpPlayer(0), mAlertCnt(0),mAxis(0),mHitPoint(0) {

	}
	virtual void Collision(CBase *b1, CBase *b2) {}


	
};
#endif
