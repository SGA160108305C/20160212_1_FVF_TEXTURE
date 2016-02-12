#pragma once
#include "GameState.h"
#include "GameState_DX_Base.h"
#include "GameState_FVF.h"


enum GameStateType
{
	STATE_DIRECT_X_BASE = 0,	//�⺻ ������ �����ӿ�ũ. DirectX�ʱ�ȭ
	STATE_FVF,					//FVF, DrawPrimitive(D3D�� �׸���� �ڽ� �׸���)
	STATE_TEXTURE,				//�ؽ��� ���� �� �Ŵ���, ����̽� ������(ť��Ǹ����)
	STATE_HIERARCHY_ANIMATION,	//���� �ִϸ��̼�(���̶�Ű ����)
	STATE_LIGHT,				//����� ��Ƽ����, ��� ����(���� ��ġ�ϱ�)
	STATE_OBJ_LOAD,				//OBJ���Ϸ� �𵨱׸���(�ٸ� ���� ������� ���� ���̵� Ȯ��)
	STATE_PICK_BASE,			//D3DXIntersectTri(��ŷ, Ű�����̵�)
	STATE_VERTEX_BUFFER,		//���ؽ� ����	
	STAET_ASE_LOAD,				//ASE(�ε� �� �ִϸ��̼�.���ʹϾ�� ������ ��ǥ��(y,z, uv, �ﰢ�� ����� ����)) - 3��
	STATE_ACTIONS,				//����, ��������Ʈ
	STATE_COLLISION,			//�浹ó���� �⺻ �޽� �����
	STATE_PICK_MOUSE,			//���콺 ��ŷ( ��ũ�� ��ǥ => 3D ��ǥ )
	STATE_UI,					//UI �� ��Ʈ ���( bind�� )
	STATE_PATH_FIND,			//���ͽ�Ʈ�� �˰���, A*�˰��� - 3��
	STATE_HEIGHTMAP,			//Height��
	STATE_SKINNING,				//��Ű��
	STATE_FRUSTUM_CULLING,		//�������� �ø�
	STATE_BLENDING,				//����
	STATE_PARTICLE,				//��ƼŬ
	STATE_SHADER,				//���̴�
	STATE_THREAD,				//������
	NUM_OF_STATE
};

class GameStateManager
{
private:
	GameStateManager();
	GameStateManager(const GameStateManager& other);//copy constructor
	~GameStateManager();

public:
	static GameStateManager& Get()//get singleton instance
	{
		static GameStateManager instance;//Compilers typically use a hidden flag variable to indicate if the local statics have already been initialized, and this flag is checked on every entry to the function. Obviously this is a small performance hit, but what's more of a concern is that this flag is not guaranteed to be thread-safe. http://stackoverflow.com/questions/246564/what-is-the-lifetime-of-a-static-variable-in-a-c-function
		return instance;
	}

	void Initialize();
	void Destroy();
	void Update();
	void Render();
	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool ChangeGameState(GameStateType state);

protected:
	GameStateType currentState = GameStateType::STATE_DIRECT_X_BASE;
	GameState* gameStates[GameStateType::NUM_OF_STATE];
};

