/*
*�^�X�N�̃}�l�[�W���[�̃v���O����
*�S���ҁ@�y�c���l
*/
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP
#include "CTask.h"

class  CTaskManager
{
public:
	CTask *mRoot;
	CTask *mTail;
	int k;

	CTaskManager(){ k = 0; }


	~CTaskManager(){
		CTask *t;
		t = mRoot;
		while (t != 0)
		{
			mRoot = t->next;
			delete t;
			t = mRoot;
		}
	}

	/*
	�ǉ�����
	���ɒǉ����Ă����`
	�����菇
	root == 0 ���@�����Ȃ��Ƃ�
	root != 0 ��  ����Ƃ�
	*/
	void Add(CTask  *t){
		if (mRoot == 0){
			mRoot = t;
			mRoot->prev = 0;
			mRoot->next = t;
			mTail = t;
		}
		else{

			t->prev = mTail;
			mTail->next = t;
			mTail = t;

		}
	}
	/*
	Abs ���� Decs �~�� 
	Abs
	*/

	void AbsR(){
		CTask temp;
		CTask *MoveTask = &temp; //�ړ��p
		CTask *StopTask = &temp; //�Œ�p
		StopTask->next = mRoot;
		MoveTask->next = mRoot->next;

		while (StopTask != mTail){
			StopTask = StopTask->next;
			MoveTask = StopTask->next;
			while (MoveTask != mTail){
				MoveTask = MoveTask->next;
				if (StopTask->mPriorityR > MoveTask->mPriorityR){
						CTask *Save; //�ۑ��p Move��ۑ�

						Save = MoveTask;

						Save->prev = StopTask->prev; 
						Save->next = StopTask->next; 

						StopTask->prev = MoveTask->prev;
						StopTask->next = MoveTask->next;

						MoveTask = StopTask;
						StopTask = Save;
					
				}
			}
		}

	}

	void DecsR(CTask *t){
		CTask *save_t; //���߂̂ق�
		CTask *task; //

		while (true)
		{
			while (true)
			{

			}

		}

	}

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

	void Kill(CTask **t){


		CTask temp; //���ɍ�����
		CTask *T = &temp; //���Ԃ�����
		T->next = mRoot;

		while (T != mTail)
		{
			T = T->next;
			if (*t == T){ //T�Ƃ����Ă���Ƃ�
				if (T->prev == 0){  //�n�܂�
					mRoot = mRoot->next;
					mRoot->prev = 0;
					delete *t;
					*t = mRoot;
					break;
				}
				else if (T->next == 0){ //�I���
					mTail = mTail->prev;
					mTail->next = 0;
					delete *t;
					*t = mTail;
					break;
				}
				else{ //����
					CTask *save_T; //���̕ۑ��ꏊ

					T->prev->next = T->next;
					T->next->prev = T->prev;

					save_T = T->prev;
					delete *t;
					*t = save_T;
					break;
				}
			}

		}
		
	}

	void Update(){}
	 
};

#endif
