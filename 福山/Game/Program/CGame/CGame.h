#ifndef GAME_HPP
#define GAME_HPP
#include "../Define/define.h"
#include "../Vector/CVector2.h"
#include "../Graphic/CRectangle.h"

class CGame {
public:
	static int *mpMapData;	//�}�b�v�f�[�^
	static int mMapRows;	//�}�b�v�̍s��
	static int mMapCols;	//�}�b�v�̗�
	static int mDispRows;	//�\������s��
	static int mDispCols;	//�\�������
	static CRectangle *mpMap;	//Map�̎l�p�`�f�[�^
	static CRectangle *mEnemy;	//
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
	static CVector2 getPosition(CVector2 &v);
};

#endif