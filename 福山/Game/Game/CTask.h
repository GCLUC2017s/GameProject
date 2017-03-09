/*
*タスクのプログラム
*担当者 冨田健斗
*/
#ifndef TASK_HPP
#define TASK_HPP

#include <stdio.h>


class  CTask
{
public:
	float mHitPoint;
	CTask *next;
	CTask *prev;
	int mPriorityR; //Rander()のナンバー
	int mPriorityU;//Update()のナンバー

	CTask() :next(0), prev(0),mHitPoint(0){};
	~CTask(){};

	virtual void Update(){};

};

#endif
