#include "CPlayer.h"
#include"CKey.h"
#include"CTexture.h"
#include "define.h"
#define SIZE_PLAYER_Y 1 * 2
#define SIZE_PLAYER_X 0.5 * 2
#define JUMP_FIRST_SPEED 0.2
#define HITPOINT_PLAYER 10
#define FIRST_R_NO_PL 0 //���߂̃����_�[�̃|�C���g
#define FIRST_U_NO_PL 0 //���߂̃A�b�v�f�[�g�̃|�C���g
#define SIZE_TEX_PLAYER_STAY_X 800 //�v���C���[�̑҂��p�e�N�X�`���T�C�Y X
#define SIZE_TEX_PLAYER_STAY_Y 800 //�v���C���[�̑҂��p�e�N�X�`���T�C�Y Y
#define SIZE_TEX_PLAYER_WALK_X 800 //�v���C���[�̕����e�N�X�`���T�C�Y Y
#define SIZE_TEX_PLAYER_WALK_Y 800 //�v���C���[�̕����p�e�N�X�`���T�C�Y Y

const float player_limit_left = -MAP_LIMIT_X / 2;  //�o�k���i�߂���(��)
const float player_limit_top =  MAP_LIMIT_Y / 4;			   //�o�k���i�߂���(��)
const float player_limit_right = MAP_LIMIT_X / 2;  //�o�k���i�߂���(�E)
const float player_limit_bottom = -MAP_LIMIT_Y / 2;//�o�k���i�߂���(��)

float CPlayer::camera_x; 
float CPlayer::camera_y;


void CPlayer::SetPos(){
	const CVector2 first_pos = CVector2(player_limit_left + MAP_LIMIT_X,
		(player_limit_top + player_limit_bottom) / 2); //���(X)�Ə��(Y)
	mPos = first_pos;
	mAxis = mPos.y;

}


void CPlayer::Init() {
	camera_x = mPos.x;
	camera_y = mPos.y;
	/*�e�N�X�`���ǂݍ���*/
	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = new CTexture(); //�e�N�X�`���N���X�̃C���X�^���X�쐬
		mWalk_tex[i] = new CTexture(); //�e�N�X�`���N���X�̃C���X�^���X�쐬
		mRun_tex[i] = new CTexture();

	}

	/*�e�N�X�`���t�@�C���ǂݍ���*/
	mStay_tex[0]->load("beru\\beru_stay\\beru_stay_00.tga");	
	mStay_tex[1]->load("beru\\beru_stay\\beru_stay_01.tga");	
	mStay_tex[2]->load("beru\\beru_stay\\beru_stay_02.tga");	
	mStay_tex[3]->load("beru\\beru_stay\\beru_stay_03.tga");	
	mStay_tex[4]->load("beru\\beru_stay\\beru_stay_04.tga");	
	mStay_tex[5]->load("beru\\beru_stay\\beru_stay_05.tga");	

	mWalk_tex[0]->load("beru\\beru_walk\\beru_walk_00.tga");
	mWalk_tex[1]->load("beru\\beru_walk\\beru_walk_01.tga");
	mWalk_tex[2]->load("beru\\beru_walk\\beru_walk_02.tga");
	mWalk_tex[3]->load("beru\\beru_walk\\beru_walk_03.tga");
	mWalk_tex[4]->load("beru\\beru_walk\\beru_walk_04.tga");
	mWalk_tex[5]->load("beru\\beru_walk\\beru_walk_05.tga");

	mRun_tex[0]->load()

	/*�e�N�X�`���𒣂�*/
	mPlayer.SetUv(mStay_tex[0], 0, 0, 800,800);
	mForward = CVector2(1.0f, 0.0f);
}


CPlayer::~CPlayer() {
}



//�v���C���[�`��
CPlayer::CPlayer() : mVelocity(0.07f), speed_jump(JUMP_FIRST_SPEED),mFlame_Count(0){

	for (int i = 0; i < FLAME_LIMIT; i++)
	{
		mStay_tex[i] = 0;
	}

	mPriorityR = FIRST_R_NO_PL;			//Render�̃i���o�[
	mPriorityU = FIRST_U_NO_PL;			//Update�̃i���o�[
	mHitPoint = HITPOINT_PLAYER;			//�g�o
	mMyNumber = E_PLAYER;

	//�l�p�`�̒��_�ݒ�
	mPlayer.SetVertex(-SIZE_PLAYER_X, SIZE_PLAYER_Y, SIZE_PLAYER_X, -SIZE_PLAYER_Y);
	//�l�p�`�̐F��ݒ�
	mPlayer.SetColor(1.0f, 0.0f, 1.0f, 1.0f);

}


const float gravity = 0.01;//�d��


void CPlayer::Jump(){ //�W�����v�������\�b�h

	mPos.y -= gravity; //�d�͏���
	mPos.y += speed_jump; //��ԏ���
	speed_jump -= gravity;//��������


	if (mPos.y < mAxis){//���݂̎��ɂ����Ƃ�
		mPos.y = mAxis; //�������n�ʂ�"Y"�ɖ߂�
		speed_jump = JUMP_FIRST_SPEED;
		enabled_jump = false; //�I��

	}



}

