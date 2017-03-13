#include "CPlayer.h"
#include "CGame.h"
#include"CKey.h"
#include"CTexture.h"
#include "define.h"
#define JUMP_FIRST_SPEED 0.2

void CPlayer::init() {
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("plkame.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	m_Player.setuv(mpTexture, 0, 0, 49, 50);
	muki = 2;
	mForward = CVector2(1.0f, 0.0f);
	axis = mPos.y;
}


CPlayer::~CPlayer() {
	if (mpTexture) {
		delete mpTexture;
		mpTexture = 0;
	}
}



//�v���C���[�`��
CPlayer::CPlayer() : mVelocity(0.07f), mpTexture(0),status(3),speed_jump(JUMP_FIRST_SPEED){
	//�l�p�`�̒��_�ݒ�
	m_Player.setVertex(-0.5, 0.5f, 0.5f, -0.5f);
	//�l�p�`�̐F��ݒ�
	m_Player.setColor(1.0f, 1.0f, 1.0f, 1.0f);

}


const float gravity = 0.01;//�d��


void CPlayer::MethodJump(){ //�W�����v�������\�b�h

	mPos.y -= gravity; //�d�͏���
	mPos.y += speed_jump; //��ԏ���
	speed_jump -= gravity;//��������

	m_Player.setColor(1.0f, 0.0f, 0.2f, 1.0f);

	if (mPos.y < axis){//���݂̎��ɂ����Ƃ�
		mPos.y = axis; //�������n�ʂ�"Y"�ɖ߂�
		m_Player.setColor(1.0f, 1.0f, 1.0f, 1.0f);
		speed_jump = JUMP_FIRST_SPEED; 
		enabled_jump = false; //�I��

	}


	
}

const float player_limit_left = -MAP_LIMIT_X / 2;  //�o�k���i�߂���(��)
const float player_limit_top = -0.2;			   //�o�k���i�߂���(��)
const float player_limit_right = MAP_LIMIT_X / 2;  //�o�k���i�߂���(�E)
const float player_limit_bottom = -MAP_LIMIT_Y / 2 + 0.2;//�o�k���i�߂���(��)

void CPlayer::update() {

	//�l�p�`�̈ʒu��ݒ�
	m_Player.position = mPos;
	
	//��̕ӂ̍��[�ƉE�[�̏��������̍��W�����߁A���W�ɊY������Y�������擾����
	int li = CGame::getIndex(mPos + CVector2(-0.3f, -0.5f));
	int ri = CGame::getIndex(mPos + CVector2(0.3f, -0.5f));
	int li2 = CGame::getIndex(mPos + CVector2(-0.3f, 0.5f));
	int ri2 = CGame::getIndex(mPos + CVector2(0.3f, 0.5f));

	//�ړ��̏���

		//switch (jumps)
		//{
		//case true:

		//	jump += 0.2f;

		//	if (jump <= 1){
		//		player.position.y -= 0.01f; //���񒣂�
		//	}
		//	else if (jump <= 50){ //�W�����v��
		//		mForward = CVector2(0.0f, 1.0f);
		//		if (jump != 0)mPos.y += 0.1f / jump;
		//	}

		//	if (jump >= 3){ //�n��ɗ�������
		//		jump = 1.0f;
		//		jumps = false;
		//	}

		//	break;

		//case false:


		//	break;
		//}
	
	//�W�����v
	if (CKey::push(' ') || enabled_jump) {
		if (!enabled_jump){ //�W�����v���Ă��Ȃ��Ƃ�
			enabled_jump = true;
		}
		MethodJump();
	}


	//��ړ�
	if (CKey::push(VK_UP) && axis < player_limit_top) { //��������ɒB���Ă��Ȃ��Ƃ�
		const float speedy = 1.0f;
		mForward = CVector2(0.0f, speedy);
		mPos += mForward * mVelocity;
		axis += mForward.y * mVelocity;

	}

	//���ړ�
	if (CKey::push(VK_DOWN) && axis > player_limit_bottom) {//��������ɒB���Ă��Ȃ��Ƃ�
		status = 0;
		const float speedy = -1.0f;
		mForward = CVector2(0.0f, speedy);
		mPos += mForward * mVelocity;
		axis += mForward.y * mVelocity;

	}

	//�E�ړ�
	if (CKey::push(VK_RIGHT)) {
		muki = 2;
		status = 0;
		const float speedx = 3.0f; 
		mForward = CVector2(speedx, 0.0f);
		mPos += mForward * mVelocity;
	}

	//���ړ�
	if (CKey::push(VK_LEFT)) {


		muki = 4;
		status = 0;

		const float speedx = -3.0f;
		mForward = CVector2(speedx, 0.0f);
		mPos += mForward * mVelocity;

	}	

	

	/*�����蔻��*/
	if (mPos.y > player_limit_top && !enabled_jump){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = player_limit_top;
		axis = mPos.y; //�������Ƃɖ߂�
	}
	if (mPos.y < player_limit_bottom){  //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(��)
		mPos.y = player_limit_bottom;
		axis = mPos.y; //�������Ƃɖ߂�
	}

	if (mPos.x >= player_limit_right || mPos.x <= player_limit_left){ //�}�b�v�O�ɏo��ƌ��̈ʒu�ɖ߂�(X)
		mPos.x = m_Player.position.x;
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
	switch (muki)
	{
	//�ʏ펞
	case 0:
	
		break;
	//������Ă�Ƃ�
	case 1:

		break;
	//�E�����Ă�Ƃ�
	case 2:
		//�A�j���[�V����
		m_Player.setuv(mpTexture, 100, 0, 149, 50);
		framecnt++;
		if (framecnt > 30){
			m_Player.setuv(mpTexture, 100, 50, 149, 100);
			framecnt2++;
			if (framecnt2 > 30){
				framecnt = 0;
				framecnt2 = 0;
			}
		}
		break;

	//�������Ă�Ƃ�
	case 3:

		break;
	//�������Ă�Ƃ�
	case 4:
		//�A�j���[�V����
		m_Player.setuv(mpTexture, 51, 0, 99, 50);
		framecnt++;
		if (framecnt > 30){
			m_Player.setuv(mpTexture, 51, 50, 99, 100);
			framecnt2++;
			if (framecnt2 > 30){
				framecnt = 0;
				framecnt2 = 0;
			}
		}
		break;


		//�������̏����@�������Ȃ�
	case 5:
		break;

	}
	

	//�l�p�`�̈ʒu��ݒ�
	m_Player.position = mPos;


}

void CPlayer::render(){
	//�v���C���[�̕`��
	m_Player.render();
}

//�s�Ɨ񂩂���W��̈ʒu��ݒ肷��
void CPlayer::setPos(int row, int col) {
	//�s�Ɨ񂩂���W��̈ʒu��ݒ肷��
	
	mPos = CGame::getPosition(row, col);
	mTarget = mPos;
}

void CPlayer::setPos(){
	const CVector2 first_pos = CVector2(player_limit_left+CGame::mDispCols,
										(player_limit_top + player_limit_bottom) / 2); //���(X)�Ə��(Y)
	mPos = first_pos;

}
