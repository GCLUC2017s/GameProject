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
				//c�폜

				if (c->mPrev == 0){		//�����ɓ��Ă͂܂����擪�v�f�̍폜
					mRoot = c->mNext;
					mRoot->mPrev = 0;
					delete c;
					c = &temp;
					c->mNext = mRoot;

				}
				else if (c->mNext == 0){	//�����ɓ��Ă͂܂������ԗv�f�̍폜
					mTail = mTail->mPrev;
					mTail->mNext = 0;
					delete c;
					c = mTail;

				}
				else{

					Task*g;
					c->mPrev->mNext = c->mNext;		//�����ɓ��Ă͂܂����Ō�v�f�̍폜
					c->mNext->mPrev = c->mPrev;
					g = c->mPrev;
					delete c;
					c = g;

				}
			}

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