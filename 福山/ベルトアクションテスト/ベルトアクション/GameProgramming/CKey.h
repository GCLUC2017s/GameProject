#pragma once
#include <windows.h>

#define KEY(c)  GetKeyState(c) & 0x8000	//キーボードが押されているか判定するマクロ関数


class CKey {
	static bool flg[256];
public:
	static bool push(char k);
	static bool once(char k);

};
