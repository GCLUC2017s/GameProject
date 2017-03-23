//�^�C�g���̃v���O���~���O
//�S���ҁ@�����O��
#include "CTitleScene.h"
#include "../Key/CKey.h"
#include"../Map/CMap.h"
#include "../Player/CPlayer.h"


//CScene eSceneNo TITLE

//CTitleScene::CTitleScene(){}

void CTitleScene::Init() {


	FirstX = first_pos.x;
	mMap.Init();
	mTitle.Init();
	mExplain.Init();

}

void CTitleScene::Update() {
	//Update����

	mMap.Update();
	mMap.Render();

	switch (status)
	{
  case	E_TITLE_SCENE:
	  mTitle.Update();
	  mTitle.Render(CVector2(FirstX, 0));
		break;
  case E_EXPLAIN_SCENE:
		mExplain.Render(CVector2(FirstX, 0));
		break;
	}

	FirstX += 0.02f;



	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	gluOrtho2D(-DISP_X+ FirstX,DISP_X  + FirstX,-DISP_Y ,DISP_Y);


	if (FirstX > DISP_X / 2.0){
	//	alpha = 1.0f;
		FirstX = first_pos.x;
	} //�}�b�v�̒[�܂ōs���ƍŏ��ɖ߂��B

	//Update�I��


	//�G���^�[�L�[���������Ƃ��ɃV�[�����Z���N�g��ʂɑւ��鏈�����s���B
	if (CKey::push(VK_RETURN))
	{
		status = E_EXPLAIN_SCENE;
	}

	if (CKey::push(VK_RETURN) && mExplain.patternflag==true)
	{
		CSceneManager::GetInstance()->ChangeScene(eSceneNo::E_GAMEMAIN);
	}


}