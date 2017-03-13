#include "TitleScene.h"
#include "CGame.h"
#include "CKey.h"


//������

//�ŏ��̓ǂݍ��݂��s���R


TitleScene::TitleScene() :status(0), Alerttop(0.0f), Alertbottom(0.0f), Alertenabled(true){}

void TitleScene::init() {

	CGame::mMapCols = MAP_COLS;		//�}�b�v�T�C�Y�̐ݒ�i�񐔁j
	CGame::mMapRows = MAP_ROWS;		//�}�b�v�T�C�Y�̐ݒ�i�s���j
	//	CGame::mDispCols = 30;
	//	CGame::mDispRows = 30;


	CGame::mDispCols = 640 * 0.012;	//�\���G���A�̃T�C�Y�ݒ�i�񐔁j
	CGame::mDispRows = 480 * 0.012;	//�\���G���A�̃T�C�Y�ݒ�i�s���j


	mPlayer.init();
	mPlayer.setPos();
	map.init();
	title.init();




	status = 0;
	FirstX = -MAP_LIMIT_X / 2.5;
	count = mPlayer.mPos.y;


	mAlertCnt = 0;		//�A���[�g����J�E���^��������
	mAlertLevel = 0;	//�A���[�g���x���ݒ�
	//�A���[�g�\���̑傫�����}�b�v�S�̂ɐݒ�
	mFade.setVertex(
		-CGame::mMapCols / 2.0,
		CGame::mMapRows / 2.0,
		CGame::mMapCols / 2.0,
		-CGame::mMapRows / 2.0);
	//���F�ɐݒ�
	mFade.setColor(1.0f, 1.0f, 1.0f, 1.0f);

	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
	//�\������G���A���w��
	gluOrtho2D(
		-CGame::mDispCols / 2.5 + mPlayer.mPos.x,
		CGame::mDispCols / 2.5 + mPlayer.mPos.x,
		-CGame::mDispRows / 2.0,
		CGame::mDispRows / 2.0);

}

void TitleScene::update() {


	//enemy.update();
	//sasori.update();
	map.update();
	mPlayer.update();
	map.render();

	title.render((CVector2(CGame::mDispCols / 3.0 + FirstX,
		CGame::mDispCols / 2.0 + FirstX - 5.0f)));


	//mPlayer.player.position = mPlayer.mPos;
	//mPlayer.render();

		FirstX += 0.02f;
		//��ʂ̍��W�n��ݒ�
		glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
		glLoadIdentity();	//�s���������
			//�\������G���A���w��
			gluOrtho2D(
				-CGame::mDispCols / 1.0 + FirstX,
				CGame::mDispCols / 1.0 + FirstX,
				-CGame::mDispRows / 1.5,
				CGame::mDispRows / 1.5);

			if (FirstX > MAP_LIMIT_X / 2.5){ 
		
				FirstX = -MAP_LIMIT_X / 2.5;

			} //�S�[���܂ŃX�N���[���ŃQ�[���ɖ߂�
		
}



/* alertDisp
�ǐՃ��[�h�̎��ɂ́A��ʂɐԂ݂�t����
*/
void TitleScene::FadeDisp() {

	mFade.render();

}