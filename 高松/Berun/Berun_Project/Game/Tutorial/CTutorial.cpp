#include "CTutorial.h"

static CFont *font = nullptr;

CTutorial::CTutorial() : CTutorial(g_tutorialDataPath[g_tutorialNo])
{
}

CTutorial::CTutorial(char * file) : CTask(0,0), mp_file(nullptr),
									m_face(0),
									m_end(0), 
									m_state(0)
{
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerM"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerW"));
	mp_img[2] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("TutorialM"));
	mp_img[3] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("TutorialW"));
	
	//テキストファイルオープン
	fopen_s(&mp_file, file, "r");
	//ファイルが無ければ何もしない
	if (mp_file == nullptr) return;
	GetText();
}

CTutorial::~CTutorial()
{
	fclose(mp_file);
}

void CTutorial::Update()
{
	if (!font) font = new CFont(L"HG丸ゴシックM-PRO", 40);
	//エンターキーでチュートリアル進行
	if (CInput::GetState(0, CInput::ePush, CInput::eButton10)) GetText();
	//スペースキーでチュートリアルスキップ
	if (CInput::GetState(0, CInput::ePush, CInput::eButton5)) m_end = TEXT_END;

	assert(0 <= g_tutorialNo && g_tutorialNo < ARRAY_SIZE(mp_img),"ARRAY_SIZE_ERROR");
	mp_img[g_tutorialNo]->SetSize(400, 800);
	mp_img[g_tutorialNo]->SetPos(-50, 100);
	mp_img[2]->SetSize(1000, 300);
	mp_img[2]->SetPos(250, 400);
	mp_img[3]->SetSize(1000, 300);
	mp_img[3]->SetPos(250, 400);

	//テキストが終われば削除フラグを真にする
	if (GetEnd()) SetDestroyFlag(true);
}

void CTutorial::Draw()
{
	//チュートリアル操作表示
	sprintf(m_str, "ENTER：進行");
	font->Draw(900, 50, 0, 0, 0, m_str);
	sprintf(m_str, "SPACE：スキップ");
	font->Draw(900, 100, 0, 0, 0, m_str);
	mp_img[g_tutorialNo]->Draw();
	if (g_tutorialNo == 0) mp_img[2]->Draw();
	if (g_tutorialNo == 1) mp_img[3]->Draw();
}

void CTutorial::GetText()
{
	fgets(m_str, WORD_MAX, mp_file);
	sscanf_s(m_str, "%d", &m_end);
	if (m_end == TEXT_END) return;
	sscanf_s(m_str, "%d", &m_face);
	fgets(m_text[0], WORD_MAX, mp_file);
	fgets(m_text[1], WORD_MAX, mp_file);
}

bool CTutorial::GetEnd()
{
	return (m_end == TEXT_END);
}
