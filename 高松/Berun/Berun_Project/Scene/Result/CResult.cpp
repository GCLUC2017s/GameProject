#include "CResult.h"
#include "../Scene/CSceneManager.h"
#include "../Global.h"

static CFont *font = nullptr;

//各画像サイズ、座標の設定
static const T_ResultData g_resultData[] =
{
	{ 1280.0f,768.0f,{    0.0f,  0.0f } },
	{  350.0f, 90.0f,{   90.0f, 50.0f } },
	{  100.0f,150.0f,{ 1075.0f, 25.0f } },
	{  100.0f,150.0f,{ 1075.0f, 25.0f } },
	{  100.0f,150.0f,{ 1075.0f, 25.0f } },
	{  100.0f,150.0f,{ 1075.0f, 25.0f } },
	{  300.0f,150.0f,{  750.0f, 50.0f } },
	{  500.0f,100.0f,{  500.0f,220.0f } },
	{  500.0f,550.0f,{   25.0f,150.0f } },
	{  150.0f,100.0f,{  550.0f,400.0f } },
	{  500.0f,200.0f,{  750.0f,350.0f } },
	{  300.0f,150.0f,{  950.0f,180.0f } },
	{  600.0f,100.0f,{  700.0f,600.0f } },
	{   75.0f, 75.0f,{   85.0f,220.0f } },
	{   75.0f, 75.0f,{  185.0f,220.0f } },
	{   75.0f, 75.0f,{  285.0f,220.0f } },
	{   75.0f, 75.0f,{  385.0f,220.0f } },
	{   75.0f, 75.0f,{   85.0f,325.0f } },
	{   75.0f, 75.0f,{  185.0f,325.0f } },
	{   75.0f, 75.0f,{  285.0f,325.0f } },
	{   75.0f, 75.0f,{  385.0f,325.0f } },
	{   75.0f, 75.0f,{   85.0f,435.0f } },
	{   75.0f, 75.0f,{  185.0f,435.0f } },
	{   75.0f, 75.0f,{  285.0f,435.0f } },
	{   75.0f, 75.0f,{  385.0f,435.0f } },
	{   75.0f, 75.0f,{   85.0f,540.0f } },
	{   75.0f, 75.0f,{  185.0f,540.0f } },
	{   75.0f, 75.0f,{  285.0f,540.0f } },
	{   75.0f, 75.0f,{  385.0f,540.0f } },

};

static_assert (ARRAY_SIZE(g_resultData) == eMax,"ArraySizeError");

CResult::CResult() : m_xSize(0.0f), m_ySize(0.0f), m_corsol(0)
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
		//こちらにもconstをつける
		T_ResultData  const *data = &g_resultData[j];
		m_xSize = data->xSize;
		m_ySize = data->ySize;
		m_pos = data->pos;
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

	bool quitFlg = false;
	//各項目の選択処理

	if (!quitFlg)
	{
		switch (m_corsol)
		{
		case 0:
			DarkenColor();
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 1:
			DarkenColor();
			mp_img[eResultTitle]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_DECIDE)
			{
				CSceneManager::GetInstance()->Quit(60, eTitle);
				quitFlg = true;
			}
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 2:
			DarkenColor();
			mp_img[eCraft]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 3:
			DarkenColor();
			mp_img[eItem1]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 4:
			DarkenColor();
			mp_img[eItem2]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 5:
			DarkenColor();
			mp_img[eItem3]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 6:
			DarkenColor();
			mp_img[eItem4]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 7:
			DarkenColor();
			mp_img[eItem5]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 8:
			DarkenColor();
			mp_img[eItem6]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 9:
			DarkenColor();
			mp_img[eItem7]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 10:
			DarkenColor();
			mp_img[eItem8]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 11:
			DarkenColor();
			mp_img[eItem9]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 12:
			DarkenColor();
			mp_img[eItem10]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 13:
			DarkenColor();
			mp_img[eItem11]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 14:
			DarkenColor();
			mp_img[eItem12]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 15:
			DarkenColor();
			mp_img[eItem13]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 16:
			DarkenColor();
			mp_img[eItem14]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 17:
			DarkenColor();
			mp_img[eItem15]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol++;
			break;
		case 18:
			DarkenColor();
			mp_img[eItem16]->SetColor(1, 1, 1, 1);
			if (PUSH_KEY_NEXT) m_corsol = 1;
			break;
		default:
			break;
		}
	}
}

void CResult::Draw()
{
	for (int i = 0; i < eMax; i++) mp_img[i]->Draw();

	font->Draw(550, 600, 1, 1, 1, "ENTER：決定");
	font->Draw(550, 650, 1, 1, 1, "SPACE：次へ");
}

void CResult::DarkenColor()
{
	for (int i = (int)eSelectStart; i < (int)eSelectEnd; i++) mp_img[i]->SetColor(0.5, 0.5, 0.5, 1);
}
