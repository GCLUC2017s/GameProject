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

	CTask *next;
	CTask *prev;
	int mPriorityR; //Rander()のナンバー
	int mPriorityU;//Update()のナンバー
	int mMyNumber;	//種類判断のためのナンバー

	CTask() :next(0), prev(0){};
	virtual ~CTask(){};

	virtual void Init(){};
	virtual void Update(){};
	virtual void Render(){};

};


#endif
