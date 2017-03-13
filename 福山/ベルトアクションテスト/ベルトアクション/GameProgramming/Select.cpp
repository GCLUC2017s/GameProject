#include"Select.h"
#include"CTexture.h"

void StageSelect::init(){
	//�Q�[���^�C�g����\��
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300.0f, 300.0f, 100.0f, 200.0f);
	mStageNo0.setVertex(-300.0f, 200.0f, 300.0, 100.0f);//�\���͈�
	mStageNo0.setColor(1.0f, 1.0f, 1.0f, 1.0f);//�F��
	mStageNo0.setuv(mpTexture, 0, 0, 640, 480);//TGA��̍��W


	//�����Ăق����L�[��\������B
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-120.0f, 140.0f, 120.0f, -140.0f);
	mStageNo1.setVertex(-200.0f, -100.0f, 200.0f, -200.0f);//�\���͈�
	mStageNo1.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mStageNo1.setuv(mpTexture, 0, 0, 640, 480);//TGA��̍��W



	//�����Ăق����L�[��\������B
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-120.0f, 140.0f, 120.0f, -140.0f);
	mStageNo2.setVertex(-200.0f, -100.0f, 200.0f, -200.0f);//�\���͈�
	mStageNo2.setColor(1.0f, 1.0f, 1.0f, 1.0f);
	mStageNo2.setuv(mpTexture, 0, 0, 640, 480);//TGA��̍��W




}



void StageSelect::update(){
	render();
};
void StageSelect::render() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	mStageNo0.render();
	mStageNo1.render();
	mStageNo2.render();
}