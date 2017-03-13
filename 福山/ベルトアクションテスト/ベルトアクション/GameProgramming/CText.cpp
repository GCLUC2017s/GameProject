#include"CText.h"

void CText::init() {
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("GAMECLEAR.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	mRect.setuv(mpTexture, 0, 0, 670, 480);	//�e�N�X�`���̎g�p�ݒ�
}
CText::~CText() {
	if (mpTexture) {
		//�e�N�X�`�����g���Ă���΃C���X�^���X�폜
		delete mpTexture;
		mpTexture = 0;
	}
}

CText::CText() : mpTexture(0) {
	//�l�p�`�̒��_�ݒ�
	mRect.setVertex(-5.0f, 4.0f, 5.0f, -4.0f);
	//�l�p�`�̐F��ݒ�
	mRect.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mEnabled = false;
}

void CText::update(){
	mRect.position = mPos;
};

void CText::render() {
	//�l�p�`�̕`��
	if (mEnabled==true){

		mRect.render();
	}
	
}

void CText::setPos(int row, int col) {
	mPos = CGame::getPosition(row, col);
}