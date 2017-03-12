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
public:
	CTask *mRoot;
	CTask *mTail;

	CTaskManager(){};


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
	並び替えしたい CTask *tを &t の形で，引数として入れる
	Absは昇順　Descは降順
	RはRebder用
	UはUpdate用
	*/

	void SwapTask(CTask **p, CTask **n){ //入れ替え処理
		CTask *s = *n;
		*n = *p;
		*p = s;

	}

	void AbsR();


	void DescR();

	void AbsU();


	void DescU();

	

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

	void Kill(CTask **t);

	void Update(){}
	 
};

#endif
