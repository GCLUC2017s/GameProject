/*
マクロ
担当者　冨田健斗 
*/
#ifndef DEFINE_HPP
#define DEFINE_HPP
#include "windows.h"
/*
[使い方]
	マクロで複数の場所で参照されるものをここに書いていく
*/

//マクロ
#define WINDOW_PIXEL_X	640					//ウィンドウ解像度：幅
#define WINDOW_PIXEL_Y	480					//ウィンドウ解像度：高さ

#define DISP_X	WINDOW_PIXEL_X * 0.012		//ウィンドウ解像度：幅
#define DISP_Y	WINDOW_PIXEL_Y * 0.012		//ウィンドウ解像度：高さ


const float character_limit_left = -DISP_X;			//進める上限(左)
const float character_limit_top = 0;	    //進める上限(上)
const float character_limit_right = DISP_X * 9;		 //進める上限(右)
const float character_limit_bottom = -DISP_Y;		//進める上限(下)


#define UP_KEY VK_UP
#define DOWN_KEY VK_DOWN
#define RIGHT_KEY VK_RIGHT
#define LEFT_KEY VK_LEFT

#endif