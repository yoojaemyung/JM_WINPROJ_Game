#pragma once
#include <string>
#include "framework.h"

class CAnimation
{
private:
	HBITMAP hOrangeMushroomImage;
	BITMAP bitOrangeMushroom;
	int RUN_FRAME_MIN = 0;
	int curframe = RUN_FRAME_MIN;

public:
	CAnimation();
	~CAnimation();
public:
	void MushLoad(std::wstring _strPath);
	void Render();
};

