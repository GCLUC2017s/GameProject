/*
*�^�X�N�̃v���O����
*�S���� �y�c���l
*/
#ifndef TASK_HPP
#define TASK_HPP

#include <stdio.h>


class  CTask
{
public:
	float mHitPoint;
	CTask *next;
	CTask *prev;
	int mPriorityR; //Rander()�̃i���o�[
	int mPriorityU;//Update()�̃i���o�[

	CTask() :next(0), prev(0),mHitPoint(0){};
	~CTask(){};

	virtual void Update(){};

};

#endif
