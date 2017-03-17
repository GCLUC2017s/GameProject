#include "../Base\CBase.h"

/*アニメのフレームを動かすメソッド*/ //エネミーによって違う場合があるので画像データ用参照
void CBase::AnimeFrame(bool roop, int speed){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT || mSaveAnime != mStatus){
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