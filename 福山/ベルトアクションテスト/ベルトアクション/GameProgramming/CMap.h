#pragma once
#include "define.h"
#include "CRectangle.h"
#include <stdio.h>
#include <list>
#include <iostream>

class CMap {
public:
/*���X�g�̎g����*//*
	"#include�������"
		#include <list>
		#include <iostream>
	//������

			std::list<�^�̎w��(��)int, float class���@�Ȃ�> �D���Ȗ��O

	//�g����  (�l��������@)

			intlist.push_back(����); ����ŗv�f��ǉ����Ă���    "(  )"�̒��ɂ͒�`�������� <�^�̎w��> �Ɠ������̂�����

			intlist.pop_back();	�@�@ ����ŗv�f���폜���Ă���

	[�d�v�_]

		�����X�g�͂��̂܂܂ł͎g���Ȃ�		�C�e���[�^�\�ƌĂ΂����̂��g��Ȃ��Ƃ����Ȃ� "iterator"

	//������

			std::list<�^�̎w��(��)int, float class���@�Ȃ�>::iterator �D���Ȗ��O; 
			����Ń��X�g�ō�����^���g�����Ƃ��ł���
			(��)
		

			
			#include <list>
			#include <iostream>

			int main()
			{
			using namespace std;

			list<int> intlist;  // int�^�̑o�������X�g
			int i;

			// 10�̗v�f��ǉ����Ă���
			for( i = 0; i < 10; ++i )
			{
			intlist.push_back( i );
			}

			list<int>::iterator it = intlist.begin(); // �C�e���[�^

			while( it != intlist.end() )  // list�̖����܂�
			{
				printf("%d,it"); // �v�f���o��
				++it;  // �C�e���[�^���P�i�߂�
			}

			return 0;
			}



	
	
*//*�I��*/

	CRectangle BGrect; //�w�i��rect

	CTexture *BackGround;

	~CMap();
	CMap();

	void init();
	void update();
	void render();	
};