/**
* @file		CTask.h
* @brief	�^�X�N�V�X�e�����N���X
* @author	ryoji anzai,yuki yamaji
*/

#ifndef TASK_GUARD
#define TASK_GUARD
//�X�V����
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Map,
	eUDP_Null,
};
//�`�揇��
enum E_DrawPrio
{
	eDWP_Map,
	eDWP_Player,
	eDWP_Enemy,
	eDWP_Tutorial,
	eDWP_Null,
};

class CTask
{
protected:
	bool m_destroyFlg;				//�폜�t���O
	bool m_pauseFlg;				//�X�V��~�t���O
	//���������̐����^	
	unsigned int m_updatePrio;	    //�X�V�D�揇�ʊi�[
	unsigned int m_drawPrio;		//�`��D�揇�ʊi�[
	int m_id;
	CTask *mp_prev;					//�O�̃A�h���X���i�[����|�C���^
	CTask *mp_next;					//���̃A�h���X���i�[����|�C���^
public:
	CTask();						//CTask�N���X�̃R���X�g���N�^
	CTask(int id, unsigned int updateprio, unsigned int drawPrio);
	virtual ~CTask();				//CTask�N���X�̃f�X�g���N�^
	virtual void Update();			//�h����N���X�ł̍X�V���s���֐�
	virtual void Draw();			//�h����N���X�ł̕`�ʂ��s���֐�
	//�X�V���ʐݒ�֐�
	void SetUpdatePrio(unsigned int updatePrio)
	{
		m_updatePrio = updatePrio;
	}
	//�`�揇�ʐݒ�֐�
	void SetDrawPrio(unsigned int drawPrio)
	{
		m_drawPrio = drawPrio;
	}
	//�X�V���ʎ擾�֐�
	int GetUpdatePrio()
	{
		return m_updatePrio;
	}
	//�`�揇�ʎ擾�֐�
	int GetDrawPrio()
	{
		return m_drawPrio;
	}
	//�X�V���ʕύX
	void ChangeUpdatePrio(unsigned int updatePrio)
	{
		unsigned int prio = m_updatePrio;
		m_updatePrio = updatePrio;
		updatePrio = prio;
	}
	//�`�揇�ʕύX
	void ChangeDrawPriority(unsigned int drawPrio)
	{
		unsigned int prio = m_drawPrio;
		m_drawPrio = drawPrio;
		drawPrio = prio;
	}
	void SetKill() 
	{
		m_destroyFlg = true;
	}
	friend class CTaskManager;
};

#endif