#include "stdafx.h"
#include "CubeRobot.h"


CubeRobot::CubeRobot()
{
}


CubeRobot::~CubeRobot()
{
}

void CubeRobot::Initialize()
{
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);
	D3DXCreateTextureFromFile(
		GameManager::GetDevice(),
		L"./Data/Texture/Box.jpg",
		&texture);
}

void CubeRobot::Destroy()
{
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);
	SAFE_RELEASE(texture);
}

void CubeRobot::Render(const D3DXMATRIXA16& view, const D3DXMATRIXA16& projection)
{
	world *= view * projection;
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetTexture(0, texture);

	FVF_PositionColorTexture vertexT[36];
	D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255);

	//front
	vertexT[0].pos = D3DXVECTOR3(-1, 0, -1);
	vertexT[0].color = color;
	vertexT[0].tex = D3DXVECTOR2(0, 1);
	vertexT[1].pos = D3DXVECTOR3(1, 2, -1);
	vertexT[1].color = color;
	vertexT[1].tex = D3DXVECTOR2(1, 0);
	vertexT[2].pos = D3DXVECTOR3(1, 0, -1);
	vertexT[2].color = color;
	vertexT[2].tex = D3DXVECTOR2(1, 1);

	vertexT[3].pos = D3DXVECTOR3(-1, 0, -1);
	vertexT[3].color = color;
	vertexT[3].tex = D3DXVECTOR2(0, 1);
	vertexT[4].pos = D3DXVECTOR3(-1, 2, -1);
	vertexT[4].color = color;
	vertexT[4].tex = D3DXVECTOR2(0, 0);
	vertexT[5].pos = D3DXVECTOR3(1, 2, -1);
	vertexT[5].color = color;
	vertexT[5].tex = D3DXVECTOR2(1, 0);

	//back
	vertexT[6].pos = D3DXVECTOR3(-1, 0, 1);
	vertexT[6].color = color;
	vertexT[6].tex = D3DXVECTOR2(0, 1);
	vertexT[7].pos = D3DXVECTOR3(1, 2, 1);
	vertexT[7].color = color;
	vertexT[7].tex = D3DXVECTOR2(1, 0);
	vertexT[8].pos = D3DXVECTOR3(-1, 2, 1);
	vertexT[8].color = color;
	vertexT[8].tex = D3DXVECTOR2(1, 1);

	vertexT[9].pos = D3DXVECTOR3(-1, 0, 1);
	vertexT[9].color = color;
	vertexT[9].tex = D3DXVECTOR2(0, 1);
	vertexT[10].pos = D3DXVECTOR3(1, 0, 1);
	vertexT[10].color = color;
	vertexT[10].tex = D3DXVECTOR2(0, 0);
	vertexT[11].pos = D3DXVECTOR3(1, 2, 1);
	vertexT[11].color = color;
	vertexT[11].tex = D3DXVECTOR2(1, 0);

	//left
	vertexT[12].pos = D3DXVECTOR3(-1, 0, 1);
	vertexT[12].color = color;
	vertexT[12].tex = D3DXVECTOR2(0, 1);
	vertexT[13].pos = D3DXVECTOR3(-1, 2, -1);
	vertexT[13].color = color;
	vertexT[13].tex = D3DXVECTOR2(1, 0);
	vertexT[14].pos = D3DXVECTOR3(-1, 0, -1);
	vertexT[14].color = color;
	vertexT[14].tex = D3DXVECTOR2(1, 1);

	vertexT[15].pos = D3DXVECTOR3(-1, 0, 1);
	vertexT[15].color = color;
	vertexT[15].tex = D3DXVECTOR2(0, 1);
	vertexT[16].pos = D3DXVECTOR3(-1, 2, 1);
	vertexT[16].color = color;
	vertexT[16].tex = D3DXVECTOR2(0, 0);
	vertexT[17].pos = D3DXVECTOR3(-1, 2, -1);
	vertexT[17].color = color;
	vertexT[17].tex = D3DXVECTOR2(1, 0);

	//right
	vertexT[18].pos = D3DXVECTOR3(1, 0, -1);
	vertexT[18].color = color;
	vertexT[18].tex = D3DXVECTOR2(0, 1);
	vertexT[19].pos = D3DXVECTOR3(1, 2, -1);
	vertexT[19].color = color;
	vertexT[19].tex = D3DXVECTOR2(0, 0);
	vertexT[20].pos = D3DXVECTOR3(1, 2, 1);
	vertexT[20].color = color;
	vertexT[20].tex = D3DXVECTOR2(1, 0);

	vertexT[21].pos = D3DXVECTOR3(1, 0, -1);
	vertexT[21].color = color;
	vertexT[21].tex = D3DXVECTOR2(0, 1);
	vertexT[22].pos = D3DXVECTOR3(1, 2, 1);
	vertexT[22].color = color;
	vertexT[22].tex = D3DXVECTOR2(1, 0);
	vertexT[23].pos = D3DXVECTOR3(1, 0, 1);
	vertexT[23].color = color;
	vertexT[23].tex = D3DXVECTOR2(1, 1);

	//up
	vertexT[24].pos = D3DXVECTOR3(-1, 2, -1);
	vertexT[24].color = color;
	vertexT[24].tex = D3DXVECTOR2(0, 1);
	vertexT[25].pos = D3DXVECTOR3(-1, 2, 1);
	vertexT[25].color = color;
	vertexT[25].tex = D3DXVECTOR2(0, 0);
	vertexT[26].pos = D3DXVECTOR3(1, 2, 1);
	vertexT[26].color = color;
	vertexT[26].tex = D3DXVECTOR2(1, 0);

	vertexT[27].pos = D3DXVECTOR3(-1, 2, -1);
	vertexT[27].color = color;
	vertexT[27].tex = D3DXVECTOR2(0, 1);
	vertexT[28].pos = D3DXVECTOR3(1, 2, 1);
	vertexT[28].color = color;
	vertexT[28].tex = D3DXVECTOR2(1, 0);
	vertexT[29].pos = D3DXVECTOR3(1, 2, -1);
	vertexT[29].color = color;
	vertexT[29].tex = D3DXVECTOR2(1, 1);

	//down
	vertexT[30].pos = D3DXVECTOR3(-1, 0, -1);
	vertexT[30].color = color;
	vertexT[30].tex = D3DXVECTOR2(0, 0);
	vertexT[31].pos = D3DXVECTOR3(1, 0, 1);
	vertexT[31].color = color;
	vertexT[31].tex = D3DXVECTOR2(1, 1);
	vertexT[32].pos = D3DXVECTOR3(-1, 0, 1);
	vertexT[32].color = color;
	vertexT[32].tex = D3DXVECTOR2(1, 0);

	vertexT[33].pos = D3DXVECTOR3(-1, 0, -1);
	vertexT[33].color = color;
	vertexT[33].tex = D3DXVECTOR2(0, 0);
	vertexT[34].pos = D3DXVECTOR3(1, 0, -1);
	vertexT[34].color = color;
	vertexT[34].tex = D3DXVECTOR2(0, 1);
	vertexT[35].pos = D3DXVECTOR3(1, 0, 1);
	vertexT[35].color = color;
	vertexT[35].tex = D3DXVECTOR2(1, 1);

	GameManager::GetDevice()->SetFVF(FVF_PositionColorTexture::FVF);
	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexT,
		sizeof(FVF_PositionColorTexture));
}

