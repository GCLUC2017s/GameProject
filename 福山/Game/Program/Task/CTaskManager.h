/*
*タスクのマネージャーのプログラム
*担当者　冨田健斗
*/
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include "CTask.h"
#include <assert.h> 

class  CTaskManager
{
private:
	static CTaskManager *mTaskManager;
	void SwapTask(CTask **p, CTask **n);

	CTaskManager();

public:
	CTask *mRoot;
	CTask *mTail;
	bool mFlagAllkill;
	static CTaskManager *GetInstance(); //GetInstance

	~CTaskManager();

	/*
	追加処理
	後ろに追加していく形
	処理手順
	root == 0 が　何もないとき
	root != 0 が  あるとき
	*/
	void Add(CTask  *t);

	/*
	使い方
	Absは昇順　
	RはRebder用
	UはUpdate用
	*/



	/*
	デリート処理

	※注意　Killのほうは " **t  なので使い方に注意が必要  "

	プログラムの順番

	Taskのアドレスが始まりの時
				↓
	Taskのアドレスが終わりの時
				↓
	Taskのアドレスが中間の時

	*/

	void Sort(CTask **t);

	void AbsR();
	void AbsU();
	void Kill(CTask **t);
	void AllKill();
	void AllUpdate();
	void AllRender();
	void AllInit();
	
};

#endif
