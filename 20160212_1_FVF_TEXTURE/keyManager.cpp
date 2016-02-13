#include "stdafx.h"
#include "keyManager.h"
keyManager::keyManager()
{
}
keyManager::~keyManager()
{
}
//==================================================================
//		## 생성자와 소멸자는 더이상 사용하지 않는다 ##
//==================================================================

HRESULT keyManager::init(void)
{
	//키는 눌려지지 않은 상태로 초기화 해준다
	for (int i = 0; i < KEYMAX; i++)
	{
		this->getKeyUp().set(i, false);
		this->getKeyUp().set(i, false);
	}

	return S_OK;
}

void keyManager::release(void)
{
}

//키를 한번 누르면
bool keyManager::isOnceKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->getKeyDown()[key])
		{
			this->setKeyDown(key, true);
			return true;
		}
	}
	else this->setKeyDown(key, false);

	return false;
}

//키를 눌렀다 때면
bool keyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) this->setKeyUp(key, true);
	else
	{
		if (this->getKeyUp()[key])
		{
			this->setKeyUp(key, false);
			return true;
		}
	}

	return false;
}

//키를 누르고 있으면
bool keyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

//토글 키 : 한번 누르면 계쏙 신호 들어오는 ex)capslock
bool keyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}