#include "CWindmill.h"
#include "CGame.h"
#include <math.h>

void CWindmill::init() {
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("����.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	mRect_spin.degree = 0;
	//�l�p�`�̒��_
	mRect_rod.setuv(mpTexture, 0, 200, 200, 400);	//�e�N�X�`���̎g�p�ݒ�
	mRect_spin.setuv(mpTexture, 0, 0, 200, 200);	//�e�N�X�`���̎g�p�ݒ�
}

CWindmill::~CWindmill() {
	if (mpTexture) {
		//�e�N�X�`�����g���Ă���΃C���X�^���X�폜
		delete mpTexture;
		mpTexture = 0;
	}
}

CWindmill::CWindmill() : mpTexture(0){
	mRect_spin.degree = 0;
	//�l�p�`�̒��_�ݒ�
	mRect_rod.setVertex(-0.5f, 0.0f, 0.5f, -2.0f);
	mRect_spin.setVertex(-1.0f, 1.0f, 1.0f, -1.0f);
	//�l�p�`�̐F��ݒ�
	mRect_rod.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mRect_spin.setColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void CWindmill::update(){
	mRect_rod.position = mPos;
	mRect_spin.position = mPos;

 	mRect_spin.degree -= 5;
	mRect_spin.degree %= 360;

};

void CWindmill::render() {
	//�l�p�`�̕`��
	mRect_rod.render();
	mRect_spin.render();
}

void CWindmill::setPos(int row, int col) {
	mPos = CGame::getPosition(row, col);
	mRect_rod.position = mPos;
	mRect_spin.position = mPos;

}