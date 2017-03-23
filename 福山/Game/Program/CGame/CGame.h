/*
���\�b�h�ꗗ
�y�c���l
*/
#ifndef GAME_HPP
#define GAME_HPP
#include "../Define/define.h"
#include "../Vector/CVector2.h"
#include "../Graphic/CRectangle.h"
#include "../Player/CPlayer.h"
#include "../Enemy/CEnemy00.h"


class CGame {
private:
public:

	/* getPosition
	return:���W��̈ʒu
	*/
	static CVector2 mGetPlayerPos();
	static CVector2 getPosition(const CVector2 &v);
	static CEnemy00 getEnemy(CEnemy00 &ene00);
	static CVector2 CameraPos();
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
	 /*�e�N�X�`�����f���[�g����Ƃ��Ɏg��*/
	static void Delete(CTexture **t);
	 /*�t�F�[�h�֐� speed = �t�F�[�h�̑��� a = ALPHA*/
	static void Fade(float speed, CRectangle *rect,float a);
	static void FadeOut(float speed, CRectangle *rect);
	/*�g��k���֐�
	true �g��, false �k��
	x,y ���
	speed ����
	rect �l�p
	*/
	static void RectScaling(bool flag, float x, float y,float speed,CRectangle *rect);
	/*���Ԍo�߂�TRUE�ɂ��� time�ɂ����鎞�Ԃ����� save�͕ۑ��p �g���Ƃ���H�e���Ǘ����� <-�@�g���ɂ����̂Œ��������������킩�炸*/
	static bool FlagTime(float time,float fps,float *save);
	/*�X�e�[�W�G�l�~�[���f*/
 


};

#endif