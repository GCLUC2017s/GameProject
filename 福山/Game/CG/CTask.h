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

	CTask *next;
	CTask *prev;
	int mPriorityR; //Rander()�̃i���o�[
	int mPriorityU;//Update()�̃i���o�[
	int mMyNumber;	//��ޔ��f�̂��߂̃i���o�[

	CTask() :next(0), prev(0){};
	virtual ~CTask(){};

	virtual void Init(){};
	virtual void Update(){};
	virtual void Render(){};

};


#endif
