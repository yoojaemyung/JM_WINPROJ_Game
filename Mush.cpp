#include "Mush.h"
#include "CCore.h"
#include "pch.h"



Mush::Mush()
{
	MushState::IDLE;
	Pos.x = 1560;
	Pos.y = 505;
	//Speed;
	//Dir;
	hOrangeMushroomImage = (HBITMAP)LoadImage(nullptr, TEXT("Images/주황버섯1.bmp")
		, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (hOrangeMushroomImage == NULL)
	{
		DWORD dwError = GetLastError();
		MessageBox(NULL, _T("이미지 로드 에러"), _T("에러"), MB_OK);
		return;
	}
	GetObject(hOrangeMushroomImage, sizeof(BITMAP), &bitOrangeMushroom);




	/*IdleAnim = new CAnimation;
	IdleAnim->MushLoad();
	AttackAnim = new CAnimation;
	AttackAnim->Load(경로);
	DieAnim = new CAnimation;
	DieAnim->Load(경로);+*/

}

Mush::Mush(POINT m_pos, HWND hWnd)
{

	/*m_pos.x = 1560;
	m_pos.y = 505;
	Pos.x = m_pos.x;
	Pos.y = m_pos.y;*/
	//Speed = 10;
	//Dir.x = 1;
	//Dir.y = 0;
	//radius = 5;
	
	
}

int Mush::Init(HWND _hWnd, POINT _ptResolution)
{
	//m_hWnd = _hWnd;
	//m_ptResolution = _ptResolution;

	////RECT rt = { 0,0 ,m_ptResolution.x , m_ptResolution.y };
	////AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	////SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	//m_hDC = GetDC(m_hWnd);

	//// 이중 버퍼링 용도의 비트맵과 DC를 만든다.

	//m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	//m_memDC = CreateCompatibleDC(m_hDC);

	//HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	//DeleteObject(hOldBit);

	return 1;
}

Mush::~Mush()
{

}

void Mush::Update()
{
	//Collision();
	Pos.x -= 10;//Dir.x * Speed;
	//UpdateState();

	Mush::Draw();
	curframe++;
	if (curframe > 2)
		curframe = RUN_FRAME_MIN;
	/*if (mushFlag == false && curframe > 1)
	{
		curframe = RUN_FRAME_MIN;


	}*/
	


	if (curframe == 1)
		Pos.y -= 15;
	if (curframe == 2)
		Pos.y += 15;
	
	//InvalidateRect(hWnd, NULL, false);
	
}

void Mush::UpdateState()
{

	//어떤 조건에서 어떤 상태로 바뀔지
}

//void Mush::render(HDC hdc)
//{

//}

void Mush::Draw()
{
	HDC hmemDC = CCore::GetInst()->GetmemDC();
	HDC m_hDC = CCore::GetInst()->GethDC();
	//HWND hWnd = CCore::GetInst()->GethWnd();

	hmemDC = CreateCompatibleDC(m_hDC);

	hOldBitmap = (HBITMAP)SelectObject(hmemDC, hOrangeMushroomImage);
	
	int xStart = curframe * bx;
	int yStart = by;



	TransparentBlt(m_hDC, Pos.x, Pos.y, bx, by, hmemDC, xStart, yStart, bx, by, RGB(255, 0, 255));



	SelectObject(hmemDC, hOldBitmap);

	DeleteDC(hmemDC);


}

BOOL Mush::Collision()
{
	
	return 0;
}
