#include <stdio.h>
#include <stdlib.h>
#include "CShader.h"



CShader::CShader():program(0){
}
CShader::CShader(const char* vertexPath,const char* pixelPath){
	load(vertexPath,pixelPath);
}
bool CShader::readFile(GLuint program,GLuint shader, const char *file) {
	FILE *fp;
	fopen_s(&fp,file, "rb");
	if(!fp) {
		printf("ファイルが開けません[%s]\n",file);
		return false;
	}
	fseek( fp, 0, SEEK_END );
	int size = ftell( fp );
	fseek( fp, 0, SEEK_SET );
	GLchar *code = new char[size];
	fread(code,size,1,fp);
	fclose(fp);

	glShaderSource(shader,1,(const GLchar **)&code,&size);
	glCompileShader(shader);
	glGetShaderiv(shader,GL_COMPILE_STATUS,&compiled);

	if(compiled) {
		GLint length;
		GLchar *log;
		glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&length);
		log = new GLchar[length];
		glGetShaderInfoLog(shader,length,&length,log);
		fprintf(stderr,"compile log='%s'\n",log);
		delete log;
	}
	delete[] code;  

	glAttachShader(program,shader);
	glLinkProgram(program);

	glGetProgramiv(program,GL_LINK_STATUS,&linked);

	if(linked) {
	//	glUseProgram(program);
	} else {
		GLint length;
		GLchar *log;
		glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&length);
		log = (GLchar*) malloc(length);
		glGetShaderInfoLog(shader,length,&length,log);
		fprintf(stderr,"compile log='%s'\n",log);
	}

	
	glDeleteShader(shader);
	//glDeleteShader(flagShader);

	return true;
 
}
bool CShader::load(const char* vertexPath,const char* flagPath){

	program = glCreateProgram();
	if(vertexPath) {

		bool ret = readFile(program,glCreateShader(GL_VERTEX_SHADER),vertexPath);
		if(!ret) return false;
	}
	if(flagPath) {
		
		bool ret = readFile(program,glCreateShader(GL_FRAGMENT_SHADER),flagPath);
		if(!ret) return false;
	}
	

	return true;
	
}
bool CShader::load(const char* path, GLuint type){
	if (!program) program = glCreateProgram();
	if (path) {
		bool ret = readFile(program, glCreateShader(type), path);
		if (!ret) return false;
	}
	return true;
}
CShader::~CShader(){
	if (program>0) glDeleteProgram(program);

}
void CShader::enable(){
	glUseProgram(program);
}
void CShader::disable(){
	glUseProgram(0);
}