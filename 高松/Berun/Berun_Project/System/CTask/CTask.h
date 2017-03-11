/**
* @file		CTask.h
* @brief	�^�X�N�V�X�e�����N���X
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include<stdio.h>

class CTask
{
protected:
	bool m_destroyFlg;			//�폜�t���O
	bool m_pauseFlg;			//�X�V��~�t���O
	//���������̐����^
	unsigned int m_udPriority;  //�X�V�D�揇�ʊi�[
	unsigned int m_rdPriority;  //�`��D�揇�ʊi�[
	CTask *mp_prev;					//�O�̃A�h���X���i�[����|�C���^
	CTask *mp_next;					//���̃A�h���X���i�[����|�C���^
public:
	CTask();						//CTask�N���X�̃R���X�g���N�^
	virtual ~CTask();				//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Render();			//�h����N���X�ł̕`�ʂ��s���֐�
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