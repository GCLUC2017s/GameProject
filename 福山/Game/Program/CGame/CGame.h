#ifndef GAME_HPP
#define GAME_HPP
#include "../Define/define.h"
#include "../Vector/CVector2.h"
#include "../Graphic/CRectangle.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"


class CGame {
public:
	/* getPosition
	return:���W��̈ʒu
	*/
	static CVector2 mGetPlayerPos();
	static CVector2 getPosition(const CVector2 &v);
	static CEnemy00 getEnemy(CEnemy00 &ene00);
	static float	GetPlayerAxis();
	static CPlayer getPlayer(CTask &t);
	/*�^�X�N�������ق����Ƃ��Ɏg��
	�@number�@�ق������̂̃i���o�[
	 �L���X�g�����Ďg�� 
	 (��)
	 CPlyer *pl;

	 pl = (CPlayer*)getStatus(E_PLAYER);

	 */
	static CTask *getStatus(int number);
	static void Delete(CTexture **t);
};

#endif