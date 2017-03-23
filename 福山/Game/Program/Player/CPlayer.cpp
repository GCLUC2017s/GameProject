#include "CPlayer.h"
#include "../Key/CKey.h"
#include "../MyNumber/CMyNumber.h"
#include "../CGame/CGame.h"
#include "../Load/CLoadPlayer.h"
#include <math.h>
#define JUMP_FIRST_SPEED				0.2f								//�W�����v�̃W�����v��
#define FIRST_R_NO_PL					0.0f								//���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL					0.0f								//���߂̃A�b�v�f�[�g�̃|�C���g
/*�e�N�X�`���T�C�Y*/
#define SIZE_TEX_PLAYER_BASE_X			-160.0f								//�v���C���[�̊�{�I�ȃe�N�X�`���T�C�Y X
#define SIZE_TEX_PLAYER_AT_C_X			-180.0f								//�v���C���[��Attack_C�e�N�X�`���T�C�Y X
#define SIZE_TEX_EAT					-180.0f
#define SIZE_TEX_PLAYER_BASE_Y			160.0f								//�v���C���[�̊�{�I�ȃe�N�X�`���T�C�Y Y
/*�e�N�X�`����O*/
#define SIZE_TEX_CUTFLY_X				100.0f								//��Ԏa���̃e�N�X�`���T�C�YX
#define SIZE_TEX_CUTFLY_Y				30.0f								//��Ԏa���̃e�N�X�`���T�C�YY

#define SIZE_TEX_CUTJUMP_X				160.0f								//��Ԏa���̃e�N�X�`���T�C�YX
#define SIZE_TEX_CUTJUMP_Y				160.0f								//��Ԏa���̃e�N�X�`���T�C�YY

#define SLOW_DOWN						 0.005f								//�ړ��̌����X�s�[�h
#define WALK_SPEED						 0.05f								//�����X�s�[�h
#define RUN_SPEED						 0.1f								//����X�s�[�h
#define WALK_X							 1.0f								//�����x�N�g��X
#define WALK_Y							 0.5f								//�����x�N�g��Y
#define PATTERN_R						 1.0f								//PATTERN�̉E
#define PATTERN_L						 2.0f								//PATTERN�̍�
#define V2_RIGHT						 CVector2(WALK_X, 0.0f)				//�E�̌���
#define V2_LEFT							 CVector2(-WALK_X, 0.0f)			//���̌���
#define V2_TOP							 CVector2(0.0f, WALK_Y)				//��̌���
#define V2_BOTTOM						 CVector2(0.0f, -WALK_Y)			//���̌���
/*�A�j���̑���*///(FPS�ł킩��悤�ɂ���)����10��0.1�b
#define ANIME_TIME_BASE						10								//�A�j���̃��[�v���� �p���I�Ȃ���
#define ANIME_TIME_ATTACK					4								//�A�j���̃��[�v���� �U���̂���
#define ANIME_TIME_EAT						10								//�A�j���̃��[�v���� �H�ׂ�
#define ANIME_TIME_JUMPATTACK				4								//�A�j���̂�[�Վ��� �W�����vATTACK
#define ANIME_TIME_BRAKE					7								//�A�j���̃��[�v���� BRAKE
#define ANIME_TIME_JUMP						6								//�A�j�����[�v���� �W�����v
#define ANIME_TIME_WALK						8 + mHungryStatus				//�A�j�����[�v���ԁ@����
#define ANIME_TIME_EX01						4								//�A�j�����[�v���� �K�E�Z�U��

#define ATTACK_A		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,2, CVector2(mPos.x+mForward.x*0.1,mPos.y)			//�U���͈�A
#define ATTACK_B		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y/2,2, CVector2(mPos.x+mForward.x*0.1,mPos.y)			//�U���͈�B
#define ATTACK_C		mForward.x, SIZE_PLAYER_X+0.5f, SIZE_PLAYER_Y,3, CVector2(mPos.x+mForward.x*0.1,mPos.y)	//�U���͈�C
#define ATTACK_JUMP		mForward.x, SIZE_PLAYER_X*2 ,SIZE_PLAYER_Y*2,3,\
						CVector2(mPos.x  -mForward.x*1.7f, mPos.y)	//�U���͈̓W�����vATTACK
