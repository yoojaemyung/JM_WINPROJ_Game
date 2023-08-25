#pragma once
#include "framework.h"
#include "define.h"
#include <vector>
#include "Mush.h"

class Mush;

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����




class CCore
{
private:

	SINGLE(CCore);

	HWND m_hWnd; // ���� ������ �ڵ�
	POINT m_ptResolution; // ���� ������ �ػ�
	HDC m_hDC; // ����

	HBITMAP m_hBit;
	HDC hmemDC; //����

	
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
