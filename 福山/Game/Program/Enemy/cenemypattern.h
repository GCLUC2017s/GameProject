#ifndef CNEMPATT_HPP
#define CNEMPATT_HPP
#include "../Base/CBase.h"
#include "../CGame/CGame.h"
#include"../Enemy\CBoss.h"

/*
�G�l�~�[�̃p�^�[���ɂ��āB

�G�l�~�[�֘A�̕���������Ɉڍs�\��B

�����O��
*/


class CNemPatt:public CBase{
private:
		
	friend	class CEnemy00;
	friend	class CBoss;
	friend	class CEnemy01;
};
#endif