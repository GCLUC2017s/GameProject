/**
*@file
*@brief  �^�X�N�V�X�e�����N���X
*@author �R�H
*/

#ifndef  TASK_HPP
#define  TASK_HPP
#include <stdio.h>

class CTask 
{
private:
	CTask *mp_prev;				//��O�̗v�f���w���|�C���^
	CTask *mp_next;				//���̗v�f���w���|�C���^
	//���������̐����^
	unsigned int m_udPriority;  //�X�V�D�揇�ʊi�[
	unsigned int m_rdPriority;  //�`��D�揇�ʊi�[
public:
	CTask();
	~CTask();
	//���z�֐� �p����̍X�V������D��
	virtual void Update();
	//�X�V���ʐݒ�֐�
	void SetUDPriority(int udPriority)
	{
		m_udPriority = udPriority;
	}
	//�`�揇�ʐݒ�֐�
	void SetRDPriority(int rdPriority)
	{
		m_rdPriority = rdPriority;
	}
	//�X�V���ʎ擾�֐�
	int GetUDPriority()
	{
		return m_udPriority;
	}	
	//�`�揇�ʎ擾�֐�
	int GetRDPriority()
	{
		return m_udPriority;
	}
	friend class CTaskManager;
};

class CTaskManager
{
private:
	CTask *mp_head;			//�擪�v�f���w���|�C���^
	CTask *mp_tail;			//�����v�f���w���|�C���^
public:
	CTaskManager();
	//���X�g�X�V�֐�
	void ListUpdate();
	//���X�g�`��֐�
	void ListRender();
	//���X�g�ǉ��֐�
	void Add(CTask *p);
	//���X�g�폜�֐�
	void Destroy();
};

#endif