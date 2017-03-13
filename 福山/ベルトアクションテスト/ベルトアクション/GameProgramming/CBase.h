#pragma once

#include "CVector2.h"

class CBase {
public:
	CVector2 mPos;		//�ʒu
	float axis;			//���@�g�����@mPos��'Y'��������(�W�����v�̎��ȂǁC�ړ��ȊO��'Y'�͑�����Ȃ�)

	CVector2 mRot;		//��]
	
	CVector2 mForward;	//����


	bool mEnabled;		//�L���t���O
	CBase *mpPlayer;

	int mAlertCnt;

	CBase() : mEnabled(true), mpPlayer(0), mAlertCnt(0) {}
	virtual void init() {}
	virtual void update() {}
	virtual void render() {}
	virtual void collision(CBase *b1, CBase *b2) {}

	/* setPos(int row, int col)
	row:�s�̎w��
	col:��̎w��
	�s�Ɨ񂩂���W��̍��W��ݒ肵�A�ړ��������ݒ肷��
	*/
	virtual void setPos(int row, int col);
	/* setPos(int row, int col, CVector2 fwd)
	row:�s�̎w��
	col:��̎w��
	fwd:�ړ������i���K�����ꂽ�x�N�g���j
	�s�Ɨ񂩂���W��̍��W��ݒ肵�A�ړ�������ݒ肷��
	*/
	virtual void setPos(int row, int col, CVector2 fwd);
};
