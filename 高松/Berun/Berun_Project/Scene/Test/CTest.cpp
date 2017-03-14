#include "CTest.h"

CTest::CTest()
{
}

CTest::~CTest()
{
}

void CTest::Update()
{
	CTaskManager::GetInstance()->Add(new CMap());
}

void CTest::Draw()
{
}
