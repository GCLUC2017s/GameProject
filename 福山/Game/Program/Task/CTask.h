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
	float mPriorityR; //Rander()�̃i���o�[
	float mPriorityU;//Update()�̃i���o�[
	bool mKillFlag;  //�t���O�������Ă�����̂�����
	int mMyNumber;	//��ޔ��f�̂��߂̃i���o�[

	CTask() :next(0), prev(0),mPriorityR(0.0f),mPriorityU(0.0f),mKillFlag(false){};
	virtual ~CTask(){};

	virtual void Init(){};
	virtual void Update(){};
	virtual void Render(){};

};


#endif
