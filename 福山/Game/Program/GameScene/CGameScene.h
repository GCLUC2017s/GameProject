/*
ƒQ[ƒ€ƒV[ƒ“ŠÇ—
’S“–Ò@•y“cŒ’“l
*/
#ifndef GAMEMAIN_HPP
#define GAMEMAIN_HPP
#include "../Scene/CScene.h"

#define JUMP_FIRST_SPEED 0.2

class CGameScene :public CScene{
private:
	float mSaveTime;
public:

	enum EStatus{
		E_INIT,E_MAIN
	};
	EStatus status;

	CGameScene();
	void Init();
	void Update();
	
};


#endif