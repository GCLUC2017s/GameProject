/**
* @file		CTask.h
* @brief	�^�X�N�V�X�e�����N���X
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD

enum E_UdPriority
{
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};

enum E_DwPriority
{
	eDWP_Map,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_destroyFlg;				//�폜�t���O
	bool m_pauseFlg;				//�X�V��~�t���O
	//���������̐����^	
	unsigned int m_udPriority;	    //�X�V�D�揇�ʊi�[
	unsigned int m_dwPriority;		//�`��D�揇�ʊi�[
	CTask *mp_prev;					//�O�̃A�h���X���i�[����|�C���^
	CTask *mp_next;					//���̃A�h���X���i�[����|�C���^
public:
	CTask();						//CTask�N���X�̃R���X�g���N�^
	CTask(unsigned int udpriority, unsigned int rdPriority);
	virtual ~CTask();				//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Draw();			//�h����N���X�ł̕`�ʂ��s���֐�
	//�X�V���ʐݒ�֐�
	void SetUDPriority(int udPriority)
	{
		m_udPriority = udPriority;
	}
	//�`�揇�ʐݒ�֐�
	void SetDWPriority(int dwPriority)
	{
		m_dwPriority = dwPriority;
	}
	//�X�V���ʎ擾�֐�
	int GetUDPriority()
	{
		return m_udPriority;
	}
	//�`�揇�ʎ擾�֐�
	int GetDWPriority()
	{
		return m_udPriority;
	}
	//�X�V���ʕύX
	void ChangeUpdatePriority(int udPriority)
	{
		m_udPriority = udPriority;
	}
	//�`�揇�ʕύX
	void ChangeDrawPriority(int dwPriority)
	{
		m_dwPriority = dwPriority;
	}
	friend class CTaskManager;
};

#endif