//�V�[���̃v���O���~���O�i�V�[���}�l�[�W���[�j
//�S���ҁ@�����O��				����e�X�g�@�����s
#include "../Scene/CScene.h"
#include "../Title/CTitleScene.h"

CScene *m_currScene;

CScene *CScene::mScene = new CScene();

void CScene::ChangeScene(eSceneNo no)
{
	mNextStatus = no;
}

void CScene::Update() {

	delete(m_currScene);

	switch (mNextStatus) {

		//�^�C�g���̌Ăяo�����s��
	case E_TITLE:
		m_currScene = new CTitleScene;


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
