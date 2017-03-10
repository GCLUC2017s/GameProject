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
	int k;

	CTaskManager(){ k = 0; }


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
			mRoot->prev = 0;
			mRoot->next = t;
			mTail = t;
		}
		else{

			t->prev = mTail;
			mTail->next = t;
			mTail = t;

		}
	}
	/*
	Abs 昇順 Decs 降順 
	Abs
	*/

	void AbsR(){
		CTask temp;
		CTask *MoveTask = &temp; //移動用
		CTask *StopTask = &temp; //固定用
		StopTask->next = mRoot;
		MoveTask->next = mRoot->next;

		while (StopTask != mTail){
			StopTask = StopTask->next;
			MoveTask = StopTask->next;
			while (MoveTask != mTail){
				MoveTask = MoveTask->next;
				if (StopTask->mPriorityR > MoveTask->mPriorityR){
						CTask *Save; //保存用 Moveを保存

						Save = MoveTask;

						Save->prev = StopTask->prev; 
						Save->next = StopTask->next; 

						StopTask->prev = MoveTask->prev;
						StopTask->next = MoveTask->next;

						MoveTask = StopTask;
						StopTask = Save;
					
				}
			}
		}

	}

	void DecsR(CTask *t){
		CTask *save_t; //初めのほう
		CTask *task; //

		while (true)
		{
			while (true)
			{

			}

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
			if (*t == T){ //Tとあっているとき
				if (T->prev == 0){  //始まり
					mRoot = mRoot->next;
					mRoot->prev = 0;
					delete *t;
					*t = mRoot;
					break;
				}
				else if (T->next == 0){ //終わり
					mTail = mTail->prev;
					mTail->next = 0;
					delete *t;
					*t = mTail;
					break;
				}
				else{ //中間
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
		
	}

	void Update(){}
	 
};

#endif
