#ifndef TEXTURU_HPP
#define TEXTURU_HPP
#include <stdio.h>	//�t�@�C���̓��͂Ɏg�p
#include "glut.h"
/*
TGA�t�@�C���̃w�b�_�t�H�[�}�b�g
*/
struct STgaheader {
	unsigned char	dummy1[12];
	unsigned short	width;		//��
	unsigned short	height;	//����
	unsigned char	depth;	//�r�b�g�̐[��
	unsigned char	dummy2;
};
/*
�e�N�X�`���[�N���X
*/
class CTexture {
public:
	//�e�N�X�`��ID
	GLuint id;
	//TGA�t�@�C���̃w�b�_���
	STgaheader header;
	/*
	�f�t�H���g�R���X�g���N�^
	*/
	CTexture() : id(0) {}
	/*
	�f�X�g���N�^�i���̃C���X�^���X���j�������Ƃ��Ɏ��s�����j
	*/
	~CTexture() {
		//�e�N�X�`���f�[�^������΍폜����
		if (id != 0) {
			//�e�N�X�`���f�[�^�̍폜
			glDeleteTextures(1, &id);
			id = 0;
		}
	}

	/*
	�摜�t�@�C���̓ǂݍ��݁i�e�N�X�`���t�@�C���̓ǂݍ��݁j
	*/
	void load(const char* filename) {
		//�摜�f�[�^
		unsigned char* data;
		//�t�@�C���|�C���^�̍쐬
		FILE *fp;
		errno_t error;
		//�t�@�C���I�[�v��
		error = fopen_s(&fp, filename, "rb");
		//�G���[�̂Ƃ��̓��^�[��
		if (error != 0) {
			printf("file not found:%s\n", filename);
			return;
		}
		//�w�b�_����ǂݍ���
		fread(&header, sizeof(header), 1, fp);
		//�摜�f�[�^�̃o�C�g�����v�Z����
		int length = header.width * header.height * header.depth / 8;
		//�摜�f�[�^�̊i�[�̈���m��
		data = new unsigned char[length];
		//�摜�f�[�^���w�b�_�̑�������ǂݍ���
		fread(data, length, 1, fp);
		//�摜�t�@�C���̃N���[�Y
		fclose(fp);

		//�e�N�X�`���f�[�^�̍쐬
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexParameteri(GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,
			GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		if (header.depth == 32)
			//�A���t�@�L��̃e�N�X�`���쐬
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, header.width,
			header.height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
		else
			//�A���t�@�����̃e�N�X�`���쐬
			gluBuild2DMipmaps(GL_TEXTURE_2D, 3, header.width,
			header.height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
		glBindTexture(GL_TEXTURE_2D, 0);
		//�i�[�̈�����
		delete[] data;
	}

};

#endif
