#include "CResult.h"

CResult::CResult() : m_step(0)
{
	/*
	CSound::GetInstance()->GetSound("RESULT_BGM")->Play();
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Clear"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankA"));
	mp_img[2] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankB"));
	mp_img[3] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankC"));
	mp_img[4] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("RankS"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get(""));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	mp_img[5] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Rank"));
	*/
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
	mp_img[0]->Draw();
}
