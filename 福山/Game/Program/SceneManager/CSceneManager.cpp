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

CSceneManager* CSceneManager::mSceneManager = 0;

//GetInstance
CSceneManager* CSceneManager::GetInstance() {
	if (mSceneManager == 0) {
		mSceneManager = new CSceneManager();
	}
	return mSceneManager;
}

//KILL����
void CSceneManager::DeleteScene(){
	if (mSceneManager)
		delete mSceneManager;
	mSceneManager = 0;
}

void CSceneManager::ChangeScene(eSceneNo SceneNo) {

	DeleteScene();		//KILL

	switch (SceneNo) {

		//�^�C�g���̌Ăяo�����s��
	case E_TITLE:
		mSceneManager = new CTitleScene;

		break;
		//�Z���N�g��ʂ̌Ăяo�����s��

	case E_SELECT:
		//�Q�[����ʂɔ�΂��܂�


		break;
		//�Q�[�����C���̌Ăяo�����s��

	case E_GAMEMAIN:

		break;
		//�Q�[���N���A��ʂ̌Ăяo�����s��

	case E_GAMECLEAR:

		break;
		//�Q�[���I�[�o�[��ʂ̌Ăяo�����s��

	case E_GAMEOVER:

		break;


	};
}

void CSceneManager::SceneMain(){

	CSceneManager::GetInstance()->ChangeScene(CScene::E_TITLE);
	for (int i = 0; i < 10; i++) {
		CSceneManager::GetInstance()->Update();
		CSceneManager::GetInstance()->Update();
	}
	CSceneManager::GetInstance()->DeleteScene();


	getchar();

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