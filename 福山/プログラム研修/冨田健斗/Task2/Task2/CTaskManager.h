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
	使い方
	並び替えしたい CTask *tを &t の形で，引数として入れる
	Absは昇順　Descは降順
	RはRebder用
	UはUpdate用
	*/

	void AbsR(){
			/*バブルソート*/
			CTask temp;
			CTask *back_t = &temp;//後ろ用
			CTask *before_t;//前用

			temp.next = mRoot;
			back_t->next = temp.next;
			before_t = temp.next;
			

			while (before_t != mTail){ //後ろのタスク
				back_t = back_t->next;


				if (back_t != mTail){ //前のタスク
					before_t = before_t->next;

					if (back_t->mPriorityR < before_t->mPriorityR){
						CTask *save0;
						//Before側のセーブ
						save0 = before_t;
						before_t->prev = back_t->prev;
						save0 = back_t->next->next;
						save0->next = back_t;
						back_t->prev = before_t;
						back_t->next = before_t->next;
						before_t->next->prev = back_t;
						mRoot = before_t;

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
