#ifndef COLLISIONMANAGER_INCLUDE_GUARD
#define COLLISIONMANAGER_INCLUDE_GUARD
#include "../CollisionA/CCollisionA.h"

class CCollisionManager
{
private:
	static CCollisionManager* mp_instance;	//�V���O���g�����̂��߂̃|�C���^
protected:
	CCollisionA *mp_head;		//�擪�v�f���w���|�C���^
	CCollisionA *mp_tail;		//�����v�f���w���|�C���^
public:
	CCollisionManager();
	~CCollisionManager();
	void Regist(CCollisionA *p);
	CCollisionA *UnRegist(CCollisionA *p);
	void UnRegistAll();
	void CheckHitAll();
	//CCollisionManager�𐶐����ĕϐ��Ɋi�[
	static CCollisionManager* GetInstance();
	//�i�[����Ă�����̂��폜
	static void ClearInstance();
};

#endif