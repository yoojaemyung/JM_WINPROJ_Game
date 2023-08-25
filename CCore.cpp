#include "CCore.h"
#include "Mush.h"
#include "pch.h"
#include "CObject.h"





CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, hmemDC(0)

{
	
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(hmemDC);
	DeleteObject(m_hBit);
}

int CCore::Init(HWND _hWnd, HDC hdc, POINT pt_Resolution)
{

	m_hWnd = _hWnd;
	m_ptResolution = pt_Resolution;

	m_ptResolution.x = 1950;//1645;
	m_ptResolution.y = 1000;//720;

	RECT rt = { 0,0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top,0);

	

	m_hDC = GetDC(m_hWnd);
	//m_hDC = hdc;

	m_hBit = CreateCompatibleBitmap(hmemDC, m_ptResolution.x, m_ptResolution.y);
	//hmemDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(hmemDC, m_hBit);
	DeleteObject(hOldBit);


	

	return 0;
}

void CCore::progress()
{
	//처음에 hdc 초기화
	//각 객체들에 대해서 반복문 돌려서 각각 Render() 호출해준다 -> memdc에 다 그려짐
	//그려진 memdc를 hdc에 옮겨줘야겠찌

	//화면 Clear
	//Rectangle(m_hDC, -1, -1, m_ptResolution.x +1, m_ptResolution.y +1);

	Rectangle(m_hDC, 10, 10, 110, 110);



	//
	//for (auto iter = musharr.begin(); iter != musharr.end(); iter++)
	//{
	//	(*iter)->musharr;
	//
	//}
	


	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, hmemDC, 0, 0, SRCCOPY);
	          



}