void CubeRobot::Update()
{
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		position += direction * 0.05f;
	}

	if (KEYMANAGER->isStayKeyDown('S'))
	{
		position -= direction * 0.05f;
	}

	if (KEYMANAGER->isStayKeyDown('Q'))
	{
		xRadian -= 0.05f;
	}

	if (KEYMANAGER->isStayKeyDown('E'))
	{
		xRadian += 0.05f;
	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		yRadian -= 0.05f;
	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		yRadian += 0.05f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		hasRobotJumped = true;
	}

	if (hasRobotJumped)
	{
		position.x += cosf(jumpAngle) * jumpSpeed;
		position.y -= -sinf(jumpAngle) * jumpSpeed - gravity;
		gravity -= 0.0007f;

		if (position.y < 0)
		{
			position.y = 0;
			gravity = 0.0f;
			hasRobotJumped = false;
		}
	}

	D3DXMatrixIdentity(&world);

	D3DXMatrixRotationX(&rotX, xRadian);
	D3DXMatrixRotationY(&rotY, yRadian);
	D3DXMatrixRotationZ(&rotZ, zRadian);
	world *= rotX * rotY * rotZ;

	D3DXVec3TransformCoord(&direction, &D3DXVECTOR3(0, 0, 1), &world);

	D3DXMatrixTranslation(&trans, position.x, position.y, position.z);
	printf_s("positionX: %.2f / positionY: %.2f / positionZ: %.2f\n", position.x, position.y, position.z);
	world = world * trans;

}

LRESULT CubeRobot::RobotInputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		mouseDown = true;
		mouseStart.x = GET_X_LPARAM(lParam);
		mouseStart.y = GET_Y_LPARAM(lParam);
	}
	break;
	case WM_LBUTTONUP:
	{
		mouseDown = false;
	}
	break;
	case WM_MOUSEMOVE:
	{
		if (mouseDown)
		{
			POINT mouseCurrent;
			mouseCurrent.x = GET_X_LPARAM(lParam);
			mouseCurrent.y = GET_Y_LPARAM(lParam);

			int deltaX = mouseCurrent.x - mouseStart.x;
			int deltaY = mouseCurrent.y - mouseStart.y;
			xRadian -= (float)deltaY*0.01f;
			yRadian -= (float)deltaX*0.01f;

			mouseStart = mouseCurrent;
		}
	}
	break;
	default:
		break;
	}
	return 0;
}