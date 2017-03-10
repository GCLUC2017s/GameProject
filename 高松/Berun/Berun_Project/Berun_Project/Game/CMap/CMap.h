#pragma once
#include "stdafx.h"
#define MAP_WIDTH 80
#define MAP_HEIGHT 24

/*!
*	@brief		�}�b�v�N���X
*/
class CMap {
private:
	int m_mapData[MAP_HEIGHT][MAP_WIDTH];	//!<�}�b�v�`�b�v�f�[�^
	int m_width;							//!<��
	int m_height;							//!<����
	CImage* m_img;							//!<�摜
	CImage* m_imghaikei;
	int back_haikei1;
	int back_haikei2;
	 
	 float m_backkumo;
	 float m_backkumo2;
	 float m_backkumo3;
	 int m_kumopatarnA;
	 int m_kumopatarnB;
	 int m_kumopatarnC;
	 int kumo;
	 int kumo2;
	 int kumo3;
	
	 float y2;
public:
	static CMap* mainMap;					//!<�O���A�N�Z�X�p
	int f;
	int M;
	int B;
	int F;
	/*!
	@brief	�R���X�g���N�^
	**/
	CMap();
	/*!
	@brief	�`�揈��
	@retval ����
	**/
	void Draw();
	/*!
	@brief	�`�b�v�̎�ނ��擾
	@param	pos	[in]�ʒu�i�X�N���[�����W�j
	@retval ����
	**/
	int GetTipData(CVector2D pos);
	/*!
	@brief	�g�p���̃}�b�v�I�u�W�F�N�g���擾
	@retval �}�b�v�I�u�W�F�N�g�̃A�h���X
	**/
	static CMap* Get() {
		return mainMap;
	}

};