//�^�X�N�}�l�[�W���[
//�����O��
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include "Task.h"
#include <Windows.h>

class Taskmanager{
public:
	Task *mRoot;
	Task *mTail;
	void Update(){}
	Taskmanager(){
	};
	~Taskmanager(){
		Task temp;
		Task *c;
		c = &temp;
		c->mNext = mRoot;
		while (c != mTail){
			c = c->mNext;
		}
	}
	void Add(Task  *p){	//mRoot��0�̎��Ɏ��s���鏈��
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
	void Genocide(){		//�폜
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