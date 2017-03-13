/**
* @file		CTaskManager.h
* @brief	�^�X�N�V�X�e���Ǘ��N���X
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

#include <stdio.h>
#include "../CTask/CTask.h"

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
	CTask* Destroy(CTask *p);
	//���X�g���S�폜�֐�
	void AllDestroy();
	//���X�g�X�V�֐�
	void AllUpdate();
	//���X�g�`��֐�
	void AllRender();
	//�X�V��~�֐�
	void Pause();
	//CTaskManager�𐶐����ĕϐ��Ɋi�[
	static CTaskManager* GetInstance();
	//�i�[����Ă�����̂��폜
	static void ClearInstance();
};

#endif