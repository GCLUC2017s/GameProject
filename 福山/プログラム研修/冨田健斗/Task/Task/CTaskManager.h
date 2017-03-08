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

	/*’Ç‰Áˆ—*/
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

	/*ƒfƒŠ[ƒgˆ—*/
	void Kill(CTask *t){
		root = root->next;
		root->prev = 0;
		delete t;
	}

	void Update(){}
	 
};

#endif
