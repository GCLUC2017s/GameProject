#include "../Base\CBase.h"
#include"../Task/CTaskManager.h"
#include <time.h>
/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照
void CBase::AnimeFrame(bool roop, int speed){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;

		}
		if (mAnimeFrame >= FRAME_LIMIT|| mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
	}
	else{
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT){
			mAnimeFrame = FRAME_LIMIT - 1; //テクスチャの最大値 = FRAME_LIMITなので ー１
		}
	}

	mSaveAnime = mStatus;
}
void CBase::LimitDisp(int sizex, int sizey){
	/*あたり判定*/
	if (mAxis > character_limit_top - sizey && !mEnabledJump){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = character_limit_top;
		mAxis = mPos.y - sizey; //軸をもとに戻す
	}
	if (mAxis + sizey < character_limit_bottom + sizey && !mEnabledJump){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = character_limit_bottom + sizey;
		mAxis = mPos.y - sizey; //軸をもとに戻す
	}

	if (mPos.x >= character_limit_right - sizex || mPos.x <= character_limit_left + sizex){ //マップ外に出ると元の位置に戻す(X)
		mPos.x = mRect.position.x;
	}
	/*あたり判定終了*/
}

/*
攻撃範囲を決める
ベースにある変数を使う 
float Forwordは現在の向きを入れる
0以上　が　右
0未満　が  左
float x , y , mAxis は攻撃範囲 ,Cvector2は　自分のposを入れる

*/

void CBase::Attack(float Forword, float x, float y, float Axis, CVector2 &mPos){
	mAttackRange.SetVertex(-x, y, x, -y);
	mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f); //デバッグ用
	if (Forword > 0)mAttackRange.position = CVector2(mPos.x + 1 + x, mPos.y);
	if (Forword <= 0)mAttackRange.position = CVector2(mPos.x - 1 - x, mPos.y);
	mAttackAxis = Axis;
}
/*時間計算用
使い方　
float 時間で猶予の時間を書く
trueの場合

falseの場合

if文として使う

（例）
if(FrameTime(時間)){			//猶予の時間を書く
	if(キー入力された場合){
	攻撃Bに移行
	}
}else{							//時間が来てしまった場合
	待ちアニメに移行
}

*/


bool CBase::FrameTime(float t){
	if (t > mFrameTime){
		mFrameTime += 1;
		return true;
	}
	else{
		mFrameTime = 0;
		return false;
	}
	
}
/*シングルか判断*/
bool SinglePos(CVector2 pos){
	CTask *t;
	t = CTaskManager::GetInstance()->mRoot;

	while (t != 0){
		CBase *b = (CBase*)t;
		if (b->mCharaFlag && pos.x == b->mPos.x && pos.y == b->mPos.y){ //ポスが同じ場合
			return false;						//シングル×
		}
		t = t->next;
	}
	if (t == 0){ //ここまででシングルだった場合
		return true;			//シングル○
	}
	return false;
}

/*
[使い方]
ランダムでポジションを決める
サイズx,サイズy,&自分のポジション
*/
void CBase::RandPos(int x,int y,CVector2 *mPos){
	while (true)
	{
		mPos->x = (rand()-rand())%(int)(character_limit_left+character_limit_right)/2;
		mPos->y = (rand() - rand())%(int)(character_limit_top + character_limit_bottom) / 2;
		mAxis = mPos->y - y;
		LimitDisp(mPos->x, mPos->y);
		if (SinglePos(*mPos)){ 
			break;
		}
	}
}
int CBase::kazu = 0;