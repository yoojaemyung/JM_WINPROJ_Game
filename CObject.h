#pragma once

//¹°Ã¼

class CObject
{
public:
	POINT m_ptPos;
	POINT m_ptScale;
public:
	CObject();
	~CObject();




protected: HBITMAP DoubleBuffer;

public:
	virtual void Update(RECT* rectView) = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void DeleteBitmap() = 0;
	virtual BOOL CheckArea() = 0;


};

