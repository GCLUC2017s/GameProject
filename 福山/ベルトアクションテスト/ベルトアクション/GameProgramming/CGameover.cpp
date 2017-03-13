#include"CGameover.h"
#include"CTexture.h"

void CGameover::init(){
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("GAMEOVER.tga");	//�e�N�X�`���t�@�C���ǂݍ���

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	gameover.setVertex(-320.0f, 240.0f, 320.0f, -240.0f);

	gameover.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	gameover.setuv(mpTexture, 0, 0, 680, 420);
}
void CGameover::update(){
	render();
};
void CGameover::render() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	gameover.render();
}