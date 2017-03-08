/*
*タスクのマネージャーのプログラム
*担当者　冨田健斗
*/
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include "CTask.h"

class  CTaskManager
{
public:
	CTask *mRoot;
	CTask *mTail;

	CTaskManager(){}


	~CTaskManager(){
		CTask *t;
		t = mRoot;
		while (t != 0)
		{
			mRoot = t->next;
			delete t;
			t = mRoot;
		}
	}

	/*
	追加処理
	後ろに追加していく形
	処理手順
	root == 0 が　何もないとき
	root != 0 が  あるとき
	*/
	void Add(CTask  *t){
		if (mRoot == 0){
			mRoot = t;
			mTail = t;
		}
		else{

			t->prev = mTail;
			mTail->next = t;
			mTail = t;
		}
	}

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
	void Kill(CTask **t){

		CTask temp; //仮に作るもの
		CTask *T = &temp; //順番を見る
		T->next = mRoot;

		while (T != mTail)
		{
			T = T->next;
			if (*t == mRoot){  //始まり
				mRoot = mRoot->next;
				mRoot->prev = 0;
				delete *t;
				*t = mRoot;
				break;
			}
		   if (*t == mTail){ //終わり
				mTail = mTail->prev;
				mTail->next = 0;
				delete *t;
				*t = mTail;
				break;
			}
		   if (*t == T){ //中間
			   CTask *save_T; //仮の保存場所

			   			T->prev->next = T->next;
						T->next->prev = T->prev;

			   			save_T = T->prev;
			   			delete *t;
			   			*t = save_T;
			   
			   break;
		   }

		}
		
	}

	void Update(){}
	 
};

#endif
