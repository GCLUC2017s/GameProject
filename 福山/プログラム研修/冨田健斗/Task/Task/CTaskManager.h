#ifndef INCLUDE_HEADER_HPP_CTaskManager
#define INCLUDE_HEADER_HPP_CTaskManager
#include "CTask.h"



class  CTaskManager : public CTask
{
public:
	CTask *root;
	CTask *tail;

	CTaskManager(){}


	~CTaskManager(){
		CTask *t;
		t = root;
		while (t != 0)
		{
			root = t->next;
			delete t;
			t = root;
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
		if (root == 0){
			root = t;
			tail = t;
		}
		else{

			t->prev = tail;
			tail->next = t;
			tail = t;
		}
	}

	/*
	デリート処理
	プログラムの順番

	Taskのアドレスが始まりの時
				↓
	Taskのアドレスが終わりの時
				↓
	Taskのアドレスが中間の時

	*/
	void Kill(CTask *t){
		//CTask *T; //順番を見る

		if (t == root){  //始まり
			root = root->next;
			root->prev = 0;
			delete t;
		}
		/*	}
			else if (t == tail){

			}
			else{

			}*/
		
	}

	void Update(){}
	 
};

#endif
