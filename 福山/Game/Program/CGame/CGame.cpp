#include "CGame.h"

int *CGame::mpMapData = 0;	//�}�b�v�̃f�[�^
int CGame::mMapRows = 0;	//�}�b�v�̍s��
int CGame::mMapCols = 0;	//�}�b�v�̗�
int CGame::mDispRows = 0;	//�\������s��
int CGame::mDispCols = 0;	//�\�������
int CGame::status = 0;		//�Q�[���S�̂̃X�e�[�^�X
CRectangle *CGame::mpMap;

/* getPosition
i:�}�b�v�f�[�^�z��̓Y��
return:���W��̈ʒu
�}�b�v�f�[�^�z��̓Y������A���W��̈ʒu��Ԃ�
*/
CVector2 CGame::getPosition(CVector2 &v) {
	return v;
}
