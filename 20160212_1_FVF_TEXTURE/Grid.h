#pragma once
#include <list>

class Line
{
public:
	Line()
	{
		start = end = D3DXVECTOR3();
		color = D3DCOLOR_XRGB(50, 50, 50);
	}
	Line(D3DXVECTOR3& _start, D3DXVECTOR3& _end, COLORREF _color = D3DCOLOR_XRGB(50, 50, 50))
	{
		start = _start;
		end = _end;
		color = _color;
	}
	~Line(){};

	D3DXVECTOR3 start;
	D3DXVECTOR3 end;
	COLORREF color;
};

class Grid
{
public:
	Grid();
	~Grid();

	void Initialize(int lineCount = 10, float interval = 1.0f);
	void Destroy();
	void Render(const D3DXMATRIXA16& view, const D3DXMATRIXA16& projection);

private:
	std::list<Line> lines;
};

