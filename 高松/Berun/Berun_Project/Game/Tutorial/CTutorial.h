/**
* @file		CTutorial.h
* @brief	チュートリアルクラス
* @author	yuki yamaji
*/

#ifndef TUTORIAL_GUARD
#define TUTORIAL_GUARD

#include "../System/TaskSystem/CTask.h"
#include "CImage.h"
#include "../Global.h"

#define IMAGE_MAX  3
#define NAME_MAX  64
#define LINE_MAX   2
#define WORD_MAX 128

class CTutorial : public CTask
{
private:
	CImage *mp_img[IMAGE_MAX];
	FILE   *mp_file;
	int     m_face;
	int     m_textEnd;
	int     m_end;
	char    m_name[NAME_MAX];
	char    m_text[LINE_MAX][WORD_MAX];
	char    m_str[WORD_MAX];
public:
	CTutorial();
	CTutorial(char *file);
	~CTutorial();
	void Update();
	void Draw();
	void GetText();
	bool GetEnd();
	static bool m_isActive;
};
#endif