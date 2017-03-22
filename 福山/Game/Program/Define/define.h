/*
�}�N��
�S���ҁ@�y�c���l 
*/
#ifndef DEFINE_HPP
#define DEFINE_HPP
#include "windows.h"
/*
[�g����]
	�}�N���ŕ����̏ꏊ�ŎQ�Ƃ������̂������ɏ����Ă���
*/

//�}�N��
#define WINDOW_PIXEL_X	640.0f					//�E�B���h�E�𑜓x�F��
#define WINDOW_PIXEL_Y	480.0f					//�E�B���h�E�𑜓x�F����

#define DISP_X	WINDOW_PIXEL_X * 0.012f		//�E�B���h�E�𑜓x�F��
#define DISP_Y	WINDOW_PIXEL_Y * 0.012f		//�E�B���h�E�𑜓x�F����

#define FRAME_LIMIT 6							//�A�j���̃t���[����(�����^)	
#define NORMALATTACK_PATTERN 3 //�ʏ�U���̃p�^�[��

const float character_limit_left = -DISP_X;			//�i�߂���(��)
const float character_limit_top = 0;	    //�i�߂���(��)
const float character_limit_right = DISP_X * 9;		 //�i�߂���(�E)
const float character_limit_bottom = -DISP_Y;		//�i�߂���(��)


#define UP_KEY VK_UP
#define DOWN_KEY VK_DOWN
#define RIGHT_KEY VK_RIGHT
#define LEFT_KEY VK_LEFT

#endif