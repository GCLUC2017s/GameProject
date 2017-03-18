#include "../Base\CBase.h"

/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
void CBase::AnimeFrame(bool roop, int speed){
	if (roop){
		mFrameCount++;
		if (mFrameCount % speed == 0){
			mAnimeFrame++;

		}
		if (mAnimeFrame >= FRAME_LIMIT-1 || mSaveAnime != mStatus){
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

/*
�U���͈͂����߂�
�x�[�X�ɂ���ϐ����g�� 
float Forword�͌��݂̌���������
0�ȏ�@���@�E
0�����@��  ��
float x , y , mAxis �͍U���͈� ,Cvector2�́@������pos������

*/

void CBase::Attack(float Forword, float x, float y, float Axis, CVector2 &mPos){
	mAttackRange.SetVertex(-x, y, x, -y);
	mAttackRange.SetColor(1.0f, 1.0f, 0.0f, 1.0f); //�f�o�b�O�p
	if (Forword > 0)mAttackRange.position = CVector2(mPos.x + 1 + x, mPos.y);
	if (Forword <= 0)mAttackRange.position = CVector2(mPos.x - 1 - x, mPos.y);
	mAttackAxis = Axis;
}
/*���Ԍv�Z�p
�g�����@
float ���ԂŗP�\�̎��Ԃ�����
true�̏ꍇ

false�̏ꍇ

if���Ƃ��Ďg��

�i��j
if(FrameTime(����)){			//�P�\�̎��Ԃ�����
	if(�L�[���͂��ꂽ�ꍇ){
	�U��B�Ɉڍs
	}
}else{							//���Ԃ����Ă��܂����ꍇ
	�҂��A�j���Ɉڍs
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