#ifndef GAMEMAIN_HPP
#define GAMEMAIN_HPP
#include "../Scene/CScene.h"

#define JUMP_FIRST_SPEED 0.2

class CGameMain :public CScene{
public:

	enum EStatus{
		E_INIT,E_MAIN
	};
	EStatus status;

	CGameMain();
	void Init();
	void Update();
	
};


#endif