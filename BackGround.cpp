#include "pch.h"
#include "CCore.h"
#include "BackGround.h"

BackGround::BackGround()
{
	hBackImage = (HBITMAP)LoadImage(nullptr, TEXT("Images/BackGround3.bmp")
		        , IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		
		    if (hBackImage == nullptr)
		    {
		        DWORD dwError = GetLastError();
		        MessageBox(nullptr, _T("이미지 로드 에러"), _T("에러"), MB_OK);
		        return;
		    }
		   GetObject(hBackImage, sizeof(BITMAP), &bitBack);
}

BackGround::~BackGround()
{
}

void BackGround::DrawBack()
{
	HDC hmemDC = CCore::GetInst()->GetmemDC();
	HDC m_hDC = CCore::GetInst()->GethDC();
	//HWND hWnd = CCore::GetInst()->GethWnd();
	int bx, by;

	hmemDC = CreateCompatibleDC(m_hDC);

	hOldBitmap = (HBITMAP)SelectObject(hmemDC, hBackImage);
	bx = bitBack.bmWidth;
	by = bitBack.bmHeight;
	
	BitBlt(m_hDC, 0, 0, bx, by, hmemDC, 0, 0, SRCCOPY);

	SelectObject(hmemDC, hOldBitmap);

	DeleteDC(hmemDC);
}
