#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

#include "olcConsoleGameEngine.h"

class OneLoneCoder_Platform : public olcConsoleGameEngine
{
public:
	OneLoneCoder_Platform() {
		m_sAppName = L"chess";
	}
	~OneLoneCoder_Platform() {
	}

private:
	virtual bool OnUserCreate() {
		return true;
	}
	
	virtual bool OnUserUpdate(float fElapsedTime) {
		return true;
	}
};