#include "CBase.h"
#include "CGame.h"

/* setPos(int row, int col, CVector2 fwd)
row:�s�̎w��
col:��̎w��
fwd:�ړ������i���K�����ꂽ�x�N�g���j
�s�Ɨ񂩂���W��̍��W��ݒ肵�A�ړ�������ݒ肷��
*/
void CBase::setPos(int row, int col) {
	setPos(row, col, CVector2(0.0f, 1.0f));
}
/* setPos(int row, int col, CVector2 fwd)
row:�s�̎w��
col:��̎w��
fwd:�ړ������i���K�����ꂽ�x�N�g���j
�s�Ɨ񂩂���W��̍��W��ݒ肵�A�ړ�������ݒ肷��
*/
void CBase::setPos(int row, int col, CVector2 fwd) {
	//�s�Ɨ񂩂���W��̈ʒu��ݒ肷��
	mPos = CGame::getPosition(row, col);
	//�ړ������ݒ�
	mForward = fwd;
}
