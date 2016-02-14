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
	D3DXMATRIXA16 world, scale, rotX, rotY, rotZ, trans;

	bool mouseDown = false;
	POINT mouseStart;

	float xRadian = 0.0f;
	float yRadian = 0.0f;
	float zRadian = 0.0f;

	D3DXVECTOR3 direction = D3DXVECTOR3(0, 0, 1);
	D3DXVECTOR3 position = D3DXVECTOR3(0, 0, 0);

	float headHalfX = 1.0f;
	float headHalfZ = 1.0f;
	float headHeight = 2.0f;
	float headBottomY = 10.5f;

	float bodyHalfX = 2.0f;
	float bodyHalfZ = 1.0f;
	float bodyHeight = 4.0f;
	float bodyBottomY = 6.0f;

	float leftArmLeft = -3.5f;
	float rightArmLeft = 2.5f;

	float armWidth = 1.0f;
	float armHalfZ = 0.8f;
	float armHeight = 3.0f;
	float armBottomY = 6.5f;

	float leftLegLeft = -1.7f;
	float rightLegLeft = 0.3f;

	float legWidth = 1.5f;
	float legHalfZ = 1.0f;
	float legHeight = 5.0f;
	float legBottomY = 0.5f;

	float jumpSpeed = 0.3f;
	float gravity = 0.0f;

	bool hasRobotJumped = false;

	LPDIRECT3DTEXTURE9 texture = nullptr;

	D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255);
	FVF_PositionColorTexture vertexHead[36];
	FVF_PositionColorTexture vertexBody[36];
	FVF_PositionColorTexture vertexLeftArm[36];
	FVF_PositionColorTexture vertexRightArm[36];
	FVF_PositionColorTexture vertexLeftLeg[36];
	FVF_PositionColorTexture vertexRightLeg[36];
};
