#ifndef BASE_HPP
#define BASE_HPP
#include "CTask.h"
#include "CTexture.h"
#include "CRectangle.h"
#include "CVector2.h"


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
	CVector2 mRot;		//��]
	CVector2 mForward;	//����
	float mAxis;			//���@�g�����@mPos��'Y'��������(�W�����v�̎��ȂǁC�ړ��ȊO��'Y'�͑�����Ȃ�)
	bool mEnabled;		//�L���t���O
	CBase *mpPlayer;
	float mHitPoint; //�q�b�g�|�C���g

	int mAlertCnt;

	CBase() : mEnabled(true), mpPlayer(0), mAlertCnt(0),mAxis(0),mHitPoint(0) {}
	virtual void Collision(CBase *b1, CBase *b2) {}

	
};
#endif
