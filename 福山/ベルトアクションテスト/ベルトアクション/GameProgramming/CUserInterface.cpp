#include "CUserInterface.h"
#include "CGame.h"

float UserInterface::gaugex;

void UserInterface::init() {

	tex_suuzi = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐻
	tex_suuzi->load("����.tga");

	tex_moji = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	tex_moji->load("���Ԑ���.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	mRect_moji.setuv(tex_moji, 0, 0, 1000, 200);	//�e�N�X�`���̎g�p�ݒ�

	tex_window = new CTexture();
	tex_window->load("�Q�[�W.tga");
	mRect_window.setuv(tex_window, 0, 0, 900, 300);
	
	tex_push = new CTexture();
	tex_push->load("PushKey.tga");
	mRect_push.setuv(tex_push, 0, 0, 400, 300);

	//�l�p�`�̒��_�ݒ�
	mRect_push.setVertex(-CGame::mDispCols/2.5f, CGame::mDispRows/2.5f,CGame::mDispRows/2.5f, -CGame::mDispCols /2.5f);
	//�l�p�`�̐F��ݒ�
	mRect_push.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	ena_push = false;
	gaugex = 1.5f;
	strtex = tex_suuzi;
	seisuu = MAX_COUNT;
	syousuu = 0;
	size = 1.0f;

}

UserInterface::~UserInterface() {
	if (mpTexture) {
		//�e�N�X�`�����g���Ă���΃C���X�^���X�폜
		delete mpTexture;
		mpTexture = 0;
	}
}
UserInterface::UserInterface() : mpTexture(0),seisuu(MAX_COUNT),syousuu(0),size(0.5f){
	gaugex = 1.5f;
	//�l�p�`�̒��_�ݒ�
	ena_push = false;
	mRect_moji.setVertex(-1.3f, 0.7f, 1.3f, -0.7f);
	//�l�p�`�̐F��ݒ�
	mRect_moji.setColor(0.8f, 1.0f, 1.0f, 1.0f);

	//�l�p�`�̒��_�ݒ�
	mRect_window.setVertex(-1.5f, 0.5f, 1.5f, -0.5f);
	//�l�p�`�̐F��ݒ�
	mRect_window.setColor(1.0f, 1.0f, 1.0f, 1.0f);	

	//�l�p�`�̒��_�ݒ�
	mRect_gauge.setVertex(-gaugex, 0.5f, gaugex, -0.5f);
	//�l�p�`�̐F��ݒ�
	mRect_gauge.setColor(0.0f, 0.8f, 0.0f, 1.0f);


}


void UserInterface::update(){
	if (syousuu == 0){	seisuu -= 1;}
	if (syousuu <= 0){	syousuu = 60;}
	if (seisuu < 0)  {	seisuu = MAX_COUNT;}
	syousuu -= 1;
};

void UserInterface::render(CVector2 pos) {
	CVector2 hoz_pos = CVector2(pos.x - 3.5f,pos.y - 1.0f);//�ۑ��p&&�����p
	
	//������̐ݒ�
	if (syousuu >= 10){sprintf(str, "%d.%d", seisuu, syousuu);}
	else{			   sprintf(str, "%d.0%d", seisuu,syousuu);}

	if(seisuu == 10){	mRect_moji.position = CVector2(hoz_pos.x + 1, hoz_pos.y + 0.35f);}
	else{				mRect_moji.position = CVector2(hoz_pos.x , hoz_pos.y + 0.35f);}
	//������̕`��
	strtex.render(str, CVector2(hoz_pos), 0.6f, 0.7f, 1.0f, 1.0f, 1.0f);
	mRect_moji.render();
	mRect_window.position = hoz_pos;
	mRect_window.position.x = -CGame::mDispCols / 3;
	mRect_gauge.position = CVector2(mRect_window.position.x+gaugex-1.5f,mRect_window.position.y  );
	mRect_gauge.setVertex(-gaugex, 0.5f, gaugex, -0.5f);
	mRect_gauge.render();
	mRect_window.render();
	if (ena_push){
		mRect_push.render();
	}


}

void UserInterface::setPos(int row, int col) {

}