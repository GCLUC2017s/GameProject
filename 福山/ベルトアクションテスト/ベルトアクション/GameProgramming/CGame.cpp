#include "CGame.h"
#include "CCollision.h"

int *CGame::mpMapData = 0;	//�}�b�v�̃f�[�^
int CGame::mMapRows = 0;	//�}�b�v�̍s��
int CGame::mMapCols = 0;	//�}�b�v�̗�
int CGame::mDispRows = 0;	//�\������s��
int CGame::mDispCols = 0;	//�\�������
int CGame::status = 0;		//�Q�[���S�̂̃X�e�[�^�X
CRectangle *CGame::mpMap;


/* getIndex
v:���W��̈ʒu
return:�}�b�v�f�[�^�z��̓Y��
���W��̈ʒu�ɊY������}�b�v�f�[�^�z��̓Y����Ԃ�
*/
int CGame::getIndex(const CVector2 &v) {
	int col = v.x + CGame::mMapCols / 2.0f;
	int row = (v.y + 0.5f - CGame::mMapRows / 2.0f) * -1.0f + 0.5f;
	return row * CGame::mMapCols + col;
}
/* getPosition
i:�}�b�v�f�[�^�z��̓Y��
return:���W��̈ʒu
�}�b�v�f�[�^�z��̓Y������A���W��̈ʒu��Ԃ�
*/
CVector2 CGame::getPosition(int i) {
	return CVector2(
		i % CGame::mMapCols - CGame::mMapCols / 2.0f + 0.5f,
		-i / CGame::mMapCols + CGame::mMapRows / 2.0f - 0.5f);
}
/* getPosition
row:�}�b�v�f�[�^�ł̍s(0�`)
col:�}�b�v�f�[�^�ł̗�(0�`)
return:���W��̈ʒu
�}�b�v�f�[�^��ł̍s�Ɨ񂩂�A���W��̈ʒu��Ԃ�
*/
CVector2 CGame::getPosition(int row, int col) {
	return CVector2(
		col - CGame::mMapCols / 2.0f + 0.5f,
		-row + CGame::mMapRows / 2.0f - 0.5f);
}

/*
����(fwd)�ֈړ������l�p�`(rec)���A��Q���ɏՓ˂��Ă���ꍇ�A
�߂���(rtn)��ݒ肵true��߂��B
*/
bool CGame::collision(CRectangle &rec, CVector2 &fwd, CVector2 *rtn) {
	int index = CGame::getIndex(rec.position);
	//�E�ֈړ�
	if (fwd.x > 0.0f) {
		if (CGame::mpMapData[index + 1 - MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index + 1 - MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + 1] != 0 && CCollision::collision(rec, CGame::mpMap[index + 1], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + 1 + MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index + 1 + MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
	}
	//���ֈړ�
	if (fwd.x < 0.0f) {
		if (CGame::mpMapData[index - 1 - MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index - 1 - MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - 1] != 0 && CCollision::collision(rec, CGame::mpMap[index - 1], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - 1 + MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index - 1 + MAP_COLS], rtn)) {
			rtn->y = 0.0f;
			return true;
		}
	}
	//��Ɉړ�
	if (fwd.y > 0.0f) {
		if (CGame::mpMapData[index - MAP_COLS - 1] != 0 && CCollision::collision(rec, CGame::mpMap[index - MAP_COLS - 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index - MAP_COLS], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index - MAP_COLS + 1] != 0 && CCollision::collision(rec, CGame::mpMap[index - MAP_COLS + 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
	}
	//���ֈړ�
	if (fwd.y < 0.0f) {
		if (CGame::mpMapData[index + MAP_COLS - 1] != 0 && CCollision::collision(rec, CGame::mpMap[index + MAP_COLS - 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + MAP_COLS] != 0 && CCollision::collision(rec, CGame::mpMap[index + MAP_COLS], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
		if (CGame::mpMapData[index + MAP_COLS + 1] != 0 && CCollision::collision(rec, CGame::mpMap[index + MAP_COLS + 1], rtn)) {
			rtn->x = 0.0f;
			return true;
		}
	}
	return false;
}
