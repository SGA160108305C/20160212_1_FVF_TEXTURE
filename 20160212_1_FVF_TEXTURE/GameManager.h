#pragma once

#include <time.h>

#include "Camera.h"
#include "Grid.h"
#include "CubeRobot.h"


class GameManager
{
private:
	GameManager();
	GameManager(const GameManager& other);//copy constructor
	~GameManager();

public:
	static GameManager& Get()//get singleton instance
	{
		static GameManager instance;//Compilers typically use a hidden flag variable to indicate if the local statics have already been initialized, and this flag is checked on every entry to the function. Obviously this is a small performance hit, but what's more of a concern is that this flag is not guaranteed to be thread-safe. http://stackoverflow.com/questions/246564/what-is-the-lifetime-of-a-static-variable-in-a-c-function
		return instance;
	}	
	
	static inline LPDIRECT3DDEVICE9 GetDevice(){ return GameManager::Get().GetInstanceDevice(); }
	static inline double GetTick(){ return GameManager::Get().GetCurrentTick(); }
	static inline Camera* GetCamera(){ return GameManager::Get().GetInstanceCamera(); }

	void Initialize(HWND handle);
	void Destroy();
	void Loop(double tick);
	LRESULT GameInputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	inline HWND GetWindowHandle(){ return windowHandle; }	

protected:
	bool hasInitialized = false;
	double currentTickTime = 0.0f;
	unsigned long FPSFrameCount = 0.0f;
	float FPSTimeElapsed = 0.0f;
	int frameRate = 0;
	
	HWND windowHandle = nullptr;
	LPDIRECT3D9 direct3d = nullptr;
	LPDIRECT3DDEVICE9 direct3dDevice = nullptr;
		
	CubeRobot* robot = nullptr;
	Camera* camera = nullptr;
	Grid* grid = nullptr;
	
	void Update();
	void Render();

	inline LPDIRECT3DDEVICE9 GetInstanceDevice(){ return direct3dDevice; }
	inline double GetCurrentTick(){ return currentTickTime; }
	inline Camera* GetInstanceCamera(){ return camera; }

	LPD3DXFONT font = nullptr;
}; 

