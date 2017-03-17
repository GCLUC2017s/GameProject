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
	}
	else{
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;
		}
		if (mAnimeFrame >= FRAME_LIMIT){
			mAnimeFrame = FRAME_LIMIT - 1; //�e�N�X�`���̍ő�l = FRAME_LIMIT�Ȃ̂� �[�P
		}
	}

	mSaveAnime = mStatus;
}
void CBase::LimitDisp(int sizex, int sizey){
	/*�����蔻��*/
	if (mAxis > character_limit_top - sizey && !mEnabledJump){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_top;
		mAxis = mPos.y - sizey; //�������Ƃɖ߂�
	}
	if (mAxis + sizey < character_limit_bottom + sizey && !mEnabledJump){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = character_limit_bottom + sizey;
		mAxis = mPos.y - sizey; //�������Ƃɖ߂�
	}

	if (mPos.x >= character_limit_right - sizex || mPos.x <= character_limit_left + sizex){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = mRect.position.x;
	}
	/*�����蔻��I��*/
}