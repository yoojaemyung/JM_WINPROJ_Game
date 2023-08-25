#pragma once
class BackGround
{
private:

	HBITMAP hBackImage;
	HBITMAP hOldBitmap;
	BITMAP bitBack;
public:
	BackGround();
	~BackGround();

	void DrawBack();
};

