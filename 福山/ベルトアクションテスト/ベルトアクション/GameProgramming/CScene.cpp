//ふくやま
//高橋弘樹
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
		//タイトルの呼び出しを行う
	case 0:
		titlescene.init();
		CGame::status = 1;
		break;
	case 1:
		titlescene.update();
		if (CKey::push(VK_RETURN)){		//returnキーを押すとゲーム開始。
			CGame::status = 2;
		}
		break;

		//ステージの呼び出しを行う
	case 2:
		stage.init();
		CGame::status = 3;
		break;
	case 3:
		stage.update();
		break;

		//ゲームオーバー画面の呼び出しを行う
	case 4:
		out.init();
		CGame::status = 5;
		break;
	case 5:
		out.update();
		if (CKey::once(VK_RETURN)){		//returnキーを押すとタイトルに戻る。
			CGame::status = 0;
		}
		break;

		//リザルト画面の呼び出し（clear）を行う
	case 6:
		clear.init();
		CGame::status = 7;
		break;
	case 7:
		clear.update();
		if (CKey::once(VK_RETURN)){		//returnキーを押すと戻る。
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