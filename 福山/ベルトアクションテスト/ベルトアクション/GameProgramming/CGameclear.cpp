#include"CGameclear.h"
#include"CTexture.h"

void CGameclear::init(){
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("GAMECLEAR.tga");	//�e�N�X�`���t�@�C���ǂݍ���

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	clear.setVertex(-320.0f, 240.0f, 320.0f, -240.0f);

	clear.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	clear.setuv(mpTexture, 0, 0, 640, 480);
}
void CGameclear::update(){
	render();
};
void CGameclear::render() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320.0f, 320.0f, -240.0f, 240.0f);
	clear.render();
}