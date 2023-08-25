#pragma once
#include<windows.h>
#include <ctime>
#include <cstdlib>
#include "CObject.h"
#include "CCore.h"


//std::vector<Mush*> musharr;


enum class MushState
{
	IDLE,
	ATTACK,
	DIE,
};

class Mush
{

private:
	MushState ms;
private:

	POINT Pos;
	
	HBITMAP hOrangeMushroomImage;
	BITMAP bitOrangeMushroom;
	HBITMAP hOldBitmap;

	int Speed = 5;
	int Dir = -1;
	int RUN_FRAME_MAX = 3;
	int RUN_FRAME_MIN = 0;
	int curframe = RUN_FRAME_MIN;
	bool mushFlag = true;

	std::vector<Mush*> musharr;

	double bx = 69;
	int by = 70;

	//Vec2 m_vPos ;
	//Vec2 m_vScale  ;
	
public:
	Mush();
	Mush(POINT m_Pos, HWND hWnd);
	~Mush();
	void Update();
	void UpdateState();
	//void render();
	void Draw();
	BOOL Collision();
	int Init(HWND _hWnd, POINT _ptResolution);
	//HWND GetMainHwnd() { return  }


private:
	
	
};

