//TASK@base@
//‚‹´O÷
#ifndef TASK_HPP
#define TASK_HPP
#include<stdio.h>

class Task{
public:
	Task *mPrev;
	Task *mNext;

	Task() :mPrev(0), mNext(0){};
	~Task();

	virtual void Update();


};
#endif