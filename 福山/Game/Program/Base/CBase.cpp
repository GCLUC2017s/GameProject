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

void CBase::AnimeFrame(bool roop, int speed,int frame){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;

		}
		if (mAnimeFrame >= frame || mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
	}
	else{
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= frame){
			mAnimeFrame = frame - 1; //テクスチャの最大値 = FRAME_LIMITなので ー１
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

	if (mPos.x > character_limit_right - sizex){ //マップ外に出ると元の位置に戻す(X)
		mPos.x = character_limit_right - sizex;
	}
	if (mPos.x < character_limit_left + sizex){
		mPos.x = character_limit_left + sizex;
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
#define FRAME_EFFECT 3
void CBase::TurnRect(CRectangle *rect){
	rect->triangle1.x1 = rect->triangle1.x3;
	rect->triangle1.y2 = rect->triangle1.y1;
	rect->triangle1.x3 = rect->triangle1.x2;
	rect->triangle2.x2 = rect->triangle2.x1;
	rect->triangle2.y3 = rect->triangle2.y2;
	rect->triangle2.x1 = rect->triangle2.x3;
}


void CBase::Attack(float Forword, float x, float y, float Axis, CVector2 &mPos){
	mAttackRange.SetVertex(-x, y, x, -y);
	mDummyEffect.SetVertex(-x, y, x, -y);
	mDummyEffect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mAttackRange.SetColor(1.0f, 1.0f, 1.0f, 1.0f);		
	if (Forword >= 0){											//右
		mAttackRange.position = CVector2(mPos.x+ x, mPos.y);
		mDummyEffect.position = mAttackRange.position;
	}
	else{														//左
		mAttackRange.position = CVector2(mPos.x- x, mPos.y);
		mDummyEffect.position = mAttackRange.position;
	}
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


/*
[使い方]
ランダムでポジションを決める
サイズx,サイズy,&自分のポジション
*/
void CBase::RandPos(int x,int y,CVector2 *mPos){
	while (true)
	{
		mPos->x = (rand() - rand()) % (int)(character_limit_left + character_limit_right);
		mPos->y = (rand() - rand()) % (int)(character_limit_top + character_limit_bottom);

		mAxis = mPos->y - y;
		LimitDisp(mPos->x, mPos->y);

		if (mPos->x != 0 || mPos->y != 0){
			break;
		}
	}
}
int CBase::kazu = 0;

/*ＨＰが減ったとき赤色の表示*/
/*関数で使う一覧*/
const float mAlertMax = 10.0f;								//赤色に表示しておく時間
#define SET_ALERT_COLLAR		1.0f, 0.4f, 0.4f, 1.0f	//アラートカラー設定
/*ＨＰが減ったとき赤色の表示関数*/
void CBase::AlertHPRect(CRectangle *rect, float &hp){
	if (!FlagAlertSetHp){				//HP初期設定
		mSaveAlertHitoPoint = hp;
		FlagAlertSetHp = true;
	}
	if (mSaveAlertHitoPoint != hp){		//HPが減ったとき
		rect->SetColor(SET_ALERT_COLLAR);
		if (mAlertCount >= mAlertMax){ //元に戻すまでのINTERVAL
			mSaveAlertHitoPoint = hp;
			rect->SetColor(1.0f,1.0f,1.0f,1.0f);
			mAlertCount = 0;
		}
		mAlertCount++;
	}

}