/*
�@�����蔻��̊Ǘ��v���O����
  �S���ҁ@ �y�c���l
*/
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"
#include "../Task/CTaskManager.h"

class CCollisionManager : public CTask
{
public:
	CCollisionManager();
	~CCollisionManager();
	/*�����̕����ɍU���������Ώۂ�����*/
	void EnemyAttack(CBase *b);
	void PlayerAttack(CBase *b);

	void Update(CBase *b);
	
private:

};

#endif