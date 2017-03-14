#include "CTaskManager.h"

CTaskManager::CTaskManager(){}


CTaskManager::~CTaskManager(){

}
/*
�ǉ�����
���ɒǉ����Ă����`
�����菇
root == 0 ���@�����Ȃ��Ƃ�
root != 0 ��  ����Ƃ�
*/
void CTaskManager::Add(CTask  *t){
	if (mRoot == 0){
		mRoot = t;
		mRoot->prev = 0;
		mRoot->next = t;
		mTail = t;
	}
	else{
		CTask temp;
		CTask *p = &temp;
		p->next = mRoot;

		while (p != mTail)
		{
			p = p->next;

			if (p == mRoot && p->mPriorityR > t->mPriorityR){ //����
				mRoot = t;
				mRoot->prev = 0;
				p->prev = t;
				if (p->next == 0){
					mTail = p;
				}

				break;
			}
			else if (p == mTail){ //�Ō�
				t->prev = mTail;
				mTail->next = t;
				mTail = t;
				mTail->next = 0;
				break;
			} 
			else if (p->mPriorityR <= t->mPriorityR <= p->next->mPriorityR){ //����
				t->next = p->next;
				t->prev = p;
				p->next->prev = t;

				p->next = t;
				break;
			}

		}


	}
}
/*
�g����
���ёւ������� CTask *t�� &t �̌`�ŁC�����Ƃ��ē����
Abs�͏����@Desc�͍~��
R��Rebder�p
U��Update�p
*/

void CTaskManager::SwapTask(CTask **p, CTask **n){ //����ւ�����
	CTask *s = *n;
	*n = *p;
	*p = s;

}
void CTaskManager::Sort(CTask **t){
	CTask *n = new CTask();
	n = *t;
	Add(n);
	Kill(t);

}

void CTaskManager::AbsR(){
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



void CTaskManager::AbsU(){
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

void CTaskManager::Kill(CTask **t){


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

void CTaskManager::AllKill(){
	CTask *task;
	task = mRoot;
	while (task != 0)
	{
		Kill(&task);
		task = task->next;
	}
}


void CTaskManager::AllInit(){
	CTask *task;
	task = mRoot;
	while (task != 0)
	{
		task->Init();
		task = task->next;
	}
}

void CTaskManager::AllUpdate(){
	CTask *task;
	task = mRoot;

	/*���ׂĂ�Render�\��*/
	while (task != 0)
	{
		task->Update();
		task = task->next;

	}
}

void CTaskManager::AllRender(){
	CTask *task;
	task = mRoot;

	/*���ׂĂ�Render�\��*/
	while (task != 0)
	{
		AbsR();
		//Sort(&task);
		task->Render();
		task = task->next;

	}



}
