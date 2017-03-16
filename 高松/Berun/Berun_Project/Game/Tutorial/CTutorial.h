/**
* @file		CTutorial.h
* @brief	�`���[�g���A���N���X
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
#define TEXT_END  -2

class CTutorial : public CTask
{
private:
	CImage *mp_img[IMAGE_MAX];				//�摜�i�[�z��
	FILE   *mp_file;						//�t�@�C���|�C���^	
	int     m_face;							//�����G�i���o�[
	int     m_end;							//�e�L�X�g�I���`�B
	char    m_name[NAME_MAX];				//�L������
	char    m_text[LINE_MAX][WORD_MAX];		//����(�s)(�������j
	char    m_str[WORD_MAX];				//�\��������
	int		m_state;
public:
	CTutorial();
	CTutorial(char *file);
	~CTutorial();
	void Update();
	void Draw();
	//�e�L�X�g�t�@�C���擾
	void GetText();
	//�I���t���O�擾
	bool GetEnd();
};
#endif