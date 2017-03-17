#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	���ʃf�[�^
*
* @author	shinya nagakawa
*/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SCREEN_SIZE CVector2D(SCREEN_WIDTH,SCREEN_HEIGHT)


#define GRAVITY	-0.98f
#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))
#define TUTORIAL_MAX 2
#define FILE_NAME 32



//�`���[�g���A���f�[�^�p�X
extern char g_tutorialDataPath[TUTORIAL_MAX][FILE_NAME];
//���݂̃`���[�g���A���i���o�[
extern int  g_tutorialNo;

//�T�E���h�@�}�N���̒�`
#define TITLE_BGM	"TITLE_BGM"
#define CHARASELECT_BGM	"CHARASELECT_BGM"
#define AREA_M_BGM	"AREA_M_BGM"
#define AREA_N_BGM	"AREA_N_BGM"
#define AREA_E_BGM	"AREA_E_BGM"
#define AREA_NI_BGM	"AREA_NI_BGM"
#define RESULT_BGM	"RESULT_BGM"
#define GAMEOVER_BGM	"GAMEOVER_BGM"

//�L�[���͂̒�`
#define PUSH_KEY_ENTER		CInput::GetState(0, CInput::ePush, CInput::eButton10)		//����E�U���L�[
#define HOLD_KEY_ENTER		CInput::GetState(0, CInput::eHold, CInput::eButton10)		//����E�U���L�[
#define PUSH_KEY_SPASE		CInput::GetState(0, CInput::ePush, CInput::eButton5)		//�X�L�b�v�E�W�����v�L�[
#define HOLD_KEY_SHIFT		CInput::GetState(0, CInput::eHold, CInput::eButton6)		//�_�b�V���L�[
#define PUSH_KEY_UP			CInput::GetState(0, CInput::ePush, CInput::eUp)				//��L�[�v�b�V��
#define HOLD_KEY_UP			CInput::GetState(0, CInput::eHold, CInput::eUp)				//��L�[�z�[���h
#define PUSH_KEY_DOWN		CInput::GetState(0, CInput::ePush, CInput::eDown)			//���L�[�v�b�V��
#define HOLD_KEY_DOWN		CInput::GetState(0, CInput::eHold, CInput::eDown)			//���L�[�z�[���h
#define PUSH_KEY_RIGHT		CInput::GetState(0, CInput::ePush, CInput::eRight)			//�E�L�[�v�b�V��
#define HOLD_KEY_RIGHT		CInput::GetState(0, CInput::eHold, CInput::eRight)			//�E�L�[�z�[���h
#define PUSH_KEY_LEFT		CInput::GetState(0, CInput::ePush, CInput::eLeft)			//���L�[�v�b�V��
#define HOLD_KEY_LEFT		CInput::GetState(0, CInput::eHold, CInput::eLeft)			//���L�[�z�[���h


