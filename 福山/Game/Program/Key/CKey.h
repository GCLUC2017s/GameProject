/*
�L�[���͔��f�N���X
�S���ҁ@ �y�c���l
*/
#ifndef KEY_HPP
#define KEY_HPP
#include <windows.h>

#define KEY(c)  GetKeyState(c) & 0x8000	//�L�[�{�[�h��������Ă��邩���肷��}�N���֐�


class CKey {
	static bool flg[256];
public:
	static bool push(char k);
	static bool once(char k);

};

#endif
