#include"Title.h"
#include"CTexture.h"
#include"CGame.h"

//TitleScene�ŕ\�������e�N�X�`���̐ݒ�B

void Title::init(){

	//�Q�[���^�C�g����\��
	mpTitleLogo = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTitleLogo->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	//glMatrixMode(GL_PROJECTION);	
	//glLoadIdentity();
	//	 gluOrtho2D(-300.0f, 300.0f, 100.0f, 200.0f);

		 mTitleLogo.setuv(mpTitleLogo, 0, 0, 640, 480);//TGA��̍��W

		 mpPleaseKey = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
		 mpPleaseKey->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	//	 glMatrixMode(GL_PROJECTION);
//		 glLoadIdentity();

	//	gluOrtho2D(-120.0f, 140.0f, 120.0f, -140.0f);
		mPleaseKey.setuv(mpPleaseKey, 0, 0, 640, 480);//TGA��̍��W

	

}
Title::~Title(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}
}
Title::Title() : mpTexture(0){
	mTitleLogo.setVertex(-7.0f, 2.0f, 2.0, -1.0f);//�\���͈�
	mTitleLogo.setColor(1.0f, 1.0f, 1.0f, 1.0f);//�F��

	mPleaseKey.setVertex(-5.0f, -2.0f, 0.0f, -3.0f);//�\���͈�
	mPleaseKey.setColor(1.0f, 1.0f, 1.0f, 1.0f);

}
void Title::update(){

};
void Title::render(CVector2 pos) {
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);*/

	mTitleLogo.position = pos;
	mTitleLogo.position.y = CGame::mDispCols / 5;

	mPleaseKey.position = pos;
	mPleaseKey.position.y = CGame::mDispCols / 20;

	mTitleLogo.render();
	mPleaseKey.render();
}

void Title::setPos(int row, int col) {

}
