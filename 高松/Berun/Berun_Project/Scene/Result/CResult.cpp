#include "CResult.h"

static T_ResultData g_resultdata[eMax] =
{
	{ 500.0f,90.0f,{ 0.0f,0.0f } },
	{ 300.0f,288.0f,{ 0.0f,0.0f } },
	{ 252.0f,300.0f,{ 0.0f,0.0f } },
	{ 300.0f,335.0f,{ 0.0f,0.0f } },
	{ 300.0f,375.0f,{ 0.0f,0.0f } },
	{ 1096.0f,417.0f,{ 0.0f,0.0f } },
	{ 1000.0f,152.0f,{ 0.0f,0.0f } },
	{ 400.0f,390.0f,{ 0.0f,0.0f } },
	{ 100.0f,67.0f,{ 0.0f,0.0f } },
	{ 546.0f,200.0f,{ 0.0f,0.0f } },
	{ 200.0f,137.0f,{ 0.0f,0.0f } },
};

CResult::CResult(int type) : m_xSize(0.0f), m_ySize(0.0f), m_step(0)
{
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Clear"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankA"));
	mp_img[2] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankB"));
	mp_img[3] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankC"));
	mp_img[4] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankS"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	mp_img[6] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Select"));
	mp_img[7] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item"));
	mp_img[8] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Arrow"));
	mp_img[9] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Craft"));
	mp_img[10] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("ItemSelect"));
	CSound::GetInstance()->GetSound("RESULT_BGM")->Play();
	mp_data = &g_resultdata[type];
	m_xSize = mp_data->xSize;
	m_ySize = mp_data->ySize;
	m_pos = mp_data->pos;
}

CResult::~CResult()
{
	CSound::GetInstance()->GetSound("RESULT_BGM")->Stop();
}

void CResult::Update()
{
	//CItem::GetInstance()->AddItem(eCarrotItem,0);
	/*
	if (m_step == 0)
	{
		if (PUSH_KEY_ENTER)
		{

		}
		else if (PUSH_KEY_UP)
		{

		}
		else if (PUSH_KEY_DOWN)
		{

		}
		else if (PUSH_KEY_RIGHT)
		{

		}
		else if (PUSH_KEY_LEFT)
		{

		}
	}
	*/
}

void CResult::Draw()
{
	//mp_img[0]->Draw();	
}
