#include "Global.h"

char g_tutorialDataPath[TUTORIAL_MAX][FILE_NAME] =
{
	"TutoText/TutorialM.txt",	//男選択時チュートリアルファイル
	"TutoText/TutorialW.txt",	//女選択時
};
int  g_tutorialNo = 0;	//初期値は男 1なら女