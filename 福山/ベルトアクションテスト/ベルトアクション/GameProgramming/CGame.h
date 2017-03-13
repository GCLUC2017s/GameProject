#pragma once
#include "define.h"
#include "CVector2.h"
#include "CRectangle.h"

class CGame {
public:
	static int *mpMapData;	//�}�b�v�f�[�^
	static int mMapRows;	//�}�b�v�̍s��
	static int mMapCols;	//�}�b�v�̗�
	static int mDispRows;	//�\������s��
	static int mDispCols;	//�\�������
	static CRectangle *mpMap;	//Map�̎l�p�`�f�[�^
	static int status;

	/* getIndex
	v:���W��̈ʒu
	return:�}�b�v�f�[�^�z��̓Y����
	���W��̈ʒu����}�b�v�f�[�^�̓Y������Ԃ�
	*/
	static int getIndex(const CVector2 &v);
	/* getPosition
	index:�}�b�v�f�[�^�z��̓Y����
	return:���W��̈ʒu
	�}�b�v�f�[�^�̓Y��������A���W��̈ʒu��Ԃ�
	*/
	static CVector2 getPosition(int index);
	/* getPosition
	row:�}�b�v�f�[�^�ł̍s(0�`)
	col:�}�b�v�f�[�^�ł̗�(0�`)
	return:���W��̈ʒu
	�}�b�v�f�[�^��ł̍s�Ɨ񂩂�A���W��̈ʒu��Ԃ�
	*/
	static CVector2 getPosition(int row, int col);

	static bool collision(CRectangle &rec, CVector2 &forward, CVector2 *rtn);
};