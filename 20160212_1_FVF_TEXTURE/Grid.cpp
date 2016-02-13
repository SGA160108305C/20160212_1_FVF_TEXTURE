#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
}


Grid::~Grid()
{
}

void Grid::Initialize(int lineCount /*= 10*/, float interval/* = 1.0f*/)
{
	lines.clear();
	int halfLineCount = (int)(lineCount * 0.5f);
	float gridEdge = (float)halfLineCount * interval;

	//일반 줄
	COLORREF color = 0;
	for (int i = 0; i <= halfLineCount; ++i)
	{
		if (i % 5 == 0)
		{
			color = RGB(255, 255, 255);
		}
		else
		{
			color = RGB(128, 128, 128);
		}

		lines.push_back(Line(D3DXVECTOR3(gridEdge, 0.0f, (float)i), D3DXVECTOR3(-gridEdge, 0.0f, (float)i), color));
		lines.push_back(Line(D3DXVECTOR3(gridEdge, 0.0f, (float)-i), D3DXVECTOR3(-gridEdge, 0.0f, (float)-i), color));
		lines.push_back(Line(D3DXVECTOR3((float)i, 0.0f, gridEdge), D3DXVECTOR3((float)i, 0.0f, -gridEdge), color));
		lines.push_back(Line(D3DXVECTOR3((float)-i, 0.0f, gridEdge), D3DXVECTOR3((float)-i, 0.0f, -gridEdge), color));
	}

	//축
	/*color = RGB(255, 0, 0);
	lines.push_back(Line(D3DXVECTOR3(gridEdge, 0.0f, 0.0f), D3DXVECTOR3(-gridEdge, 0.0f, 0.0f), color));

	color = RGB(0, 255, 0);
	lines.push_back(Line(D3DXVECTOR3(0.0f, gridEdge, 0.0f), D3DXVECTOR3(0.0f, -gridEdge, 0.0f), color));

	color = RGB(0, 0, 255);
	lines.push_back(Line(D3DXVECTOR3(0.0f, 0.0f, gridEdge), D3DXVECTOR3(0.0f, 0.0f, -gridEdge), color));*/

}

void Grid::Destroy()
{
	lines.clear();
}

void Grid::Render(HDC targetDC,
	const D3DXMATRIXA16& view,
	const D3DXMATRIXA16& projection,
	const D3DXMATRIXA16& viewport)
{
	D3DXMATRIXA16 pipeline = view * projection * viewport;
	for (auto iter = lines.cbegin(); iter != lines.cend(); ++iter)
	{
		D3DXVECTOR3 start = (*iter).start;
		D3DXVECTOR3 end = (*iter).end;

		D3DXVec3TransformCoord(&start, &start, &pipeline);
		D3DXVec3TransformCoord(&end, &end, &pipeline);

		COLORREF oldColor = SetDCPenColor(targetDC, (*iter).color);
		MoveToEx(targetDC, (int)start.x, (int)start.y, nullptr);
		LineTo(targetDC, (int)end.x, (int)end.y);
		SetDCPenColor(targetDC, oldColor);
	}
}
