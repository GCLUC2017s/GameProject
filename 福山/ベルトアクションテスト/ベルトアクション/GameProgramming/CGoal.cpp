#include "CGoal.h"
#include "CGame.h"

void CGoal::init() {
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("tobira.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	mRect.setuv(mpTexture, 0, 0, 100, 100);	//�e�N�X�`���̎g�p�ݒ�
}

CGoal::~CGoal() {
	if (mpTexture) {
		//�e�N�X�`�����g���Ă���΃C���X�^���X�폜
		delete mpTexture;
		mpTexture = 0;
	}
}

CGoal::CGoal() : mpTexture(0) {
	//�l�p�`�̒��_�ݒ�
	mRect.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	//�l�p�`�̐F��ݒ�
	mRect.setColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void CGoal::update(){
	mRect.position = mPos;
};

void CGoal::render() {
	//�l�p�`�̕`��
	if (mEnabled == true){ mRect.render(); }
}

void CGoal::setPos(int row, int col) {
	mPos = CGame::getPosition(row, col);
}