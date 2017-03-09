//タスクマネージャー
//高橋弘樹
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include "Task.h"
#include <Windows.h>

class Taskmanager{
public:
	Task *mRoot;
	Task *mTail;
	void Update(){};
	int i;
	Taskmanager(){ i = 0; };

	~Taskmanager(){
		Task temp;
		Task *c;

		c = &temp;
		c->mNext = mRoot;

		while (c != mTail){
			c = c->mNext;

			if (==c){
				//c削除

				if (c->mPrev == 0){		//条件に当てはまった先頭要素の削除
					mRoot = c->mNext;
					mRoot->mPrev = 0;
					delete c;
					c = &temp;
					c->mNext = mRoot;

				}
				else if (c->mNext == 0){	//条件に当てはまった中間要素の削除
					mTail = mTail->mPrev;
					mTail->mNext = 0;
					delete c;
					c = mTail;

				}
				else{

					Task*g;
					c->mPrev->mNext = c->mNext;		//条件に当てはまった最後要素の削除
					c->mNext->mPrev = c->mPrev;
					g = c->mPrev;
					delete c;
					c = g;

				}
			}

		}
	}




	void Add(Task  *p){	//mRootが0の時に実行する処理
		if (mRoot == 0){
			mRoot = p;
			mTail = p;
		}
		else{
			p->mPrev = mTail;
			mTail->mNext = p;
			mTail = p;
		}
	}

	void Genocide(){		//削除
		Task *n;
		n = mRoot;
		while (n != 0){
			mRoot = n->mNext;
			delete n;
			n = mRoot;
		}
	}



};
#endif