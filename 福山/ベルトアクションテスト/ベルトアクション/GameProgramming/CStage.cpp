#include "CStage.h"
#include "CGame.h"
#include "CKey.h"



CStage::CStage() :status(0),Alerttop(0.0f),Alertbottom(0.0f),Alertenabled(true){}

void CStage::init() {

	CGame::mMapCols = MAP_COLS;		//�}�b�v�T�C�Y�̐ݒ�i�񐔁j
	CGame::mMapRows = MAP_ROWS;		//�}�b�v�T�C�Y�̐ݒ�i�s���j
//	CGame::mDispCols = 30;
//	CGame::mDispRows = 30;


		CGame::mDispCols = 640*0.012;	//�\���G���A�̃T�C�Y�ݒ�i�񐔁j
		CGame::mDispRows = 480*0.012;	//�\���G���A�̃T�C�Y�ݒ�i�s���j


	mPlayer.init();
	mPlayer.setPos();
	mEnemy00.init();
	mEnemy00.setPos();

	map.init();
	title.init();


	status = 0;
	FirstX = -MAP_LIMIT_X / 2.5;

	//enemy.mpPlayer = &player;
	//sasori.init();	//�T�\���̏�����
	//sasori.setPos(4, 9, CVector2(0.0f, 1.0f));	//�T�\���̔z�u


	//�v���C���[�̔z�u


	mAlertCnt = 0;		//�A���[�g����J�E���^��������
	mAlertLevel = 0;	//�A���[�g���x���ݒ�
	//�A���[�g�\���̑傫�����}�b�v�S�̂ɐݒ�
	mAlert.setVertex(
		-CGame::mMapCols / 2.0,
		Alerttop,
		CGame::mMapCols / 2.0,
		Alertbottom);
	//�������̐ԐF�ɐݒ�
	mAlert.setColor(1.0f, 0.0f, 0.0f, 0.5f);

	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
	//�\������G���A���w��
	gluOrtho2D(
		-CGame::mDispCols / 2.5+mPlayer.mPos.x,
		CGame::mDispCols / 2.5 + mPlayer.mPos.x,
		-CGame::mDispRows / 2.0 ,
		CGame::mDispRows / 2.0 );
		
}

void CStage::update() {

	//enemy.update();
	//sasori.update();
	map.update();
	mPlayer.update();
	mEnemy00.update();

	map.render();

	mPlayer.m_Player.position = mPlayer.mPos;
	mPlayer.render();

	mEnemy00.m_Enemy00.position = mEnemy00.mPos;
	mEnemy00.render();


	if (CKey::push(VK_RETURN)) {
	
		mEnemy00.init();
		mEnemy00.update();
		mEnemy00.setPos();
		mEnemy00.m_Enemy00.position = mEnemy00.mPos;
		mEnemy00.render();

	}


			//�\������G���A���w��
			gluOrtho2D(
				-CGame::mDispCols / 2.0 + Save,
				CGame::mDispCols / 2.0 + Save,
				-CGame::mDispRows / 2.5,
				CGame::mDispRows / 2.5);

			//��ʂ̍��W�n��ݒ�
			glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
			glLoadIdentity();	//�s���������
			//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
			const float camera_x = CGame::mDispCols;
			const float camera_y = CGame::mDispRows;
			const float area_x = MAP_LIMIT_X / 2;
			//�\������G���A���w��
			if (-area_x <= -camera_x + mPlayer.mPos.x+2 &&
				area_x >= camera_x + mPlayer.mPos.x+2){

				save_player_x = mPlayer.mPos.x+2;

				gluOrtho2D(
					-camera_x + mPlayer.mPos.x+2,
					camera_x + mPlayer.mPos.x+2,
					-camera_y,
					camera_y);
			}
			else{
				gluOrtho2D(
					-camera_x + save_player_x,
					camera_x + save_player_x,
					-camera_y,
					camera_y);
			}

		}



	/*
	//��ʂ̍��W�n��ݒ�
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();	//�s���������
	//	gluOrtho2D(-CGame::mDispCols / 2.0, CGame::mDispCols / 2.0, -CGame::mDispRows / 2.0, CGame::mDispRows / 2.0);
    const float camera_x = CGame::mDispCols;
	const float camera_y = CGame::mDispRows;
	const float area_x = MAP_LIMIT_X / 2;
	//�\������G���A���w��
	if (-area_x <=  -camera_x+player.mPos.x &&
	     area_x >= camera_x + player.mPos.x){

		save_player_x = player.mPos.x;

		gluOrtho2D(
			-camera_x + player.mPos.x,
			camera_x + player.mPos.x,
			-camera_y,
			camera_y);
	}
	else{
		gluOrtho2D(
			-camera_x + save_player_x,
			camera_x +  save_player_x ,
			-camera_y,
			camera_y);
	}
	*/




/* alertDisp
�ǐՃ��[�h�̎��ɂ́A��ʂɐԂ݂�t����
*/
void CStage::alertDisp() {

}
