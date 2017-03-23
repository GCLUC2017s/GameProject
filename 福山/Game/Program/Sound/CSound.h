#ifndef SOUND_HPP
#define SOUND_HPP
#include<Windows.h>
#include<mmsystem.h>
#include <stdio.h>
#pragma comment(lib,"winmm.lib")


class CSound{
public:
	char	file[100];
	int result;

	CSound()
	{
		result = 0;

	}

	void sendstring(char *w){

		//wchar_t		buf[100];
		char		buf[100];
		//wsprintf((LPSTR)buf, (LPCSTR)w, file);
		sprintf(buf, w, file);
		result = mciSendString((LPSTR)buf, NULL, 0, NULL);

	}

	void load(char *filename)
	{
		//			wcscpy(file, filename);
		strcpy(file, filename);
		sendstring("close %s");
		sendstring("open %s");
	}


	void play()
	{
		sendstring("play %s from 0");
	}

	void repeat()
	{
		sendstring("play %s from 0 repeat");
	}


	void stop()
	{
		sendstring("stop %s");
	}

	void close()
	{
		sendstring("close %s");

	}

	~CSound()
	{
		stop();
		close();
	}

};
#endif