/*�W�����v�U���͈�*/
#define FRAME_JUMPBOTTOM 3													//�W�����v�U�����̎��̃A�j���[�V����
#define EAT_ATTACK		mForward.x, SIZE_PLAYER_X, SIZE_PLAYER_Y,2,CVector2(mPos.x+mForward.x*0.1,mPos.y)	//�H�ׂ�U��
#define EX01_ATTACK		mForward.x, SIZE_PLAYER_X+ fabsf(mEx01Speed), SIZE_PLAYER_Y + fabsf(mEx01Speed),3, CVector2(mPos.x+mEx01Speed,mPos.y) //�K�E�Z�͈�
#define EX01_SPEED 0.1f														//�K�E�Z���i�ރX�s�[�h
#define INTERVAL		20.0f												//�U�����INTERVAL�L�[���͑҂�����  
#define HUNGRY_SPEED	0.002f												//���Ȃ�������X�s�[�h
#define HUNGRY_SSPP_HIGH	 RUN_SPEED									//���Ȃ��������ăX�s�[�h���オ��@+=�@���Ďg������
#define HUNGRY_SSPP_LOW		-WALK_SPEED*0.5f								//���Ȃ��������ς�����ɂ��� 	+=�@���Ďg����
#define HUNGRY_POWER_HIGH	1.2f											//���Ȃ��������ė͂��o��@*=���Ďg������
#define HUNGRY_POWER_LOW	0.8f											//���Ȃ��������ς��͂��o�Ȃ��@*=���Ďg������
#define RIGHT WALK_X														//�E
#define LEFT -WALK_X														//��
#define SIZE_ATTACT_C -SIZE_PLAYER_X+0.5f,SIZE_PLAYER_Y,SIZE_PLAYER_X+0.5f,-SIZE_PLAYER_Y
float CPlayer::camera_x;
float CPlayer::camera_y;


void CPlayer::SetPos(){
	mPos = first_pos;
	mAxis = mPos.y - SIZE_PLAYER_Y;

}


void CPlayer::Init() {
	
	SetPos();
	camera_x = mPos.x;
	camera_y = mPos.y;

	/*�e�N�X�`���𒣂�*/
	mRect.SetUv(CLoadPlayer::GetInstance()->mStayTex[0], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
	mShadow.SetUv(CLoadPlayer::GetInstance()->mShadowTex, 0, 0, SHADOW_TEX_X, SHADOW_TEX_Y);
	mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutFlyTex, 0, 0, SIZE_TEX_CUTFLY_X, SIZE_TEX_CUTFLY_Y);
	mForward = CVector2(RIGHT, 0.0f);
}



CPlayer::~CPlayer() {
	


}

//�v���C���[�`��
CPlayer::CPlayer() : mVelocity(0), mSpeedJump(JUMP_FIRST_SPEED),mEnabledInterval(false){

	
	mCharaFlag = true;
	mPriorityR = E_PLAYER;			//Render�̃i���o�[ 
	mPriorityU = E_PLAYER;			//Update�̃i���o�[
	mHitPoint = PL_HP_X;		//�g�o
	mStamina = PL_ST_X;			//ST
	mMyNumber = E_PLAYER;
	mStatus = E_STAY_R,
	//�l�p�`�̒��_�ݒ�
	mRect.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	mShadow.SetVertex(-SIZE_SHADOW_X, SIZE_SHADOW_Y, SIZE_SHADOW_X, -SIZE_SHADOW_Y);
	//�l�p�`�̐F��ݒ�
	mRect.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}
