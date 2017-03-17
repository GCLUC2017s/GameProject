#include "CGame.h"
#include "../Task/CTaskManager.h"


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


CTask *CGame::getStatus(int number){
	CTask *t;
	t = CTaskManager::GetInstance()->mRoot;
	while (t != 0){
		if (t->mMyNumber == number){
			return t;
		}
		t = t->next;
	}
}