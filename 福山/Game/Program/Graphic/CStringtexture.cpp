#include"CStringtexture.h"
#include "../CGame/CGame.h"
#define NUM_X 25		//NUMBERのテクスチャ横幅
#define NUM_Y 50		//NUMBERのテクスチャ縦幅
#define NUM_SX 250
#define NUM_SY 50
#define NUM_FILE "../CG/GameScreen/"

CStringtexture::CStringtexture(){
	mPtexture = new CTexture();
	mPtexture->load(NUM_FILE"0to9.tga");
}
CStringtexture::~CStringtexture(){
	CGame::Delete(&mPtexture);
}
void CStringtexture::render(char* pstr, CVector2 pos, float size, float r, float g, float b, float a){

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, mPtexture->id);
	glColor4f(r, g, b, a);
	float u, v, W = NUM_X, M = NUM_Y,SY = NUM_SY,SX = NUM_SX; // Ｗは横幅，Ｍは縦幅，Ｓはサイズ

	char hoz_str  ='\0';

	for (int i = 0; pstr[i] != '\0'; i++){
		v = -1.0f;
		if ('0' <= pstr[i] && ';'){ 
			v = 0.0f;
			u = ((pstr[i] - '0') * W) / SX;
		}
		if (v >= 0.0f){
			
			glBegin(GL_QUADS);
			glTexCoord2f(u, v);
			glVertex2f(pos.x + i * size, pos.y);
			glTexCoord2f(u, v - M / SY);
			glVertex2f(pos.x + i * size, pos.y - size * 1.5f);
			glTexCoord2f(u + W / SX, v - M / SY);
			glVertex2f(pos.x + i * size + size, pos.y - size * 1.5f);
			glTexCoord2f(u + W / SX, v);
			glVertex2f(pos.x + i * size + size, pos.y);
			glEnd();
			
		}
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}