/*�A�j���̃t���[���𓮂������\�b�h*/
void CPlayer::AnimeFlame(){

	mFlame_Count += 1;
	if (mFlame_Count % 5 == 0){ //�t���[����
		mAnime += 1;
	}
	if (mAnime >= FLAME_LIMIT || save_eAnime != eAnime){
		mAnime = 0;
	}
	save_eAnime = eAnime;

}

void CPlayer::Update() {
	AnimeFlame();
	assert(mAnime <= FLAME_LIMIT); //�t���[���������𒴂���ƃ_��
	mPriorityR = mAxis;
	camera_x = mPos.x;
	camera_y = mPos.y;

	//�l�p�`�̈ʒu��ݒ�
	mPlayer.position = mPos;


	//�ړ��̏���

	if (CKey::push(VK_RIGHT)) { // �E�ړ�

		const float speedx = 3.0f;
		mForward = CVector2(speedx, 0.0f);
		mPos += mForward * mVelocity;
		eAnime = E_WALK_R;

	}
	else if (save_eAnime == E_WALK_R){//�ҋ@�� ���O�����̕����łȂ����
		eAnime = E_STAY_R;
	}
	if (CKey::push(VK_LEFT)) { //���ړ�

		const float speedx = -3.0f;
		mForward = CVector2(speedx, 0.0f);
		mPos += mForward * mVelocity;
		eAnime = E_WALK_L;
	}else if(save_eAnime == E_WALK_L){ //�ҋ@�� ���O���E�̕����łȂ����
			eAnime = E_STAY_L; //�D��x������

	}

	//�W�����v
	if (CKey::push(' ') || enabled_jump) {
		if (!enabled_jump){ //�W�����v���Ă��Ȃ��Ƃ�
			enabled_jump = true;
		}
		Jump();
	}


	//��ړ�
	if (CKey::push(VK_UP) && mAxis < player_limit_top - SIZE_PLAYER_Y) { //��������ɒB���Ă��Ȃ��Ƃ�
		const float speedy = 1.0f;
		mForward = CVector2(0.0f, speedy);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}

	//���ړ�
	if (CKey::push(VK_DOWN) && mAxis > player_limit_bottom + SIZE_PLAYER_Y) {//��������ɒB���Ă��Ȃ��Ƃ�

		const float speedy = -1.0f;
		mForward = CVector2(0.0f, speedy);
		mPos += mForward * mVelocity;
		mAxis += mForward.y * mVelocity;

	}




	/*�����蔻��*/
	if (mPos.y > player_limit_top - SIZE_PLAYER_Y && !enabled_jump){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = player_limit_top - SIZE_PLAYER_Y;
		mAxis = mPos.y; //�������Ƃɖ߂�
	}
	if (mPos.y < player_limit_bottom + SIZE_PLAYER_Y){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = player_limit_bottom + SIZE_PLAYER_Y;
		mAxis = mPos.y; //�������Ƃɖ߂�
	}

	if (mPos.x >= player_limit_right - SIZE_PLAYER_X || mPos.x <= player_limit_left + SIZE_PLAYER_X){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = mPlayer.position.x;
	}
	/*�����蔻��I��*/


	//�X�C�b�`

	/*����
	0���f�t�H���g
	1�������
	2���E����
	3��������
	4��������
	*/
	
	//�l�p�`�̈ʒu��ݒ�
	mPlayer.position = mPos;
	/*�A�j���[�V�����̃X�e�[�^�X*/

	switch (eAnime)
	{
		/*�ҋ@��*/
	case E_STAY_L:
		mPlayer.SetUv(mStay_tex[mAnime],SIZE_TEX_PLAYER_STAY_X, 0, 0, SIZE_TEX_PLAYER_STAY_Y);
		printf("�ҋ@ ������\n");
		break;
	case E_STAY_R:
		mPlayer.SetUv(mStay_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_STAY_X,SIZE_TEX_PLAYER_STAY_Y);
		printf("�ҋ@�@�E����\n");
		break;
		/*������*/
	case E_WALK_L:
		mPlayer.SetUv(mWalk_tex[mAnime], SIZE_TEX_PLAYER_WALK_X, 0, 0, SIZE_TEX_PLAYER_WALK_Y);
		printf("�����@������\n");
		break;
	case E_WALK_R:
		mPlayer.SetUv(mWalk_tex[mAnime], 0, 0, SIZE_TEX_PLAYER_STAY_X, SIZE_TEX_PLAYER_WALK_Y);
		printf("�����@�E����\n");
		break;
		/*���蒆*/
	case E_RUN_L:
		mPlayer.SetUv(mStay_tex[mAnime], 0, 0, 800, 800);
		break;
	case E_RUN_R:
		mPlayer.SetUv(mStay_tex[mAnime], 0, 0, 800, 800);
		break;
	}

}

void CPlayer::Render(){
	//�v���C���[�̕`��
	mPlayer.Render();
}
