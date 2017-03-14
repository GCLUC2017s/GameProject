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
#define MAP_LIMIT_Y	10						//マップのY
#define MAP_LIMIT_X	100						//マップのX

#endif