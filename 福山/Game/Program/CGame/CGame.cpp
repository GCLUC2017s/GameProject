#include "CGame.h"
#include "../Task/CTaskManager.h"


/* getPosition
i:マップデータ配列の添字
return:座標上の位置
マップデータ配列の添字から、座標上の位置を返す
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