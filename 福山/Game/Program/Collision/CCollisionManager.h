/*
�@�����蔻��̊Ǘ��v���O����
  �S���ҁ@ �y�c���l
*/
#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "../Collision/CCollision.h"

class CCollisionManager
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