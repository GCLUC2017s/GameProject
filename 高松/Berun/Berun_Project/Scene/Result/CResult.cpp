#include "CResult.h"

CResult::CResult()
{
	CSound::GetInstance()->GetSound("RESULT_BGM")->Play();
}

CResult::~CResult()
{
	CSound::GetInstance()->GetSound("RESULT_BGM")->Stop();
}

void CResult::Update()
{
	//CItem::GetInstance()->AddItem(eCarrotItem,0);
	/*
	if (PUSH_KEY_ENTER)
	{

	}
	if (PUSH_KEY_UP)
	{

	}
	if (PUSH_KEY_DOWN)
	{

	}
	if (PUSH_KEY_RIGHT)
	{

	}
	if (PUSH_KEY_LEFT)
	{

	}
	*/
}

void CResult::Draw()
{
}
