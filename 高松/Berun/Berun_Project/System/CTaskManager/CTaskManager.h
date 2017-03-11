/**
* @file		CTask.h
* @brief	TaskManagerSystem
*
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

#include <stdio.h>
#include "../CTask/CTask.h"

class CTaskManager
{
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
	//���X�g���S�폜�֐�
	void KillCheck();
	//���X�g�X�V�֐�
	void AllUpdate();
	//���X�g�`��֐�
	void AllRender();
	//�X�V��~�֐�
	void Pause();
};

#endif