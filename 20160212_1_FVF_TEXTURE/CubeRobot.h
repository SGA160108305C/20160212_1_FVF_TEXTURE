#pragma once

class CubeRobot
{
public:
	CubeRobot();
	~CubeRobot();

	void Initialize();
	void Destroy();
	void Update();
	void Render(const D3DXMATRIXA16& view, const D3DXMATRIXA16& projection);

	LRESULT RobotInputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	D3DXVECTOR3* getRobotPosition() { return &position; }
	float* getXradian() { return &xRadian; }
	float* getYradian() { return &yRadian; }

protected:
	D3DXMATRIXA16 world, rotX, rotY, rotZ, trans;

	bool mouseDown = false;
	POINT mouseStart;

	float xRadian = 0.0f;
	float yRadian = 0.0f;
	float zRadian = 0.0f;

	D3DXVECTOR3 direction = D3DXVECTOR3(0, 0, 1);
	D3DXVECTOR3 position = D3DXVECTOR3(0, 0, 0);

	float jumpAngle = D3DX_PI / 0.5f;
	float jumpSpeed = 0.07f;
	float gravity = 0.0f;

	bool hasRobotJumped = false;

	LPDIRECT3DTEXTURE9 texture = nullptr;
};