/*���E���f*/
void CPlayer::DecisionRL(int R, int L){
	
		if (mSaveForword.x == RIGHT || mSaveForword.x == 0){ mStatus = R; }
		if (mSaveForword.x == LEFT){ mStatus = L; }
	
}
/*�W�����v���\�b�h*/
void CPlayer::Jump(){ //�W�����v�������\�b�h
	/*
	�v�Z
	y = y + v(���Ԃɂ��i�񂾋���)
	�d�͌v�Z
	v = v0 + g*t(�ǂꂭ�炢�d�͂�����������)
	*/
	if (CKey::push('C') && !mEnabledJump && !mEnabledAttack) {
		mSpeedJump = JUMP_FIRST_SPEED;
		mAnimeFrame = 0; //�W�����v����frame
		mEnabledJump = true; //�W�����v���Ă��Ȃ��Ƃ�
		DecisionRL(E_JUMP_R, E_JUMP_L);
	}

	if (mEnabledJump){
		if (!mEnabledJumpAttack){
			mAnimeFrame = 1; //�W�����v����frame
			if (mSpeedJump <= 0){
				mAnimeFrame = 2;
			}
		}
		mPos.y = mPos.y + mSpeedJump; //��ԏ���
		mSpeedJump -= gravity;//��������
		
		if (mPos.y < mAxis + SIZE_PLAYER_Y){//���݂̎��ɑ��������Ƃ�
			mPos.y = mAxis + SIZE_PLAYER_Y; //�������n�ʂ�"Y"�ɖ߂�
			mEnabledJump = false; //�I��
		}
	}
}
/*���邩�ۂ����\�b�h*/
void CPlayer::RunWalk(CVector2 v){
	if (CKey::push(VK_CONTROL)){ //���鎞
		mVelocity = RUN_SPEED;
		if(!mEnabledJump)DecisionRL(E_RUN_R, E_RUN_L);
	}
	else{				//�����Ƃ�
		mVelocity = WALK_SPEED;
	}
	
	mForward = v;
	mPos += mForward * (mVelocity+mHungrySSpp);
	mAxis += mForward.y *(mVelocity + mHungrySSpp);
}

/*�ړ����̃��\�b�h*/
void CPlayer::Move(){
	CVector2 SavemPos = mPos;		//�ʒu�ۑ�
	float  SavemAxis = mAxis;		//�ʒu�ۑ�
	// �E�ړ�
	if (CKey::push(RIGHT_KEY)) {
		if (!mEnabledJump)mStatus = E_WALK_R;
		RunWalk(V2_RIGHT);
		mSaveForword = V2_RIGHT;
	}
	//���ړ�
	if (CKey::push(LEFT_KEY)) {
		if (!mEnabledJump)mStatus = E_WALK_L;
		RunWalk(V2_LEFT);
		mSaveForword = V2_LEFT;
	}
	//��ړ�
	if (CKey::push(UP_KEY)) { 
		if (!mEnabledJump)DecisionRL(E_WALK_R, E_WALK_L);
		RunWalk(V2_TOP);
	}
	//���ړ�
	if (CKey::push(DOWN_KEY)) {
		if (!mEnabledJump)DecisionRL(E_WALK_R, E_WALK_L);
		RunWalk(V2_BOTTOM);
	}
	if (mAxis > character_limit_top - SIZE_PLAYER_Y ||
		mAxis + SIZE_PLAYER_Y < character_limit_bottom + SIZE_PLAYER_Y){ //��
		mPos = SavemPos;
		mAxis = SavemAxis;
	}
}

/*�u���[�L���\�b�h*/
void CPlayer::Brake(){
	//�u���[�L��������Ƃ�(����Ȃ������Ȃ��W�����v���Ȃ�)
	if (!CKey::push(VK_DOWN) && !CKey::push(VK_UP) && !CKey::push(VK_LEFT) && !CKey::push(VK_RIGHT) && mVelocity > 0 
		&& !mEnabledJump && mVelocity != 0 && !mEnabledAttack){
		mVelocity -= SLOW_DOWN;
		DecisionRL(E_BRAKE_R, E_BRAKE_L);
	}
	else if (mVelocity <= 0){
		mVelocity = 0;
	}
	mPos += mForward * mVelocity;
	mAxis += mForward.y * mVelocity;
}

