#include "define.h"
#include "CMap.h"
#include "CGoal.h"
#include "CPlayer.h"
#include "CUserInterface.h"
#include "CDownGimmick.h"
#include "CWindmill.h"
#include "CWind.h"
#include "Title.h"
#include"Enemy.h"

class CStage {
public:
	CPlayer mPlayer;
	CMap map;
	Title title;
	Enemy00 mEnemy00;

	CStage();

	//�ǐՃ��[�h���̉��o
	int  mAlertCnt;		//�A���[�g����p�J�E���^
	int  mAlertLevel;	//�A���[�g�\���p�f�[�^
	CRectangle mAlert;	//�A���[�g�\���l�p�`
	bool Alertenabled;


	float Alertbottom, Alerttop;
	float count;//�X�N���[�����o�̂���
	float first_y; //���߂̃X�N���[���̂���
	float hoz_y; //�S�[���ŏ����~�܂邽�߂̕ϐ�
	float save_player_x; //�ۑ��p

	int status;

	float FirstX;

	float Save;



	void init();
	void update();
	/* �ǐՒ��\��
	*/
	void alertDisp();
};
