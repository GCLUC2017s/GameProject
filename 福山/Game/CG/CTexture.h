#ifndef TEXTURU_HPP
#define TEXTURU_HPP
#include <stdio.h>	//ファイルの入力に使用
#include "glut.h"
/*
TGAファイルのヘッダフォーマット
*/
struct STgaheader {
	unsigned char	dummy1[12];
	unsigned short	width;		//幅
	unsigned short	height;	//高さ
	unsigned char	depth;	//ビットの深さ
	unsigned char	dummy2;
};
/*
テクスチャークラス
*/
class CTexture {
public:
	//テクスチャID
	GLuint id;
	//TGAファイルのヘッダ情報
	STgaheader header;
	/*
	デフォルトコンストラクタ
	*/
	CTexture() : id(0) {}
	/*
	デストラクタ（このインスタンスが破棄されるときに実行される）
	*/
	~CTexture() {
		//テクスチャデータがあれば削除する
		if (id != 0) {
			//テクスチャデータの削除
			glDeleteTextures(1, &id);
			id = 0;
		}
	}

	/*
	画像ファイルの読み込み（テクスチャファイルの読み込み）
	*/
	void load(const char* filename) {
		//画像データ
		unsigned char* data;
		//ファイルポインタの作成
		FILE *fp;
		errno_t error;
		//ファイルオープン
		error = fopen_s(&fp, filename, "rb");
		//エラーのときはリターン
		if (error != 0) {
			printf("file not found:%s\n", filename);
			return;
		}
		//ヘッダ情報を読み込む
		fread(&header, sizeof(header), 1, fp);
		//画像データのバイト数を計算する
		int length = header.width * header.height * header.depth / 8;
		//画像データの格納領域を確保
		data = new unsigned char[length];
		//画像データをヘッダの続きから読み込む
		fread(data, length, 1, fp);
		//画像ファイルのクローズ
		fclose(fp);

		//テクスチャデータの作成
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexParameteri(GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,
			GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		if (header.depth == 32)
			//アルファ有りのテクスチャ作成
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, header.width,
			header.height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
		else
			//アルファ無しのテクスチャ作成
			gluBuild2DMipmaps(GL_TEXTURE_2D, 3, header.width,
			header.height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
		glBindTexture(GL_TEXTURE_2D, 0);
		//格納領域を解放
		delete[] data;
	}

};

#endif
