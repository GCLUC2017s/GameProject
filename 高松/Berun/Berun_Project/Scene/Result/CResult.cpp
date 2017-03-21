#include "CResult.h"
#include "../Scene/CSceneManager.h"

static CFont *font = nullptr;

//各画像サイズ、座標の設定
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
	{ 500.0f,200.0f,{ 750.0f,350.0f } },
	{ 300.0f,150.0f,{ 950.0f,180.0f } },
	{ 600.0f,100.0f,{ 700.0f,600.0f } },
	{ 75.0f,75.0f,{ 85.0f,220.0f } },
	{ 75.0f,75.0f,{ 185.0f,220.0f } },
	{ 75.0f,75.0f,{ 285.0f,220.0f } },
	{ 75.0f,75.0f,{ 385.0f,220.0f } },
	{ 75.0f,75.0f,{ 85.0f,325.0f } },
	{ 75.0f,75.0f,{ 185.0f,325.0f } },
	{ 75.0f,75.0f,{ 285.0f,325.0f } },
	{ 75.0f,75.0f,{ 385.0f,325.0f } },
	{ 75.0f,75.0f,{ 85.0f,435.0f } },
	{ 75.0f,75.0f,{ 185.0f,435.0f } },
	{ 75.0f,75.0f,{ 285.0f,435.0f } },
	{ 75.0f,75.0f,{ 385.0f,435.0f } },
	{ 75.0f,75.0f,{ 85.0f,540.0f } },
	{ 75.0f,75.0f,{ 185.0f,540.0f } },
	{ 75.0f,75.0f,{ 285.0f,540.0f } },
	{ 75.0f,75.0f,{ 385.0f,540.0f } },

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
	mp_img[10] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("ItemSelect"));
	mp_img[11] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Craft"));
	mp_img[12] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("ResultTitle"));
	mp_img[13] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item1"));
	mp_img[14] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item2"));
	mp_img[15] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item3"));
	mp_img[16] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item4"));
	mp_img[17] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item5"));
	mp_img[18] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item6"));
	mp_img[19] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item7"));
	mp_img[20] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item8"));
	mp_img[21] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item9"));
	mp_img[22] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item10"));
	mp_img[23] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item11"));
	mp_img[24] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item12"));
	mp_img[25] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item13"));
	mp_img[26] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item14"));
	mp_img[27] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item15"));
	mp_img[28] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("Item16"));
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
	if (!font) font = new CFont(L"HG丸ゴシックM-PRO", 35);
	mp_img[0]->SetColor(0.5, 0.5, 0.5, 1);
	//CItem::GetInstance()->AddItem(eCarrotItem,0);
	//各項目の選択処理
	switch (m_corsol)
	{
	case 0:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 1:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[12]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_ENTER)
		{
			CSceneManager::GetInstance()->Quit(60, eTitle);
		}
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 2:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[11]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 3:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[13]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 4:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[14]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 5:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[15]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 6:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[16]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 7:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[17]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 8:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[18]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 9:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[19]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 10:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[20]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 11:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[21]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 12:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[22]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 13:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[23]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 14:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[24]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 15:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[25]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 16:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[26]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 17:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[27]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol++;
		}
		break;
	case 18:
		for (int i = 10; i < eMax; i++)
		{
			mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
		}
		mp_img[28]->SetColor(1, 1, 1, 1);
		if (PUSH_KEY_SPASE)
		{
			m_corsol = 1;
		}
		break;
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

	sprintf(m_str, "ENTER：決定");
	font->Draw(550, 600, 1, 1, 1, m_str);
	sprintf(m_str, "SPACE：次へ");
	font->Draw(550, 650, 1, 1, 1, m_str);
}
