#ifndef INCLUDE_HEADER_HPP_CTaskManager
#define INCLUDE_HEADER_HPP_CTaskManager
#include "CTask.h"



class  CTaskManager : public CTask
{
public:
	CTask *root;
	CTask *tail;

	CTaskManager(){}


	~CTaskManager(){
		CTask *t;
		t = root;
		while (t != 0)
		{
			root = t->next;
			delete t;
			t = root;
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
		if (root == 0){
			root = t;
			tail = t;
		}
		else{

			t->prev = tail;
			tail->next = t;
			tail = t;
		}
	}

	/*
	�f���[�g����
	�v���O�����̏���

	Task�̃A�h���X���n�܂�̎�
				��
	Task�̃A�h���X���I���̎�
				��
	Task�̃A�h���X�����Ԃ̎�

	*/
	void Kill(CTask *t){
		//CTask *T; //���Ԃ�����

		if (t == root){  //�n�܂�
			root = root->next;
			root->prev = 0;
			delete t;
		}
		/*	}
			else if (t == tail){

			}
			else{

			}*/
		
	}

	void Update(){}
	 
};

#endif
