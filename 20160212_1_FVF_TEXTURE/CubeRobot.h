#pragma once

class CubeRobot
{
public:
	CubeRobot();
	~CubeRobot();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	LRESULT RobotInputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	D3DXVECTOR3* getRobotPosition() { return &position; }
	float* getXradian() { return &xRadian; }
	float* getYradian() { return &yRadian; }

protected:
	float rotationAxisX = 0.0f;
	float rotationAxisY = 0.0f;

	D3DXMATRIXA16 world, rot, trans;

	bool mouseDown = false;
	POINT mouseStart;

	float xRadian = 0.0f;
	float yRadian = 0.0f;

	float modelY = 3.0f;

	D3DXVECTOR3 direction = D3DXVECTOR3(0, modelY, 1);
	D3DXVECTOR3 position = D3DXVECTOR3(0, 3, 0);

	float jumpAngle = D3DX_PI / 0.5f;
	float jumpSpeed = 0.07f;
	float gravity = 0.0f;

	bool hasRobotJumped = false;

	LPDIRECT3DTEXTURE9 texture = nullptr;
};
