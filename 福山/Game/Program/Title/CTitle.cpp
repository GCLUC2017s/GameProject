#include"../Title/CTitle.h"
#include"../Graphic/CTexture.h"
#include "../MyNumber/CMyNumber.h"

//TitleScene�ŕ\�������e�N�X�`���̐ݒ�B

void CTitle::Init(){

	//�Q�[���^�C�g����\��
	mpTitleLogo = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTitleLogo->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	
		 mTitleLogo.SetUv(mpTitleLogo, 0, 0, 640, 480);//TGA��̍��W

		 mpPleaseKey = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
		 mpPleaseKey->load("gameTitle.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	
		mPleaseKey.SetUv(mpPleaseKey, 0, 0, 640, 480);//TGA��̍��W

	

}
CTitle::~CTitle(){
	if (mpTexture){
		delete mpTexture;
		mpTexture = 0;
	}
}
CTitle::CTitle() : mpTexture(0){
	mMyNumber = E_TITLE;
	mPriorityR = E_TITLE;
	mPriorityU = E_TITLE;

	mTitleLogo.SetVertex(-7.0f, 2.0f, 2.0, -1.0f);//�\���͈�
	mTitleLogo.SetColor(1.0f, 1.0f, 1.0f, 1.0f);//�F��

	mPleaseKey.SetVertex(-5.0f, -2.0f, 0.0f, -3.0f);//�\���͈�
	mPleaseKey.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

}
void CTitle::Update(){

};
void CTitle::Render(CVector2 pos) {


	mTitleLogo.position = pos;
	mTitleLogo.position.y = DISP_Y / 5;

	mPleaseKey.position = pos;
	mPleaseKey.position.y = DISP_Y / 20;

	mTitleLogo.Render();
	mPleaseKey.Render();
}
