/*
*�^�X�N�̃v���O����
*�S���� �y�c���l
*/
#ifndef TASK_HPP
#define TASK_HPP
#include <stdio.h>
#include <assert.h>
#include "../MyNumber/CMyNumber.h"

class  CTask
{
public:

	CTask *next;
	CTask *prev;
	float mPriorityR; //Rander()�̃i���o�[
	float mPriorityU;//Update()�̃i���o�[
	bool mKillFlag;  //�t���O�������Ă�����̂�����
	bool mCharaFlag; //�L�����N�^�[�̃t���O�������Ă�����̂ɂ�Col����
	int mMyNumber;	//��ޔ��f�̂��߂̃i���o-
	bool mUiFlag; //UI�����邩���f

	CTask() :next(0), prev(0), mKillFlag(false),mUiFlag(false) ,mCharaFlag(false), mMyNumber(E_ERROR),mPriorityR(E_ERROR),mPriorityU(E_ERROR){};
	virtual ~CTask(){};

	virtual void Init(){};
	virtual void Update(){ 
		assert(mMyNumber  != E_ERROR);
		assert(mPriorityU != E_ERROR);
	};
	virtual void Render(){
		assert(mMyNumber != E_ERROR);
		assert(mPriorityR != E_ERROR);
	};

};


#endif
