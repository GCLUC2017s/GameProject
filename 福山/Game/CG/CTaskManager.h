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

	void AbsR(){
		/*�o�u���\�[�g*/
		CTask temp;
		CTask *p = &temp;//���p
		CTask *n = &temp;//�O�p

		p->next = mRoot;
		n->next = mRoot;
	

		while (p->next != mTail){ //���̃^�X�N
			p = p->next;
			n = p->next;
			if (p->mPriorityR > n->mPriorityR){
				CTask sp, sn;
				printf("n��%d�ł�\n", n->mBirthday_No);
				printf("����ւ�\n");
				SwapTask(&p, &n);

				/*�ۑ�*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*�����ɏ��Ԃ�ς���*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*�O��̏��Ԃ�ς���*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//����ւ����I���ɍs��ꂽ��
					mTail = n;
				}
				/*����ւ������Ԃ̎�*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
			}
		}
	}


	void DescR(){
		/*�o�u���\�[�g*/
		CTask temp;
		CTask *p = &temp;//���p
		CTask *n = &temp;//�O�p

		p->next = mRoot;
		n->next = mRoot;


		while (p->next != mTail){ //���̃^�X�N
			p = p->next;
			n = p->next;
			if (p->mPriorityR < n->mPriorityR){
				CTask sp, sn;
				printf("n��%d�ł�\n", n->mBirthday_No);
				printf("����ւ�\n");
				SwapTask(&p, &n);

				/*�ۑ�*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*�����ɏ��Ԃ�ς���*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*�O��̏��Ԃ�ς���*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//����ւ����I���ɍs��ꂽ��
					mTail = n;
				}
				/*����ւ������Ԃ̎�*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
			}
		}
	}

	void AbsU(){
		/*�o�u���\�[�g*/
		CTask temp;
		CTask *p = &temp;//���p
		CTask *n = &temp;//�O�p

		p->next = mRoot;
		n->next = mRoot;


		while (p->next != mTail){ //���̃^�X�N
			p = p->next;
			n = p->next;

			if (p->mPriorityU > n->mPriorityU){

				CTask sp, sn;
				SwapTask(&p, &n);

				/*�ۑ�*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*�����ɏ��Ԃ�ς���*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*�O��̏��Ԃ�ς���*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//����ւ����I���ɍs��ꂽ��
					mTail = n;
				}
				/*����ւ������Ԃ̎�*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
			}
		}
	}


	void DescU(){
		/*�o�u���\�[�g*/
		CTask temp;
		CTask *p = &temp;//���p
		CTask *n = &temp;//�O�p

		p->next = mRoot;
		n->next = mRoot;


		while (p->next != mTail){ //���̃^�X�N
			p = p->next;
			n = p->next;
			if (p->mPriorityU < n->mPriorityU){
				CTask sp, sn;
				printf("n��%d�ł�\n", n->mBirthday_No);
				printf("����ւ�\n");
				SwapTask(&p, &n);

				/*�ۑ�*/
				sp.prev = p->prev;
				sp.next = p->next;
				sn.prev = n->prev;
				sn.next = n->next;
				/*�����ɏ��Ԃ�ς���*/
				p->prev = sn.prev;
				p->next = sp.prev;
				n->next = sp.next;
				n->prev = sn.next;
				/*�O��̏��Ԃ�ς���*/
				if (p->prev == 0){
					mRoot = p;
				}
				if (n->next == 0){	//����ւ����I���ɍs��ꂽ��
					mTail = n;
				}
				/*����ւ������Ԃ̎�*/
				if (p->prev != 0){
					p->prev->next = p;
				}
				if (p->next != 0){
					p->next->prev = p;
				}
				if (n->prev != 0){
					n->prev->next = n;
				}
				if (n->next != 0){
					n->next->prev = n;
				}
				p = mRoot;
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