/*NormalAttack���\�b�h*/
void CPlayer::PlayerAttack(){
	//�ʏ�U�� �A�j���؂�ւ�
	switch (mStatus)
	{
	case E_NORMALATTACK_A_R:				//1�i�K��
	case E_NORMALATTACK_A_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEnabledAttack = false;
			if (FrameTime(INTERVAL)){
				mEnabledInterval = true;
				if (CKey::once('X')){
					mAnimeFrame = 0;
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_B_R, E_NORMALATTACK_B_L);
				}
			}
			else{
				mEnabledInterval = false;
			}
		}
		Attack(ATTACK_A);
		break;
	case E_NORMALATTACK_B_R:				//2�i�K��
	case E_NORMALATTACK_B_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEnabledAttack = false;			 // �U������������@
			if (FrameTime(INTERVAL)){		//Interval
				mEnabledInterval = true;    //�L�[���͑҂�
				if (CKey::once('X')){		
					mAnimeFrame = 0;
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_C_R, E_NORMALATTACK_C_L);
				}
			}
			else{
				mEnabledInterval = false;
			}
		}
		
		Attack(ATTACK_B);
		break;
	case E_NORMALATTACK_C_R:				//3�i�K��
	case E_NORMALATTACK_C_L:
		mRect.SetVertex(SIZE_ATTACT_C);
		if (mAnimeFrame != FRAME_LIMIT - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mRect.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_X);
			mEnabledAttack = false;
			mEnabledInterval = false;

		}
		Attack(ATTACK_C);
		break;
	case E_JUMPATTACK_R:
	case E_JUMPATTACK_L:
		if (mAnimeFrame != FRAME_LIMIT - 1){
			mEnabledAttack = true;
			mEnabledJumpAttack = true;
		}
		else{ //�A�j���Ōオ������
			mEnabledAttack = false;
			mEnabledJumpAttack = false;
		}
		Attack(ATTACK_JUMP);
		AtJumpAnime();
		break;
	case E_EAT_R:
	case E_EAT_L:
		if (mAnimeFrame != FRAME_LIMIT3 - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEnabledAttack = false;
			mEnabledEat = false;
		}
		Attack(EAT_ATTACK);
		break;
	case E_EX01_L:
	case E_EX01_R:
		
		if (mSaveForword.x == RIGHT || mSaveForword.x == 0){ mEx01Speed += EX01_SPEED; }
		if (mSaveForword.x == LEFT){ mEx01Speed -= EX01_SPEED; }
		if (mAnimeFrame != FRAME_LIMIT8 - 1){ mEnabledAttack = true; }
		else{ //�A�j���Ōオ������
			mEx01Speed = 0;
			mEnabledAttack = false;
			mEnabledEx01 = false;
		}
		Attack(EX01_ATTACK);
		break;
	default:
		mEnabledAttack = false;
		mEnabledInterval = false;
		if (mStatus != E_BRAKE_R && mStatus != E_BRAKE_L){ //�u���[�L���������Ă��Ȃ��Ƃ�
			/*�ʏ�U�� �U���͂̐ݒ� �t���O��^��*/
			if (CKey::once('X') && !mEnabledAttack){

					mAttackPoint = PL_NORMAL_POWER;
					mAnimeFrame = 0;
					mAttackPoint = mAttackPoint *mHungryPower;
					mEnabledAttack = true;
					DecisionRL(E_NORMALATTACK_A_R, E_NORMALATTACK_A_L);
					if (mEnabledJump){


						mAttackPoint = PL_JUMP_AT_POWER;
						mAnimeFrame = 0;
						mAttackPoint = mAttackPoint *mHungryPower;
						mEnabledAttack = true;
						mEnabledJumpAttack = true;
						DecisionRL(E_JUMPATTACK_R, E_JUMPATTACK_L);
					}
			}
			/*�ߐH�U�� �U���͂̐ݒ� �t���O��^��*/
			if (CKey::once('Z') && !mEnabledAttack){
				mAttackPoint = PL_EAT_POWER;		
				mAnimeFrame = 0;
				mAttackPoint = mAttackPoint *mHungryPower;
				mEnabledAttack = true;
				mEnabledEat = true;
				DecisionRL(E_EAT_R, E_EAT_L);
			}
			/*�K�E�Z(����)*/
			if (CKey::once('A') && mStamina >= PL_ST_X *0.1){
				mAnimeFrame = 0;
				mAttackPoint = PL_EX01_POWER;
				mStamina -= PL_ST_X*0.1f;
				mAttackPoint = mAttackPoint *mHungryPower;
				mEnabledAttack = true;
				mEnabledEx01 = true;
				DecisionRL(E_EX01_R, E_EX01_L);
			}
		}
		break;
	};
}

/*
(�A�j���[�V����)�������̂���
BRAKE,EX02,
NORMALATAKKU_,C
FLERM
*/
#define FRAME_CUTDOWN 2 //���a���A�j��FRAME
#define FRAME_CUTRETURN 4//�a���A�j���Ԃ�
#define FRAME_CUTUP 5

