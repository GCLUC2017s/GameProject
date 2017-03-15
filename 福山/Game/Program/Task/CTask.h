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
	float mPriorityR; //Rander()のナンバー
	float mPriorityU;//Update()のナンバー
	bool mKillFlag;  //フラグが立っているものを消す
	int mMyNumber;	//種類判断のためのナンバー
	float mSaveR;	//sort判断用するか
	CTask() :next(0), prev(0),mPriorityR(0.0f),mPriorityU(0.0f),mKillFlag(false),mSaveR(0.0f){};
	virtual ~CTask(){};

	virtual void Init(){};
	virtual void Update(){};
	virtual void Render(){};

};


#endif
