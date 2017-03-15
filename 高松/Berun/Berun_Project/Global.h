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
#define KEY_DECIDE_ATTACK (CInput::eButton10)	//����U���L�[
#define KEY_SKIP_JUMP     (CInput::eButton5)	//�X�L�b�v�W�����v�L�[
#define KEY_UP			  (CInput::eUp)			//��ړ��L�[
#define KEY_DOWN		�@(CInput::eDown)		//���ړ��L�[
#define KEY_RIGHT		  (CInput::eRight)		//�E�ړ��L�[
#define KEY_LEFT		  (CInput::eLeft)		//���ړ��L�[


