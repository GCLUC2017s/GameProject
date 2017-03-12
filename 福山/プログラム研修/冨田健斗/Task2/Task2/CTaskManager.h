/*
*�^�X�N�̃}�l�[�W���[�̃v���O����
*�S���ҁ@�y�c���l
*/
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include "CTask.h"
#include <assert.h> 
class  CTaskManager
{
public:
	CTask *mRoot;
	CTask *mTail;

	CTaskManager(){};


	~CTaskManager();

	/*
	�ǉ�����
	���ɒǉ����Ă����`
	�����菇
	root == 0 ���@�����Ȃ��Ƃ�
	root != 0 ��  ����Ƃ�
	*/
	void Add(CTask  *t);
	/*
	�g����
	���ёւ������� CTask *t�� &t �̌`�ŁC�����Ƃ��ē����
	Abs�͏����@Desc�͍~��
	R��Rebder�p
	U��Update�p
	*/

	void SwapTask(CTask **p, CTask **n){ //����ւ�����
		CTask *s = *n;
		*n = *p;
		*p = s;

	}

	void AbsR();


	void DescR();

	void AbsU();


	void DescU();

	

	/*
	�f���[�g����

	�����Ӂ@Kill�̂ق��� " **t  �Ȃ̂Ŏg�����ɒ��ӂ��K�v  "

	�v���O�����̏���

	Task�̃A�h���X���n�܂�̎�
				��
	Task�̃A�h���X���I���̎�
				��
	Task�̃A�h���X�����Ԃ̎�

	
	*/

	void Kill(CTask **t);

	void Update(){}
	 
};

#endif
