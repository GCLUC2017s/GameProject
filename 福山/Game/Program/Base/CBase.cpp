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
	if (mAxis > character_limit_top - SIZE_PLAYER_Y && !mEnabledJump){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = character_limit_top;
		mAxis = mPos.y - SIZE_PLAYER_Y; //軸をもとに戻す
	}
	if (mAxis + SIZE_PLAYER_Y < character_limit_bottom + SIZE_PLAYER_Y){  //マップ外に出ると元の位置に戻す(軸)
		mPos.y = character_limit_bottom + SIZE_PLAYER_Y;
		mAxis = mPos.y - SIZE_PLAYER_Y; //軸をもとに戻す
	}

	if (mPos.x >= character_limit_right - SIZE_PLAYER_X || mPos.x <= character_limit_left + SIZE_PLAYER_X){ //マップ外に出ると元の位置に戻す(X)
		mPos.x = mRect.position.x;
	}
	/*あたり判定終了*/
}