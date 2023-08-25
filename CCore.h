#pragma once
#include "framework.h"
#include "define.h"
#include <vector>
#include "Mush.h"

class Mush;

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능




class CCore
{
private:

	SINGLE(CCore);

	HWND m_hWnd; // 메인 윈도우 핸들
	POINT m_ptResolution; // 메인 윈도우 해상도
	HDC m_hDC; // 메인

	HBITMAP m_hBit;
	HDC hmemDC; //서브

	
	//std::vector<Mush*> musharr;
	
public:

	int Init(HWND _hWnd, POINT pt_Resolution);
	void progress();



private:
	CCore();
	~CCore();



	HWND GethWnd() { return m_hWnd; }
	HDC GethDC() { return m_hDC; }
	HDC GetmemDC() { return hmemDC; }
	void Render();
	POINT GetResolution(POINT m_Resolution) { return m_Resolution; };

public:
	//void addMush()
	//{
	//	Mush* mush = new Mush;
	//	musharr.push_back(mush);
	//}


};
