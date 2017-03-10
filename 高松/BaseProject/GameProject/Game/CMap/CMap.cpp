#include "CMap.h"
#include "../CImageManager.h"
#include "Global.h"
#include"CEnemy.h"

//�}�b�v�f�[�^�i���j
static int State1Data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};
//�N���X�ϐ��̒�`
CMap* CMap::mainMap;
CMap::CMap() {
	

	  m_backkumo = 1000;
	  m_backkumo2 = 1300;
	  m_backkumo3 = 1600;
	  m_kumopatarnA = 0;
	  m_kumopatarnB = 0;
	  m_kumopatarnC = 0;
	  kumo = 0;
	  kumo2 = 0;
	  kumo3= 0;
	//���̃\�[�X�t�@�C���Ŏg���}�b�v�I�u�W�F�N�g�����g�ɐݒ�
	mainMap = this;
	FILE* fp;
	//�t�@�C����ǂݍ��݃��[�h�ŊJ��
	fopen_s(&fp, stageDataPath[stageNo], "r");
	if (fp) {
		char tag[32];
		while (!feof(fp)) {
			//�t�@�C������̓ǂݍ���
			fscanf_s(fp, "%s", tag,32);
			//�ǂݍ��񂾕�����MapData�Ȃ�
			if (strcmp(tag, "MapData") == 0) {
				//���ƍ�����ǂݍ���
				fscanf_s(fp, "%d %d", &m_width,&m_height);
				for (int i = 0; i < m_height; i++) {
					for (int j = 0; j < m_width; j++) {
						//���ƍ������}�b�v�f�[�^��ǂݍ���
						fscanf_s(fp, "%d", &m_mapData[i][j]);
					}
				}
			}
		}
	}
	fclose(fp);
	m_img = CImageManager::Get("MapTip");

	/*
	//���f�[�^
	for (int i = 0; i < MAP_HEIGHT;i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_mapData[i][j] = State1Data[i][j];
		}
	}
	*/

	

}
void CMap::Draw() {
	if (stageNo == 1) {
		 
	
		
		m_imghaikei = CImageManager::Get("Haikei2");
		m_imghaikei->setRect(0, 0, 1280, 768);
		m_imghaikei->setSize(1280, 768);
		m_imghaikei->Draw();

		m_imghaikei = CImageManager::Get("Kumo");
		m_imghaikei->setRect(30, 45, 135, 130);
		m_imghaikei->setSize(128, 128);
		if (m_kumopatarnA==0) {
			srand(time(nullptr));
			kumo = rand() % 4;
			m_kumopatarnA++;
		}
		if (m_kumopatarnB == 0) {
			srand(time(nullptr));
			kumo2 = rand() % 6;
			m_kumopatarnB++;
		}
		if (m_kumopatarnC == 0) {
			srand(time(nullptr));
			kumo3 = rand() % 2;
			m_kumopatarnC++;
		}
		m_imghaikei->setPos(m_backkumo, 50*kumo);
		m_imghaikei->Draw();
		m_imghaikei->setPos(m_backkumo2, 30*kumo2);
		m_imghaikei->Draw();
		m_imghaikei->setPos(m_backkumo3, 10*kumo3);
		m_imghaikei->Draw();
		
		if (m_backkumo >= -100) {
			m_backkumo -= 3;
		}
		if (m_backkumo <= -100) {
			m_backkumo = 1200;
			m_kumopatarnA--;
		}

		if (m_backkumo2 >= -100) {
			m_backkumo2 -= 2;
			}
		if (m_backkumo2 <= -100) {
			m_backkumo2 = 1200;
			m_kumopatarnB--;
		}

		if (m_backkumo3 >= -100) {
			m_backkumo3 -= 1;
		}
		if (m_backkumo3 <= -100) {
			m_backkumo3 = 1200;
			m_kumopatarnC--;
		}

		
		
		
		
	}
		if (f ==true) {
			//���ƍ������J��Ԃ����}�b�v�`�b�v��z�u�E�\������
			for (int i = 0; i < MAP_HEIGHT; i++) {
				for (int j = 0; j < MAP_WIDTH; j++) {
					if (m_mapData[i][j] == 0) continue;
					//�}�b�v�`�b�v�̎�ނ��擾
					int t = m_mapData[i][j];
					//���W�ݒ�
					m_img->setPos(j * 32, i * 32);
					//�\���T�C�Y�ݒ�
					m_img->setSize(32, 32);
					//�\���̈�ݒ�
					m_img->setRect(t * 32, 0, t * 32 + 32, 32);
					//�`��
					m_img->Draw();
				}
			}
		}
	
	

}
int CMap::GetTipData(CVector2D pos) {
	int x = pos.x / 32;	//���W���`�b�v�P�ʂ̏ꏊ�ɕϊ�
	int y = pos.y / 32;
	//�͂ݏo����h��
	if (x < 0) x = 0;
	if (x >= MAP_WIDTH) x = MAP_WIDTH-1;
	if (y < 0) y = 0;
	if (y >= MAP_HEIGHT) y = MAP_HEIGHT - 1;
	//pos�̏ꏊ�̃`�b�v�̎�ނ�Ԃ�
	return m_mapData[y][x];
}