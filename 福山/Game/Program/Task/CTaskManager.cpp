#include "CTaskManager.h"

CTaskManager::CTaskManager(){}


CTaskManager::~CTaskManager(){

}
/*
追加処理
後ろに追加していく形
処理手順
root == 0 が　何もないとき
root != 0 が  あるとき
*/
void CTaskManager::Add(CTask  *t){
	if (mRoot == 0){
		mRoot = t;
		mRoot->prev = 0;
		mRoot->next = t;
		mTail = t;
	}
	else{
		CTask temp;
		CTask *p = &temp;
		p->next = mRoot;

		while (p != mTail)
		{
			p = p->next;

			if (p == mRoot && p->mPriorityR > t->mPriorityR){ //初め
				mRoot = t;
				mRoot->prev = 0;
				p->prev = t;
				if (p->next == 0){
					mTail = p;
				}

				break;
			}
			else if (p == mTail){ //最後
				t->prev = mTail;
				mTail->next = t;
				mTail = t;
				mTail->next = 0;
				break;
			} 
			else if (p->mPriorityR <= t->mPriorityR <= p->next->mPriorityR){ //中間
				t->next = p->next;
				t->prev = p;
				p->next->prev = t;

				p->next = t;
				break;
			}

		}


	}
}
/*
使い方
並び替えしたい CTask *tを &t の形で，引数として入れる
Absは昇順　Descは降順
RはRebder用
UはUpdate用
*/

void CTaskManager::SwapTask(CTask **p, CTask **n){ //入れ替え処理
	CTask *s = *n;
	*n = *p;
	*p = s;

}
void CTaskManager::Sort(CTask **t){
	CTask *n = new CTask();
	n = *t;
	Add(n);
	Kill(t);

}

void CTaskManager::AbsR(){
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



void CTaskManager::AbsU(){
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

void CTaskManager::Kill(CTask **t){


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

void CTaskManager::AllKill(){
	CTask *task;
	task = mRoot;
	while (task != 0)
	{
		Kill(&task);
		task = task->next;
	}
}


void CTaskManager::AllInit(){
	CTask *task;
	task = mRoot;
	while (task != 0)
	{
		task->Init();
		task = task->next;
	}
}

void CTaskManager::AllUpdate(){
	CTask *task;
	task = mRoot;

	/*すべてのRender表示*/
	while (task != 0)
	{
		task->Update();
		task = task->next;

	}
}

void CTaskManager::AllRender(){
	CTask *task;
	task = mRoot;

	/*すべてのRender表示*/
	while (task != 0)
	{
		AbsR();
		//Sort(&task);
		task->Render();
		task = task->next;

	}



}
