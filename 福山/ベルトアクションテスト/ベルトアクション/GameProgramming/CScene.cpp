//�ӂ����
//�����O��
#include "CGame.h"
#include <math.h>	
#include <stdio.h>
#include "CStage.h"
#include "CKey.h"
#include "CGame.h"
#include "CGameclear.h"
#include "CGameover.h"
#include "Title.h"
#include "TitleScene.h"


void loop() {
	switch (CGame::status) {
		//�^�C�g���̌Ăяo�����s��
	case 0:
		titlescene.init();
		CGame::status = 1;
		break;
	case 1:
		titlescene.update();
		if (CKey::push(VK_RETURN)){		//return�L�[�������ƃQ�[���J�n�B
			CGame::status = 2;
		}
		break;

		//�X�e�[�W�̌Ăяo�����s��
	case 2:
		stage.init();
		CGame::status = 3;
		break;
	case 3:
		stage.update();
		break;

		//�Q�[���I�[�o�[��ʂ̌Ăяo�����s��
	case 4:
		out.init();
		CGame::status = 5;
		break;
	case 5:
		out.update();
		if (CKey::once(VK_RETURN)){		//return�L�[�������ƃ^�C�g���ɖ߂�B
			CGame::status = 0;
		}
		break;

		//���U���g��ʂ̌Ăяo���iclear�j���s��
	case 6:
		clear.init();
		CGame::status = 7;
		break;
	case 7:
		clear.update();
		if (CKey::once(VK_RETURN)){		//return�L�[�������Ɩ߂�B
			CGame::status = 8;
		}

		break;
	case 8:


		break;
	case 9:



		break;

	};

}

void init() {
}

void update() {


}