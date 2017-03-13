/*
ƒJƒƒ‰‚ÌƒvƒƒOƒ‰ƒ€

*/
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "CBase.h"
#include "CPlayer.h"

class  CCamera : public CBase {
public:

	CPlayer *mPlayer;

	int save_player_x;

	CCamera(){
		
	};

	void Render();

};

#endif