#include "CResult.h"
#include "../Scene/CSceneManager.h"

static T_ResultData g_resultdata[eMax] =
{
	{ 1280.0f,768.0f,{ 0.0f,0.0f } },
	{ 350.0f,90.0f,{ 90.0f,50.0f } },
	{ 100.0f,150.0f,{ 1075.0f,25.0f } },
	{ 100.0f,150.0f,{ 1075.0f,25.0f } },
	{ 100.0f,150.0f,{ 1075.0f,25.0f } },
	{ 100.0f,150.0f,{ 1075.0f,25.0f } },
	{ 300.0f,150.0f,{ 750.0f,50.0f } },
	{ 500.0f,100.0f,{ 500.0f,220.0f } },
	{ 500.0f,550.0f,{ 25.0f,150.0f } },
	{ 150.0f,100.0f,{ 550.0f,400.0f } },
	{ 300.0f,150.0f,{ 950.0f,180.0f } },
	{ 500.0f,200.0f,{ 750.0f,350.0f } },
	{ 600.0f,100.0f,{ 700.0f,600.0f } },
};

CResult::CResult() : m_xSize(0.0f), m_ySize(0.0f), m_step(0), m_corsol(0)
{
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("ResultBackGround"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Clear"));
	mp_img[2] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankA"));
	mp_img[3] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankB"));
	mp_img[4] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankC"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankS"));
	mp_img[6] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	mp_img[7] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Select"));
	mp_img[8] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item"));
	mp_img[9] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Arrow"));
	mp_img[10] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Craft"));
	mp_img[11] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("ItemSelect"));
	mp_img[12] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("ResultTitle"));
	CSound::GetInstance()->GetSound("RESULT_BGM")->Play();
	for (int j = 0; j < eMax; j++)
	{
		mp_data = &g_resultdata[j];
		m_xSize = mp_data->xSize;
		m_ySize = mp_data->ySize;
		m_pos = mp_data->pos;
		mp_img[j]->SetPos(m_pos);
		mp_img[j]->SetSize(m_xSize, m_ySize);
	}
}

CResult::~CResult()
{
	CSound::GetInstance()->GetSound("RESULT_BGM")->Stop();
}

void CResult::Update()
{
	mp_img[0]->SetColor(0.5, 0.5, 0.5, 1);
	//CItem::GetInstance()->AddItem(eCarrotItem,0);
	switch (m_corsol)
	{
	case 0:
		mp_img[12]->SetColor(0, 0, 0.8, 1);
		if (PUSH_KEY_ENTER)
		{
			CSceneManager::GetInstance()->Quit(60, eTitle);
		}
	default:
		break;
	}
}

void CResult::Draw()
{
	for (int i = 0; i < eMax; i++)
	{
		mp_img[i]->Draw();
	}
}
