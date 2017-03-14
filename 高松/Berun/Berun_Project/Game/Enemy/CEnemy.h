#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../System/Base/CBase.h"
#include"../Global.h"

/**
*@file	 CEnemy.h
*@brief  �G�N���X
*@author �{�c
*/



class CEnemy:public CBase {
private:
	
	CImage *m_vegetavelenemy;
	enum vegetavelenemy //�X�e�[�W�P��؁E�ʕ��G
	{
		carrot,//�j���W��
		papurika,//�s�[�}��
		berry,//�C�`�S��
		strawberry//�C�`�S�n��
	};
	CVector3D m_enemypos;
public:
	


	static CEnemy* mainEnemy;		
	CEnemy(T_EnemyData *data);
	
	~CEnemy();
	
	void Update();
	
	void Draw();
	

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
