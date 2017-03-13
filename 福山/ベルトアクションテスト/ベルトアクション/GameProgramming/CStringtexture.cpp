#include"CStringtexture.h"

void CStringtexture::render(char* pstr, CVector2 pos, float size, float r, float g, float b, float a){
	if (ptexture == 0)
		return;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, ptexture->id);
	glColor4f(r, g, b, a);
	float u, v, W = 20.0f, M = 30.0f,S = 220.0f; // ÇvÇÕâ°ïùÅCÇlÇÕècïùÅCÇrÇÕÉTÉCÉY

	char hoz_str  ='\0';

	for (int i = 0; pstr[i] != '\0'; i++){
		v = -1.0f;
		if ('A' <= pstr[i] && pstr[i] <= 'Z'){
			v = 0.0f;
			u = ((pstr[i] - 'A') * W) / S;
		}
		else if ('0' <= pstr[i] && ';'){ 
			v = 0.0f;
			u = ((pstr[i] - '0') * W) / S;
		}
		else if (pstr[i] == '.'){
			v = 0.0f;
			u = (10 * W) / S;
		}
		if (v >= 0.0f){
			if (hoz_str == '.'){
				pos.x -= size/1.5;
			}
			glBegin(GL_QUADS);
			glTexCoord2f(u, v);
			glVertex2f(pos.x + i * size, pos.y);
			glTexCoord2f(u, v - M / S);
			glVertex2f(pos.x + i * size, pos.y - size * 1.5f);
			glTexCoord2f(u + W / S, v - M / S);
			glVertex2f(pos.x + i * size + size, pos.y - size * 1.5f);
			glTexCoord2f(u + W / S, v);
			glVertex2f(pos.x + i * size + size, pos.y);
			glEnd();
			
		}
		hoz_str = pstr[i];
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}