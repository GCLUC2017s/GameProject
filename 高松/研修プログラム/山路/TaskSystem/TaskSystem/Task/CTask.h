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
	bool m_pauseflg;			//�X�V��~�t���O
public:
	CTask();
	virtual ~CTask();
	//���z�֐� �p����̍X�V������D��
	virtual void Update();
	virtual void Render();
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

#endif