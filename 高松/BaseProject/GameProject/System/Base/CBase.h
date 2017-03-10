/**
*@file
*@brief  Šî’êƒNƒ‰ƒX
*@author ŽR˜H
*/

#ifndef CBASE_GUARD
#define CBASE_GUARD

struct T_WordPos
{
	float xPos;
	float yPos;
};

class CBase
{
private:
	T_WordPos *mp_posData;
	float m_xPos;
	float m_yPos;
};

#endif