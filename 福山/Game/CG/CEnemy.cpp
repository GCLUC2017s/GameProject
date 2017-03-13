#include "CEnemy.h"

CEnemy::CEnemy(){
	
		mPriorityR = E_ENEMY;	//Renderの順番の番号
		mPriorityU = E_ENEMY;	//Updateの順番の番号
		mMyNumber = E_ENEMY;	//属性の設定
		mHitPoint = E_ENEMY;	//エネミーのヒットポイント

}

void CEnemy::Update(){}
void CEnemy::Render(){}
