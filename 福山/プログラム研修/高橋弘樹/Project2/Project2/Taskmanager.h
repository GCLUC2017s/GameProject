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
	void Add(Task  *p){
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


	void Destroy(){
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