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

	CTask() :next(0), prev(0),mHitPoint(0){};
	~CTask(){};

	virtual void Update(){};

};

#endif