void CPlayer::AtJumpAnime(){
	if (mAnimeFrame == FRAME_CUTDOWN){
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, SIZE_TEX_CUTJUMP_X, 0, 0, SIZE_TEX_CUTJUMP_Y); }//�a��()
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, 0, 0, SIZE_TEX_CUTJUMP_X, SIZE_TEX_CUTJUMP_Y); }//�a��()
	}
	if (mAnimeFrame == FRAME_CUTRETURN){
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, SIZE_TEX_CUTJUMP_X, 0, 0, SIZE_TEX_CUTJUMP_Y); }//�a��()
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, 0, 0, SIZE_TEX_CUTJUMP_X, SIZE_TEX_CUTJUMP_Y); }//�a��()
	}
	if (mAnimeFrame == FRAME_CUTUP){
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, SIZE_TEX_CUTJUMP_X, SIZE_TEX_CUTJUMP_Y,0 , 0); }//�a��()
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutJumpTex, 0, SIZE_TEX_CUTJUMP_Y, SIZE_TEX_CUTJUMP_X, 0); }//�a��()
	}
}
/*�A�j���[�V�����V�[��*/
void CPlayer::AnimeScene(){
	
	/*�A�j���[�V�����̃X�e�[�^�X*/
	switch (mStatus)
	{
		/*��*/
	case E_STAY_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mStayTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_L:
		AnimeFrame(true, ANIME_TIME_WALK,FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mWalkTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_L:
		AnimeFrame(true, ANIME_TIME_BASE,FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mRunTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[0][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[1][mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[2][mAnimeFrame], SIZE_TEX_PLAYER_AT_C_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMPATTACK_L:
		AnimeFrame(false, ANIME_TIME_JUMPATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpAttackTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_L:
		AnimeFrame(false, ANIME_TIME_EAT, FRAME_LIMIT3);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEatTex[mAnimeFrame], SIZE_TEX_EAT, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_L:
		AnimeFrame(false, ANIME_TIME_EX01, FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx01Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_L:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx02Tex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_L:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mFlameTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMP_L://����Ȃ̂ŃW�����v���\�b�h�ŏ���
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_L:
		AnimeFrame(false, ANIME_TIME_BRAKE,FRAME_LIMIT2);
		mRect.SetUv(CLoadPlayer::GetInstance()->mBrakeTex[mAnimeFrame], SIZE_TEX_PLAYER_BASE_X, 0, 0, SIZE_TEX_PLAYER_BASE_Y);
		break;
		/*�E*/
	case E_STAY_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mStayTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_WALK_R:
		AnimeFrame(true, ANIME_TIME_WALK,FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mWalkTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_RUN_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mRunTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_A_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[0][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_B_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[1][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_NORMALATTACK_C_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mNormalAttackTex[2][mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMPATTACK_R:
		AnimeFrame(false, ANIME_TIME_JUMPATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpAttackTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EAT_R:
		AnimeFrame(false, ANIME_TIME_ATTACK,FRAME_LIMIT3);

		mRect.SetUv(CLoadPlayer::GetInstance()->mEatTex[mAnimeFrame], 0, 0, SIZE_TEX_EAT, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX01_R:
		AnimeFrame(false, ANIME_TIME_EX01, FRAME_LIMIT8);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx01Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_EX02_R:
		AnimeFrame(false, ANIME_TIME_ATTACK);
		mRect.SetUv(CLoadPlayer::GetInstance()->mEx02Tex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_FLAME_R:
		AnimeFrame(true, ANIME_TIME_BASE);
		mRect.SetUv(CLoadPlayer::GetInstance()->mFlameTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_JUMP_R://����Ȃ̂ŃW�����v���\�b�h�ŏ���
		mRect.SetUv(CLoadPlayer::GetInstance()->mJumpTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_AT_C_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	case E_BRAKE_R:
		AnimeFrame(false, ANIME_TIME_BRAKE,FRAME_LIMIT2);
		mRect.SetUv(CLoadPlayer::GetInstance()->mBrakeTex[mAnimeFrame], 0, 0, SIZE_TEX_PLAYER_BASE_X, SIZE_TEX_PLAYER_BASE_Y);
		break;
	};
	
	if (!mEnabledJumpAttack){
		if (mForward.x == LEFT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutFlyTex, SIZE_TEX_CUTFLY_X, 0, 0, SIZE_TEX_CUTFLY_Y); }//�a��()
		if (mForward.x == RIGHT){ mAttackRange.SetUv(CLoadPlayer::GetInstance()->mCutFlyTex, 0, 0, SIZE_TEX_CUTFLY_X, SIZE_TEX_CUTFLY_Y); }//�a��()
	}
}
/*�\�͕ω��̃��\�b�h*/
void CPlayer::ChangeStatus(){

	/*�q�b�g�|�C���g����*/
	/*�X�^�~�i����*/
	if (mStamina <= PL_ST_X && mStamina >= 0){	  //�����Ă���
		mStamina -= HUNGRY_SPEED; 

		/*�X�e�[�^�X�ω�*/
		if (HUNGRY_S_HIGH_IF){ 
			mHungryPower = HUNGRY_POWER_LOW; mHungrySSpp = HUNGRY_SSPP_LOW; //���Ȃ���t����
			mHungryStatus = E_HIGH;
		} 
		else if (HUNGRY_S_LOW_IF){ 
			mHungryPower = HUNGRY_POWER_HIGH; mHungrySSpp = HUNGRY_SSPP_HIGH;//���Ȃ��������㏸
			mRect.triangle1.r = 0.4f;
			mRect.triangle2.r = 0.4f;
			mRect.triangle1.g = 0.4f;
			mRect.triangle2.g = 0.4f;
			mHungryStatus = E_LOW;
		}
		else{									 //���� �ω��Ȃ�
			mHungryPower = 0; mHungrySSpp = 0;
			mHungryStatus = E_NORMAL;
		}
		/*�X�e�[�^�X�ω��I��*/
	} 
	else{										 //��������ꍇ
		mStamina = PL_ST_X; 
	} 
	if (mStamina <= 0){							 //�����Ȃ�����ꍇ
		mStamina = 0;							 //����ȏ�X�^�~�i�����炳�Ȃ��悤�ɂ���
		mHitPoint -= HUNGRY_SPEED;
	}
	

}

/*�A�b�v�f�[�g*/
void CPlayer::Update() {
	assert(mAnimeFrame <= FRAME_LIMIT8);				//�t���[���������𒴂���ƃ_��
	//assert(E_STAY_L <= mStatus && mStatus <= E_BRAKE_R);       //�e�N�X�`���𐳂����ǂݍ��߂Ă��邩�ǂ���
	//�l�p�`�̈ʒu��ݒ�
	mAttackRange.position = mPos;
	if (mHitPoint > 0){ //HP������Ƃ�
		mRect.position = mPos;
		if (!mEnabledAttack){ Move(); }	//�ړ����\�b�h
		Brake();						//�u���[�L���\�b�h
		Jump();							//�W�����v���\�b�h
		PlayerAttack();					//�A�^�b�N���\�b�h
		AnimeScene();					//�A�j�����\�b�h
		AlertHPRect(&mRect, mHitPoint);	//�A���[�g���\�b�h(HP�ω��ɂ�����)
		ChangeStatus();					//�\�͕ω����\�b�h
	}
	if (!mEnabledInterval && mStatus != E_STAY_L && mStatus != E_STAY_R && mVelocity <= 0 && !mEnabledJump && !mEnabledAttack){
		DecisionRL(E_STAY_R, E_STAY_L);
	}

	LimitDisp(SIZE_PLAYER_X, SIZE_PLAYER_Y);

	mPriorityR = -mAxis;
	camera_x = mPos.x;
	camera_y = mPos.y;
	mRect.position = mPos;
	mShadow.position = CVector2(mPos.x, mAxis);

	const float fade_speed = 0.01f;
	if (mHitPoint <= 0) {
		//�V�[���Q�[���I�[�o�[������
		CGame::FadeOut(fade_speed,&mRect);
	}
	if (mRect.triangle1.a <= 0){ //�t�F�[�h�A�E�g���I��������KILL����
		mKillFlag = true;
	}
}


void CPlayer::Render(){
	//�v���C���[�̕`��
	mShadow.Render();
	mRect.Render();
	if (mEnabledAttack && !mEnabledEat){
		mAttackRange.Render();
	}
	

}
