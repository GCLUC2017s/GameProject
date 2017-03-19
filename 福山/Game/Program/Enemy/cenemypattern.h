#ifndef CNEMPATT_HPP
#define CNEMPATT_HPP
#include "../Base/CBase.h"
#include "../CGame/CGame.h"
#include"../Enemy\CBoss.h"

/*
エネミーのパターンについて。

エネミー関連の物をこちらに移行予定。

高橋弘樹
*/


class CNemPatt:public CBase{
private:
		
	friend	class CEnemy00;
	friend	class CBoss;
	friend	class CEnemy01;
};
#endif