/*
*エネミーのプログラム
*担当者 冨田健斗
*/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "../Base/CBase.h"
#include "../MyNumber/CMyNumber.h"


class  CEnemy : public CBase
{
public:

	CEnemy();


	void Render();

	void Update();

};

#endif