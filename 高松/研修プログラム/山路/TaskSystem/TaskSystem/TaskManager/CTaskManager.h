/**
*@file
*@brief  �^�X�N�Ǘ��N���X
*@author �R�H
*/

#ifndef  TASKMANAGER_HPP
#define  TASKMANAGER_HPP
#include "../Task/CTask.h"

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
	//���X�g�S�폜�֐�
	void ListDestroy();
	//�X�V�ꎞ��~�֐�
	void Pause();
};

#endif