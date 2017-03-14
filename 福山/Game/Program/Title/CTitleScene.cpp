//�^�C�g���̃v���O���~���O
//�S���ҁ@�����O��
#include "CTitleScene.h"
#include "../Key/CKey.h"
#include"../Map/CMap.h"

//CScene eSceneNo TITLE

//CTitleScene::CTitleScene(){}

void CTitleScene::Init() {


	FirstX = -MAP_LIMIT_X / 2.5;
	mMap.Init();
	mTitle.Init();
	
	mFade.SetVertex(
		-MAP_LIMIT_X / 2.0,
	     MAP_LIMIT_Y / 2.0,
		 MAP_LIMIT_X / 2.0,
		-MAP_LIMIT_Y / 2.0);
	//���F�ɐݒ�
	mFade.SetColor(1.0f, 1.0f, 1.0f, alpha=1.0f);

	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
	//�\������G���A���w��
	gluOrtho2D(
		-MAP_LIMIT_X / 2.5,
		MAP_LIMIT_X / 2.5,
		-MAP_LIMIT_Y / 2.0,
		MAP_LIMIT_Y / 2.0);




}

void CTitleScene::Update() {

	//Update����

	mMap.Update();
	mMap.Render();

	
	mTitle.Render((CVector2(MAP_LIMIT_X / 3.0 + FirstX,
	MAP_LIMIT_X / 2.0 + FirstX - 5.0f)));




	FirstX += 0.02f;



	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	gluOrtho2D(
		-MAP_LIMIT_X / 1.0 + FirstX,
		MAP_LIMIT_X / 1.0 + FirstX,
		-MAP_LIMIT_Y / 1.5,
		MAP_LIMIT_Y / 1.5);


	if (FirstX > MAP_LIMIT_X / 2.5){
	//	alpha = 1.0f;
		FirstX = -MAP_LIMIT_X / 2.5;
	} //�}�b�v�̒[�܂ōs���ƍŏ��ɖ߂��B

	//Update�I��


	//�G���^�[�L�[���������Ƃ��ɃV�[�����Z���N�g��ʂɑւ��鏈�����s���B
	if (CKey::push(VK_RETURN)) 
	{
	}


}