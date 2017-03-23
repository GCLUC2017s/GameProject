#pragma once
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")


class CSound{
public:
	wchar_t	file[100];
		int result;

		CSound()
		{
			result = 0;

		}

		void sendstring(wchar_t*w){

			wchar_t		buf[100];
			wsprintf(buf, w, file);
			result = mciSendString(buf, NULL, 0, NULL);

		}

		void load(wchar_t*filename)
		{
			wcscpy(file, filename);
			sendstring(L"close %s");
			sendstring(L"open %s");


		}


		void play()
		{
			sendstring(L"play %s from 0");
		}

		void repeat()
		{
			sendstring(L"play %s from 0 repeat");
		}


		void stop()
		{
			sendstring(L"stop %s");
		}

		void close()
		{
			sendstring(L"close %s");

		}

		~CSound()
		{
			stop();
			close();

		}







};