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
	CTask* Destroy(CTask *p);
	//���X�g���w��폜�֐�
	void DestroyAppoint();
	//���X�g���S�폜�֐�
	void DestroyAll();
	//���X�g�X�V�֐�
	void UpdateAll();
	//���X�g�`��֐�
	void DrawAll();
	CTask GetTask();
	//CTaskManager�𐶐����ĕϐ��Ɋi�[
	static CTaskManager* GetInstance();
	//�i�[����Ă�����̂��폜
	static void ClearInstance();

	void Number(int i);
};

#endif