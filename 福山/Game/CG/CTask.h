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
	int mBirthday_No;//���܂ꂽ��
	static float count; //�S���̃^�X�N��


	CTask() :next(0), prev(0), mHitPoint(0){};
	virtual ~CTask(){};

	virtual void Update(){};
	virtual void Render(){};

};


#endif
