#include "CTutorial.h"

static CFont *font = nullptr;

CTutorial::CTutorial() : CTutorial(g_tutorialDataPath[g_tutorialNo])
{
}

CTutorial::CTutorial(char * file)
{
	mp_img[0] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerM"));
	mp_img[1] = dynamic_cast<CImage*>(CResourceManager::GetInstance()->Get("PlayerW"));
	fopen_s(&mp_file, file, "r");
	if (mp_file == nullptr) return;
	fgets(m_str, WORD_MAX, mp_file);
	sscanf_s(m_str, "%d");
	GetText();
}

CTutorial::~CTutorial()
{
	fclose(mp_file);
}

void CTutorial::Update()
{
	if (!font) font = new CFont(L"HG丸ゴシックM-PRO", 40);
	if (CInput::GetState(0, CInput::ePush, CInput::eButton10)) GetText();
	if (CInput::GetState(0, CInput::ePush, CInput::eButton5)) m_end = -2;
	if(g_tutorialNo == 1) mp_img[0]->SetPos(200, 250);
	if(g_tutorialNo == 2) mp_img[1]->SetPos(200, 250);
}

void CTutorial::Draw()
{
	sprintf(m_str, "ENTER：進行");
	font->Draw(800, 35, 1, 1, 1, m_str);
	sprintf(m_str, "SPACE：スキップ");
	font->Draw(800, 75, 1, 1, 1, m_str);
	if (g_tutorialNo == 1) mp_img[0]->Draw();
	if (g_tutorialNo == 2) mp_img[1]->Draw();
}

void CTutorial::GetText()
{
	fgets(m_str, WORD_MAX, mp_file);
	sscanf_s(m_str, "%d", &m_end);
	if (m_end == -2) return;
	sscanf_s(m_str, "%d", &m_face);
	fgets(m_name, WORD_MAX, mp_file);
	fgets(m_text[0], WORD_MAX, mp_file);
	fgets(m_text[1], WORD_MAX, mp_file);
}

bool CTutorial::GetEnd()
{
	return (m_end == -2);
}
