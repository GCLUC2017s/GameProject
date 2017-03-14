#ifndef CENEMY_GURAD
#define CENEMY_GUARD
#include"../System/Base/CBase.h"
#include"../Global.h"
#include "../Global.h"
#include"../System/TaskSystem/CTaskManager.h"

/**
*@file	 CEnemy.h
*@brief  �G�N���X
*@author �{�c
*/



class CEnemy:public CTask {
private:
	//��؁E�ʕ�
	CImage *m_carrot;
	CImage *m_papurika;
	CImage *m_berry;
	CImage *m_strawberry;
	CImage *m_vegetavelBoss;
	//��
	CImage *m_pig;
	CImage *m_bird;
	CImage *m_meatboss;
	//��
	CImage *m_squid;
	CImage *m_fish;
	CImage *m_fishBoss;
	//����
	CImage *m_rice;
	CImage *m_bread;
	CImage *m_grainBoss;
	
	enum E_Enemy 
	{
		eCarrot,//�j���W��
		ePapurika,//�s�[�}��
		eBerry,//�C�`�S�T���O���X��
		eStrawberry,//�C�`�S�n��
		eVegetavelboss,//��؃{�X�i�E�T�M�j
		ePig,//��
		eBird,//��
		eMeatboss,//���{�X�i�{�j
		eSquid,//�C�J
		eFish,//��
		eFishboss,//����{�X�i�L�j
		eRice,//��
		eBread,//�p��
		eGrainboss//�����{�X�i���q���m�j
	};
	int m_enemytime;
	E_Enemy m_enemytype;
public:
		
	CEnemy();
	
	~CEnemy();
	
	void Update();
	
	void Draw();
	

	/*void HitCallback(CBase *b);
	static CEnemy* GetmainEnemy() { return mainEnemy; };
	*/
};




#endif // CENEMY_GURAD
