//�V�[���̃v���O���~���O�i�V�[���}�l�[�W���[�j
/*
�V�[���ƃV�[���}�l�[�W���[������

���݂͂܂�����ɂ͊������Ă��Ȃ��B

�V�[���}�l�[�W���[�ƃV�[���ɕ����\��

*/

//�S���ҁ@�����O��				����e�X�g�@�����s
#include "../Scene/CScene.h"
#include "../Title/CTitleScene.h"
#include"CSceneManager.h"
#include "../GameMain/CGameMain.h"
#include "../Key/CKey.h"

CSceneManager* CSceneManager::mSceneManager = 0;

CScene* mScene=0;

//GetInstance
CSceneManager* CSceneManager::GetInstance() {
	if (mSceneManager == 0) {
		mSceneManager = new CSceneManager();
	}
	return mSceneManager;
}

//KILL����
void CSceneManager::DeleteScene(){
	if (mScene)
		delete mScene;
	mScene = 0;
}

void CSceneManager::ChangeScene(eSceneNo SceneNo) {

	DeleteScene();		//KILL

	switch (SceneNo) {

		//�^�C�g���̌Ăяo�����s��
	case eSceneNo::E_TITLE:
		mScene = new CTitleScene;
		mScene->Init();

		break;
		//�Z���N�g��ʂ̌Ăяo�����s��

	case eSceneNo::E_SELECT:
		//�Q�[����ʂɔ�΂��܂�


		break;
		//�Q�[�����C���̌Ăяo�����s��

	case eSceneNo::E_GAMEMAIN:
		mScene = new CGameMain;
		

		break;
		//�Q�[���N���A��ʂ̌Ăяo�����s��

	case eSceneNo::E_GAMECLEAR:

		break;
		//�Q�[���I�[�o�[��ʂ̌Ăяo�����s��

	case eSceneNo::E_GAMEOVER:

		break;


	};
}

void CSceneManager::SceneMain(){
	switch (status)
	{
	case 0:

		CSceneManager::GetInstance()->ChangeScene(eSceneNo::E_TITLE);

		status = 1;
		break;
	case 1:

		mScene->Update();

		break;
	}

}

/*
�쓮�p

//�����V�[���̎w��
CScene::GetInstance()->ChangeScene(CScene::E_TITLE);

//�V�[���̃A�b�v�f�[�g
CScene::GetInstance()->Update();

//�V�[���̃f���[�g
CScene::GetInstance()->DeleteScene();



*/