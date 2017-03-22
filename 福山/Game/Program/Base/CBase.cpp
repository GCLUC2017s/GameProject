#include "../Base\CBase.h"
#include"../Task/CTaskManager.h"
#include <time.h>
/*�A�j���̃t���[���𓮂������\�b�h*/ //�G�l�~�[�ɂ���ĈႤ�ꍇ������̂ŉ摜�f�[�^�p�Q��
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
			mAnimeFrame = FRAME_LIMIT - 1; //�e�N�X�`���̍ő�l = FRAME_LIMIT�Ȃ̂� �[�P
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
			mAnimeFrame = frame - 1; //�e�N�X�`���̍ő�l = FRAME_LIMIT�Ȃ̂� �[�P
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

	if (mPos.x > character_limit_right - sizex){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = character_limit_right - sizex;
	}
	if (mPos.x < character_limit_left + sizex){
		mPos.x = character_limit_left + sizex;
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
	if (Forword >= 0){											//�E
		mAttackRange.position = CVector2(mPos.x+ x, mPos.y);
		mDummyEffect.position = mAttackRange.position;
	}
	else{														//��
		mAttackRange.position = CVector2(mPos.x- x, mPos.y);
		mDummyEffect.position = mAttackRange.position;
	}
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


/*
[�g����]
�����_���Ń|�W�V���������߂�
�T�C�Yx,�T�C�Yy,&�����̃|�W�V����
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

/*�g�o���������Ƃ��ԐF�̕\��*/
/*�֐��Ŏg���ꗗ*/
const float mAlertMax = 10.0f;								//�ԐF�ɕ\�����Ă�������
#define SET_ALERT_COLLAR		1.0f, 0.4f, 0.4f, 1.0f	//�A���[�g�J���[�ݒ�
/*�g�o���������Ƃ��ԐF�̕\���֐�*/
void CBase::AlertHPRect(CRectangle *rect, float &hp){
	if (!FlagAlertSetHp){				//HP�����ݒ�
		mSaveAlertHitoPoint = hp;
		FlagAlertSetHp = true;
	}
	if (mSaveAlertHitoPoint != hp){		//HP���������Ƃ�
		rect->SetColor(SET_ALERT_COLLAR);
		if (mAlertCount >= mAlertMax){ //���ɖ߂��܂ł�INTERVAL
			mSaveAlertHitoPoint = hp;
			rect->SetColor(1.0f,1.0f,1.0f,1.0f);
			mAlertCount = 0;
		}
		mAlertCount++;
	}

}