//�V�[���̃v���O���~���O�i�V�[���}�l�[�W���[�j
/*
�V�[���ƃV�[���}�l�[�W���[������

���݂͂܂�����ɂ͊������Ă��Ȃ��B

*/

//�S���ҁ@�����O��				����e�X�g�@�����s
#include "../Scene/CScene.h"
#include "../Title/CTitleScene.h"

CScene* CScene::mScene = 0;

//GetInstance
CScene* CScene::GetInstance() {
	if (mScene == 0) {
		mScene = new CScene();
	}
	return mScene;
}

//KILL����
void CScene::DeleteScene(){
	if	  (mScene)
	delete mScene;
	mScene = 0;
}

void CScene::ChangeScene(eSceneNo SceneNo) {

	DeleteScene();		//KILL

	switch (SceneNo) {

		//�^�C�g���̌Ăяo�����s��
	case E_TITLE:
		mScene = new CTitleScene;

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
/*
�쓮�p

	//�����V�[���̎w��
	CScene::GetInstance()->ChangeScene(CScene::E_TITLE);

	//�V�[���̃A�b�v�f�[�g
	CScene::GetInstance()->Update();

	//�V�[���̃f���[�g
	CScene::GetInstance()->DeleteScene();



*/