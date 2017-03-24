//�^�C�g���̃v���O���~���O
//�S���ҁ@�����O��
#include "CTitleScene.h"
#include "../Key/CKey.h"
#include"../Map/CMap.h"
#include "../Player/CPlayer.h"
#include "../CGame/CGame.h"
#define SC_SPEED 0.025f
#define FILE_TEX "../CG\\GameScreen\\"
#define R_SIZE_FILTER		-DISP_X-2.0f,DISP_Y,DISP_X,-DISP_Y
#define F_SPEEDBASE	0.01f //�t�F�[�h�̃X�s�[�h
#define F_ALFMAX 1.0f //�t�F�[�h�̏��
//CScene eSceneNo TITLE

//CTitleScene::CTitleScene(){}

void CTitleScene::Init() {
	mFilterTex = new CTexture();
	mFilterTex->load("../CG\\Filter\\filter.tga");

	mRectFilter.SetVertex(R_SIZE_FILTER);
	mRectFilter.SetColor(0.0f, 0.0f, 0.0f, 0.0f);
	mRectFilter.SetUv(mFilterTex, 0, 0, 10, 10);
	mFirstX = first_pos.x;
	mMap.Init();
	mTitle.Init();
	mExplain.Init();

}

bool FlagRectA(const CRectangle &rect,bool flag){ //�A���t�@�`�����l�����������Ă��邩���Ȃ����t�F�[�h�̉��o�Ɏg��
	if (flag){
		if (rect.triangle1.a >= 1.0f){
			return true;
		}
	}
	else
	{
		if (rect.triangle1.a <= 0.0f){
			return true;
		}
	}
	return false;
}

void CTitleScene::Update() {
	//Update����

	mMap.Update();
	mMap.Render();
	mRectFilter.Render();

	switch (status)
	{
  case	E_TITLE_SCENE:
	  mTitle.Update();
	  mTitle.Render(CVector2(mFirstX, 0));
		break;
  case E_EXPLAIN_SCENE:
		mExplain.Render(CVector2(mFirstX, 0));
		break;
	}




	const float arearight_x = character_limit_right - (DISP_X / 2) - SIZE_PLAYER_X * 4;


	switch (mStarusFade)
	{
	case E_FADE:
		CGame::Fade(F_SPEEDBASE, &mRectFilter, F_ALFMAX);
		if (FlagRectA(mRectFilter, true)){
			mStarusFade = E_FADEOUT;
			mFirstX = first_pos.x;
		}
		break;
	case E_FADEOUT:
		CGame::FadeOut(F_SPEEDBASE, &mRectFilter);
		if (FlagRectA(mRectFilter, false)){
			mStarusFade = E_NOFADE;
		}
		break;
	case E_NOFADE:
		mFirstX += SC_SPEED;
		if (mFirstX >= arearight_x){
			mStarusFade = E_FADE;
		}
		break;
	}
	mRectFilter.position = CVector2(mFirstX, 0);



	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	gluOrtho2D(-DISP_X + mFirstX, DISP_X + mFirstX, -DISP_Y, DISP_Y);
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