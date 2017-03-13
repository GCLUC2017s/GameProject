#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "../Define/define.h"
#include "../Title/CTitle.h"
#include"../Map/CMap.h"

class CTitleScene {
public:
	CMap map;
	CTitle title;
	CRectangle mFade;	//�A���[�g�\���l�p�`


	CTitleScene();

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



	void Init();
	void Update();
	/* �ǐՒ��\��
	*/
	void FadeDisp();
};
#endif