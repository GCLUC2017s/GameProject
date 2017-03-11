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

	void SwapTask(CTask **p, CTask **n){ //入れ替え処理
		CTask *s = *n;
		*n = *p;
		*p = s;

	}

	void AbsR(){
		/*バブルソート*/
		CTask temp;
		CTask *p = &temp;//後ろ用
		CTask *n = &temp;//前用

		p->next = mRoot;
		n->next = mRoot;
	

		while (p->next != mTail){ //後ろのタスク
			p = p->next;
			n = p->next;
			if (p->mPriorityR > n->mPriorityR){
				CTask sp, sn;
				printf("nは%dです\n", n->mBirthday_No);
				printf("入れ替え\n");
				SwapTask(&p, &n);

				/*保存*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*左回りに順番を変える*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*前後の順番を変える*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//入れ替えが終わりに行われた時
					mTail = n;
				}
				/*入れ替えが中間の時*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
			}
		}
	}


	void DescR(){
		/*バブルソート*/
		CTask temp;
		CTask *p = &temp;//後ろ用
		CTask *n = &temp;//前用

		p->next = mRoot;
		n->next = mRoot;


		while (p->next != mTail){ //後ろのタスク
			p = p->next;
			n = p->next;
			if (p->mPriorityR < n->mPriorityR){
				CTask sp, sn;
				printf("nは%dです\n", n->mBirthday_No);
				printf("入れ替え\n");
				SwapTask(&p, &n);

				/*保存*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*左回りに順番を変える*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*前後の順番を変える*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//入れ替えが終わりに行われた時
					mTail = n;
				}
				/*入れ替えが中間の時*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
			}
		}
	}

	void AbsU(){
		/*バブルソート*/
		CTask temp;
		CTask *p = &temp;//後ろ用
		CTask *n = &temp;//前用

		p->next = mRoot;
		n->next = mRoot;


		while (p->next != mTail){ //後ろのタスク
			p = p->next;
			n = p->next;

			if (p->mPriorityU > n->mPriorityU){

				CTask sp, sn;
				SwapTask(&p, &n);

				/*保存*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*左回りに順番を変える*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*前後の順番を変える*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//入れ替えが終わりに行われた時
					mTail = n;
				}
				/*入れ替えが中間の時*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
			}
		}
	}


	void DescU(){
		/*バブルソート*/
		CTask temp;
		CTask *p = &temp;//後ろ用
		CTask *n = &temp;//前用

		p->next = mRoot;
		n->next = mRoot;


		while (p->next != mTail){ //後ろのタスク
			p = p->next;
			n = p->next;
			if (p->mPriorityU < n->mPriorityU){
				CTask sp, sn;
				printf("nは%dです\n", n->mBirthday_No);
				printf("入れ替え\n");
				SwapTask(&p, &n);

				/*保存*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*左回りに順番を変える*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*前後の順番を変える*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//入れ替えが終わりに行われた時
					mTail = n;
				}
				/*入れ替えが中間の時*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
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
