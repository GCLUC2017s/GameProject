#include "CDownGimmick.h"
#include "CGame.h"

int CDownGimmick::rowsuu;

void CDownGimmick::init() {
	mpTexture = new CTexture();	//�e�N�X�`���N���X�̃C���X�^���X�쐬
	mpTexture->load("����}�b�v�`�b�v.tga");	//�e�N�X�`���t�@�C���ǂݍ���
	mRect_left.setuv(mpTexture, 0, 0, 100, 100);	//�e�N�X�`���̎g�p�ݒ�
	mRect_right.setuv(mpTexture, 0, 0, 100, 100);	//�e�N�X�`���̎g�p�ݒ�

	//�l�p�`�̒��_�ݒ�
	mRect_left.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	mRect_right.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);

	enabled = false;
	go_enabld = false;
	plusx = 0.0f;
	speed = 0.0f;
	rowsuu = 0;
	  
}

CDownGimmick::~CDownGimmick() {
	if (mpTexture) {
		//�e�N�X�`�����g���Ă���΃C���X�^���X�폜
		delete mpTexture;
		mpTexture = 0;
	}
}

CDownGimmick::CDownGimmick() : mpTexture(0), speed(0.0f), plusx(0.0f), enabled(false){
	rowsuu = 0;

	//�l�p�`�̒��_�ݒ�
	mRect_left.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	mRect_right.setVertex(-0.5f, 0.5f, 0.5f, -0.5f);
	//�l�p�`�̐F��ݒ�
	mRect_left.setColor(1.0f, 0.0f, 0.0f, 1.0f);
	mRect_right.setColor(0.0f, 1.0f, 0.0f, 1.0f);

}


void CDownGimmick::update(){


	if (enabled){ //���܂�����Ƃ�
		if (CGame::getIndex(hozleftpos) != CGame::getIndex(leftpos)){
			speed -= 0.002f;
			plusx -= speed;
			leftpos.x -= speed;
			rightpos.x += speed;
		}
		else
		{
			leftpos = hozleftpos;
			rightpos = hozrightpos;
			enabled = false;
			go_enabld = false;
		}
	}
	else{ //�܂��Ă��Ȃ��Ƃ�

		if (CGame::getIndex(middlepos) > CGame::getIndex(leftpos)){ //�^�񒆂ɍs���܂�
			speed += 0.002f;
			plusx += speed;
			leftpos.x += speed;
			rightpos.x -= speed;
		}
		else 
		{
			enabled = true;//�܂��Ă���
			if (rowsuu < CGame::mMapRows - 4){ //downgimmick���܂ōs���J�E���g
				rowsuu += 1; //�������J�E���g����downgimmick�𑝂₵�Ă��� 
				if (rowsuu >= CGame::mMapRows - 4){ //rowsuu���z�񐔂𒴂����ꍇ
					rowsuu = CGame::mMapRows - 4;
				}
			}
		}
	}

		mRect_left.position = leftpos;
		mRect_right.position = rightpos;

		mRect_left.setVertex(-0.5f - plusx, 0.5f, 0.5f, -0.5f);
		mRect_right.setVertex(-0.5f, 0.5f, 0.5f + plusx, -0.5f);

};

void CDownGimmick::render() {
	//�l�p�`�̕`��
	mRect_left.render();
	mRect_right.render();
}

void CDownGimmick::setPos(int row, int col) {

	leftpos = CGame::getPosition(row, col);
	rightpos = CGame::getPosition(row, col + CGame::mMapCols-1);
	middlepos = CGame::getPosition(row, col + CGame::mMapCols / 2);
	hozleftpos = leftpos;
	hozrightpos = rightpos;

	mRect_left.position = leftpos;
	mRect_right.position = rightpos;
}