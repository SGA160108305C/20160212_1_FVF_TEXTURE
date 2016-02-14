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

void Grid::Render(const D3DXMATRIXA16& view, const D3DXMATRIXA16& projection)
{
	/*D3DXMATRIXA16 pipeline = view * projection * viewport;
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
	}*/

	D3DXMATRIXA16 world;
	D3DXMatrixIdentity(&world);

	GameManager::GetDevice()->SetTransform(D3DTS_VIEW, &view);
	GameManager::GetDevice()->SetTransform(D3DTS_PROJECTION, &projection);
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetTexture(0, nullptr);

	FVF_PositionColor lineVertex[44];

	lineVertex[0].pos = D3DXVECTOR3(-10, 0, -10);
	lineVertex[0].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[1].pos = D3DXVECTOR3(10, 0, -10);
	lineVertex[1].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[2].pos = D3DXVECTOR3(-10, 0, -8);
	lineVertex[2].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[3].pos = D3DXVECTOR3(10, 0, -8);
	lineVertex[3].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[4].pos = D3DXVECTOR3(-10, 0, -6);
	lineVertex[4].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[5].pos = D3DXVECTOR3(10, 0, -6);
	lineVertex[5].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[6].pos = D3DXVECTOR3(-10, 0, -4);
	lineVertex[6].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[7].pos = D3DXVECTOR3(10, 0, -4);
	lineVertex[7].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[8].pos = D3DXVECTOR3(-10, 0, -2);
	lineVertex[8].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[9].pos = D3DXVECTOR3(10, 0, -2);
	lineVertex[9].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[10].pos = D3DXVECTOR3(-10, 0, 0);
	lineVertex[10].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[11].pos = D3DXVECTOR3(10, 0, 0);
	lineVertex[11].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[12].pos = D3DXVECTOR3(-10, 0, 2);
	lineVertex[12].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[13].pos = D3DXVECTOR3(10, 0, 2);
	lineVertex[13].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[14].pos = D3DXVECTOR3(-10, 0, 4);
	lineVertex[14].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[15].pos = D3DXVECTOR3(10, 0, 4);
	lineVertex[15].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[16].pos = D3DXVECTOR3(-10, 0, 6);
	lineVertex[16].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[17].pos = D3DXVECTOR3(10, 0, 6);
	lineVertex[17].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[18].pos = D3DXVECTOR3(-10, 0, 8);
	lineVertex[18].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[19].pos = D3DXVECTOR3(10, 0, 8);
	lineVertex[19].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[20].pos = D3DXVECTOR3(-10, 0, 10);
	lineVertex[20].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[21].pos = D3DXVECTOR3(10, 0, 10);
	lineVertex[21].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[22].pos = D3DXVECTOR3(-10, 0, -10);
	lineVertex[22].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[23].pos = D3DXVECTOR3(-10, 0, 10);
	lineVertex[23].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[24].pos = D3DXVECTOR3(-8, 0, -10);
	lineVertex[24].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[25].pos = D3DXVECTOR3(-8, 0, 10);
	lineVertex[25].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[26].pos = D3DXVECTOR3(-6, 0, -10);
	lineVertex[26].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[27].pos = D3DXVECTOR3(-6, 0, 10);
	lineVertex[27].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[28].pos = D3DXVECTOR3(-4, 0, -10);
	lineVertex[28].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[29].pos = D3DXVECTOR3(-4, 0, 10);
	lineVertex[29].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[30].pos = D3DXVECTOR3(-2, 0, -10);
	lineVertex[30].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[31].pos = D3DXVECTOR3(-2, 0, 10);
	lineVertex[31].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[32].pos = D3DXVECTOR3(0, 0, -10);
	lineVertex[32].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[33].pos = D3DXVECTOR3(0, 0, 10);
	lineVertex[33].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[34].pos = D3DXVECTOR3(2, 0, -10);
	lineVertex[34].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[35].pos = D3DXVECTOR3(2, 0, 10);
	lineVertex[35].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[36].pos = D3DXVECTOR3(4, 0, -10);
	lineVertex[36].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[37].pos = D3DXVECTOR3(4, 0, 10);
	lineVertex[37].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[38].pos = D3DXVECTOR3(6, 0, -10);
	lineVertex[38].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[39].pos = D3DXVECTOR3(6, 0, 10);
	lineVertex[39].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[40].pos = D3DXVECTOR3(8, 0, -10);
	lineVertex[40].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[41].pos = D3DXVECTOR3(8, 0, 10);
	lineVertex[41].color = D3DCOLOR_XRGB(128, 128, 128);

	lineVertex[42].pos = D3DXVECTOR3(10, 0, -10);
	lineVertex[42].color = D3DCOLOR_XRGB(128, 128, 128);
	lineVertex[43].pos = D3DXVECTOR3(10, 0, 10);
	lineVertex[43].color = D3DCOLOR_XRGB(128, 128, 128);

	GameManager::GetDevice()->SetFVF(FVF_PositionColor::FVF);
	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_LINELIST,
		22,
		lineVertex,
		sizeof(FVF_PositionColor)
		);
}
