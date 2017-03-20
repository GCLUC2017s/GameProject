/*
*タスクのプログラム
*担当者 冨田健斗
*/
#ifndef TASK_HPP
#define TASK_HPP
#include <stdio.h>
#include <assert.h>
#include "../MyNumber/CMyNumber.h"

class  CTask
{
public:

	CTask *next;
	CTask *prev;
	float mPriorityR; //Rander()のナンバー
	float mPriorityU;//Update()のナンバー
	bool mKillFlag;  //フラグが立っているものを消す
	bool mCharaFlag; //キャラクターのフラグがたっているものにはCol判定
	int mMyNumber;	//種類判断のためのナンバ-
	bool mUiFlag; //UIがあるか判断

	CTask() :next(0), prev(0), mKillFlag(false),mUiFlag(false) ,mCharaFlag(false), mMyNumber(E_ERROR),mPriorityR(E_ERROR),mPriorityU(E_ERROR){};
	virtual ~CTask(){};

	virtual void Init(){};
	virtual void Update(){ 
		assert(mMyNumber  != E_ERROR);
		assert(mPriorityU != E_ERROR);
	};
	virtual void Render(){
		assert(mMyNumber != E_ERROR);
		assert(mPriorityR != E_ERROR);
	};

};


#endif
