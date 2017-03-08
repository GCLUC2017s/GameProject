#ifndef INCLUDE_HEADER_HPP_CTaskManager
#define INCLUDE_HEADER_HPP_CTaskManager
#include "CTask.h"



class  CTaskManager : public CTask
{
public:
	CTask *root;
	CTask *tail;

	void Abb(CTask  *t){
		root = t;
		tail = t;
	}
	void Kill(CTask *t){
	
	}
	void Update(){}
	 
};

#endif
