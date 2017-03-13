#include "CGameMain.h"

CGameMain::CGameMain(){}

void CGameMain::Init(){
	taskmanger.Add(new CMap);
	taskmanger.Add(new CCamera);
	taskmanger.Add(new CPlayer);
	taskmanger.Add(new CEnemy);
}

void CGameMain::Update(){

	switch (status)
	{
	case E_INIT:
		Init();

		task = taskmanger.mRoot;
		while (task != 0)
		{
			task->Init();
			task = task->next;
		}
		status = E_MAIN;

		break;
	case E_MAIN:
		task = taskmanger.mRoot;

		taskmanger.AbsR();

		/*‚·‚×‚Ä‚ÌRender•\Ž¦*/
		while (task != 0)
		{

			task->Update();
			task->Render();
			task = task->next;

		}



		break;

	}

	

}