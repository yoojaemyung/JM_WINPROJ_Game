#include "CAnimation.h"
#include "pch.h"

CAnimation::CAnimation()
{
}

CAnimation::~CAnimation()
{
}

void CAnimation::MushLoad(std::wstring _strPath)
{
    hOrangeMushroomImage = (HBITMAP)LoadImage(nullptr, TEXT("Images/주황버섯.bmp")
        , IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (hOrangeMushroomImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("이미지 로드 에러"), _T("에러"), MB_OK);
        return;
    }
    GetObject(hOrangeMushroomImage, sizeof(BITMAP), &bitOrangeMushroom);

    RUN_FRAME_MIN = 0;
    curframe = RUN_FRAME_MIN;


}

void CAnimation::Render()
{
    
}
