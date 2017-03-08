#pragma once
/**
*@file
*@brief  �^�X�N�V�X�e�����N���X
*@author �R�H
*/

#ifndef INCLUDE_GURAD_TASK
#endif  INCLUDE_GURAD_TASK

#include <string.h>
#include <stdio.h>

class CTask 
{
private:
	CTask *mp_head;			//�擪�v�f���w���|�C���^
	CTask *mp_tail;			//�����v�f���w���|�C���^
	CTask *mp_prev;			//��O�̗v�f���w���|�C���^
	CTask *mp_next;			//���̗v�f���w���|�C���^
	char   m_name[32];		//���O�i�[�z��
public:
	CTask(char *name);
	~CTask();
	//���z�֐� �p����̍X�V������D��
	virtual void Update();
	virtual void Print();
	friend class CTaskManager;
};

class CTaskManager : public CTask
{
public:
	//�I�u�W�F�N�g�ǉ��֐�
	void Add(CTask *p);
	//�I�u�W�F�N�g�폜�֐�
	void Destroy(CTask *p);
	void DrawList();
};
