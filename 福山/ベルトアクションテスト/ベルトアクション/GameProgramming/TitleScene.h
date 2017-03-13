#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "define.h"
#include "CMap.h"
#include "CGoal.h"
#include "CPlayer.h"
#include "CUserInterface.h"
#include "CDownGimmick.h"
#include "CWindmill.h"
#include "CWind.h"
#include "Title.h"

class TitleScene {
public:
	CPlayer mPlayer;
	CMap map;
	Title title;
	CRectangle mFade;	//�A���[�g�\���l�p�`


	TitleScene();

	//�ǐՃ��[�h���̉��o
	int  mAlertCnt;		//�A���[�g����p�J�E���^
	int  mAlertLevel;	//�A���[�g�\���p�f�[�^
	bool Alertenabled;


	float Alertbottom, Alerttop;
	float count;//�X�N���[�����o�̂���
	float save_player_x; //�ۑ��p

	int status;

	float FirstX;

	float Save;



	void init();
	void update();
	/* �ǐՒ��\��
	*/
	void FadeDisp();
};
#endif