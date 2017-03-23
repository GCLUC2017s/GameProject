/**
* @file		CTaskManager.h
* @brief	�^�X�N�V�X�e���Ǘ��N���X
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

#include "CTask.h"

class CTaskManager
{
private:
	static CTaskManager* mp_instance;	//�V���O���g�����̂��߂̃|�C���^
protected:
	CTask *mp_head;		//�擪�v�f���w���|�C���^
	CTask *mp_tail;		//�����v�f���w���|�C���^
public:
	CTaskManager();
	~CTaskManager();
	//���X�g�ǉ��֐�
	void Add(CTask *p);
	//���X�g���폜�֐�
	CTask* Kill(CTask *p);
	//���X�g���w��폜�֐�
	void KillAppoint();
	//���X�g���S�폜�֐�
	void KillAll();
	//���X�g�X�V�֐�
	void UpdateAll();
	//���X�g�`��֐�
	void DrawAll();
	//
	//�^�X�N����ւ��֐�
	void SwapTask(CTask **p, CTask **n);
	//�����\�[�g�֐��i�X�V�p�j
	void SortAscUpdate();
	//�����\�[�g�֐��i�`��p�j
	void SortAscDraw();
	//�^�X�N�擾�֐�
	CTask* GetTask(int id);
	//�^�X�N�J�E���g�֐�
	int GetCount(int id);
	//CTaskManager�𐶐����ĕϐ��Ɋi�[
	static CTaskManager* GetInstance();
	//�i�[����Ă�����̂��폜
	static void ClearInstance();

	//void Number(int i);
};

#endif