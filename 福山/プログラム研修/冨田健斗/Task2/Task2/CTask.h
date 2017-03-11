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
	int mBirthday_No;//生まれた日
	static float count; //全部のタスク数


	CTask() :next(0), prev(0), mHitPoint(0){};
	virtual ~CTask(){};

	virtual void Update(){};
	virtual void Render(){};

};


#endif
