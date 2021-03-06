#pragma once

// D3D 정점 FVF플래그 작성 순서 및 플래그
// 
// 1. Position 정점의 좌표 x,y,z(float) :  D3DFVF_XYZ
// 2. RHW (float) :  D3DFVF_XYZRHW (D3DFVF_XYZ 또는 D3DFVF_NORMAL과 같이 사용불가)
// 3. Blending Weight Data 결합 가중치 (float)       : D3DFVF_XYZB1 ~ D3DFVF_XYZB5
// 4. Vertex Normal 정점의 법선 벡터 x,y,z(float)    : D3DFVF_NORMAL
// 5. Vertex Point Size 정점의 점 크기 (float)       : D3DFVF_PSIZE
// 6. Diffuse Color (DWORD)                          : D3DFVF_DIFFUSE
// 7. Specular Color (DWORD)                         : D3DFVF_SPECULAR
// 8. Texture Coordinate Set 1 (float)               : D3DFVF_TEX0 - D3DFVF_TEX8

struct FVF_PositionColor
{	
	D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0);
	D3DCOLOR color = D3DCOLOR_XRGB(0, 0, 0);
	
	FVF_PositionColor()
	{
	}
	FVF_PositionColor(
		D3DXVECTOR3 _pos, 
		D3DCOLOR _color)
		:pos(_pos), color(_color)
	{
	}

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE, };
};

struct FVF_PositionColorTexture
{
	D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0);
	D3DCOLOR color = D3DCOLOR_XRGB(0, 0, 0);
	D3DXVECTOR2 tex = D3DXVECTOR2(0, 0);

	FVF_PositionColorTexture()
	{
	}
	FVF_PositionColorTexture(
		D3DXVECTOR3 _pos,
		D3DCOLOR _color,
		D3DXVECTOR2 _tex)
		:pos(_pos), color(_color), tex(_tex)
	{
	}

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1, };
};