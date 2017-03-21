/**
* @file		CTutorial.h
* @brief	チュートリアルクラス
* @author	yuki yamaji
*/

#ifndef TUTORIAL_GUARD
#define TUTORIAL_GUARD

#include "TaskSystem/CTask.h"
#include "CImage.h"
#include "../Global.h"

#define IMAGE_MAX  5
#define LINE_MAX   2
#define WORD_MAX 128
#define TEXT_END  -2

class CTutorial : public CTask
{
private:
	CImage *mp_img[IMAGE_MAX];				//画像格納配列
	FILE   *mp_file;						//ファイルポインタ	
	int     m_face;							//立ち絵ナンバー
	int     m_end;							//テキスト終了伝達
	int		m_state;
	char    m_text[LINE_MAX][WORD_MAX];		//文章(行)(文字数）
	char    m_str[WORD_MAX];				//表示文字列
public:
	CTutorial(char *file);
	~CTutorial();
	void Update();
	void Draw();
	//テキストファイル取得
	void GetText();
	//終了フラグ取得
	bool GetEnd();
};
#endif