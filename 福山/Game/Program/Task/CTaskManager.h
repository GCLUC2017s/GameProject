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
private:
	CTask *mRoot;
	CTask *mTail;
	void SwapTask(CTask **p, CTask **n);

public:
	CTaskManager();

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
	Abs�͏����@
	R��Rebder�p
	U��Update�p
	*/



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

	void SortR(CTask *t);

	void AbsR();
	void AbsU();
	void Kill(CTask **t);
	void AllKill();
	void AllUpdate();
	void AllRender();
	void AllInit();
	 
};

#endif
