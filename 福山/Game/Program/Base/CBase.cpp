#include "../Base\CBase.h"

/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CBase::AnimeFrame(bool roop, int speed){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT || mSaveAnime != mStatus){
			mAnimeFrame = 0;
		}
		mSaveAnime = mStatus;
	}
	else{
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT){
			mAnimeFrame = FRAME_LIMIT - 1; //�e�N�X�`���̍ő�l = FRAME_LIMIT�Ȃ̂� �[�P
		}
		mSaveAnime = mStatus;
	}
}