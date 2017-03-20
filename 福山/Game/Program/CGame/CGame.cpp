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


CVector2 CGame::CameraPos(){
	const float arealeft_x = character_limit_left + SIZE_PLAYER_X * 2;
	const float arearight_x = character_limit_right - (DISP_X / 2) - SIZE_PLAYER_X * 4;
	//表示するエリアを指定
	if (arealeft_x <= CPlayer::camera_x&& arearight_x >= CPlayer::camera_x){
		return CVector2(CPlayer::camera_x, 0);
	}
	else if (arealeft_x > CPlayer::camera_x){
		return CVector2(arealeft_x, 0);
	}
	else{
		return CVector2(arearight_x, 0);

	}
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

CVector2 CGame::mGetPlayerPos() {
	CTask *t;
	t = CTaskManager::GetInstance()->mRoot;

	while (t != 0){
		if (t->mMyNumber == E_PLAYER){
			CPlayer *p;
			p = (CPlayer*)t;
			return p->mPos;
		}
		t = t->next;
	}
}

void CGame::Delete(CTexture **t){
	if (*t){
		delete *t;
		*t = 0;
	}
}

float CGame::GetPlayerAxis(){
	CTask *t;
	t = CTaskManager::GetInstance()->mRoot;

	while (t != 0){
		if (t->mMyNumber == E_PLAYER){
			CPlayer *p;
			p = (CPlayer*)t;
			return p->mAxis;
		}
		t = t->next;
	}
}

/*フェード関数*/
void CGame::Fade(float speed,CRectangle *rect){
	float mFade4 = rect->triangle1.a + speed;		//フェード関数で使う
	mFade4 += speed;
	if (mFade4 >= 1.0f){
		mFade4 = 1.0f;
	}
	rect->SetColor(1.0f, 1.0f, 1.0f, mFade4);
}
