#pragma once
#include "CMatrix.h"
#include "CLight.h"
#include "CCamera.h"
#include "CShader.h"
#include <functional>
class CShadow {
public:
	enum {
		eNone,
		eShadow,
		eDisplay,
	};
	public:
	GLuint m_frameBuffer;
	GLuint m_texBuffer;
	GLuint m_edgeBuffer;
	GLuint m_effectBuffer;
	GLuint  m_depthrenderbuffer;
	GLuint m_effectFrameBuffer;
	int		m_texWidth;
	int		m_texHeight;
	int		m_screenWidth;
	int		m_screenHeight;
	CMatrix m_lightProj;
	CMatrix m_lightView;
	float	m_length;
	int		m_state;
	CShader *m_depthShader;
	CShader *m_effectShader;
	CShader *m_noeffectShader;
	static CShadow *m_shadow;
	void AutoCamera();
public:
	static void CreateInscance(int screenWidth,int screenHeight,float length=256,int texWidth = 1024, int texHeight = 1024) {
		if (m_shadow) return;
		m_shadow = new CShadow(screenWidth, screenHeight,length,texWidth ,texHeight);
	}
	static CShadow* GetInstance() {
		if (!m_shadow) CreateInscance(CCamera::GetCurrent()->GetWhidth(), CCamera::GetCurrent()->GetHeight());
		return m_shadow;
	}
	static void ClearInstance() {
		if (!m_shadow) return;
		delete m_shadow;
		m_shadow = nullptr;
	}
	CShadow(int screenWidth, int screenHeight,float length,int texWidth, int texHeight);
	~CShadow();
	void SetLightProjectionMatrix(CMatrix &m) {
		m_lightProj = m;
	}
	void SetLightViewMatrix(CMatrix &m) {
		m_lightView = m;
	}
	void Render(std::function<void()> render, bool shadow=true, bool autoCamera = true,bool edge=false,bool effect=false,bool clear=true);
	void DrawDepthTex(int w, int h);
	int GetState() {
		return m_state;
	}
};