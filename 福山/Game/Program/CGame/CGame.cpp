#include "CGame.h"

int *CGame::mpMapData = 0;	//�}�b�v�̃f�[�^
int CGame::mMapRows = 0;	//�}�b�v�̍s��
int CGame::mMapCols = 0;	//�}�b�v�̗�
int CGame::mDispRows = 0;	//�\������s��
int CGame::mDispCols = 0;	//�\�������
int CGame::status = 0;		//�Q�[���S�̂̃X�e�[�^�X
CPlayer *CGame::mPlayer;

/* getPosition
i:�}�b�v�f�[�^�z��̓Y��
return:���W��̈ʒu
�}�b�v�f�[�^�z��̓Y������A���W��̈ʒu��Ԃ�
*/
CVector2 CGame::getPosition(const CVector2 &v) {
	return v;
}
CEnemy00 CGame::getEnemy(CEnemy00 &ene00){
	return ene00;
}
