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
		&texture
		);

	//head front
	vertexHead[0].pos = D3DXVECTOR3(-headHalfX, headBottomY, -headHalfZ);
	vertexHead[0].color = color;
	vertexHead[0].tex = D3DXVECTOR2(0, 1);
	vertexHead[1].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[1].color = color;
	vertexHead[1].tex = D3DXVECTOR2(1, 0);
	vertexHead[2].pos = D3DXVECTOR3(headHalfX, headBottomY, -headHalfZ);
	vertexHead[2].color = color;
	vertexHead[2].tex = D3DXVECTOR2(1, 1);

	vertexHead[3].pos = D3DXVECTOR3(-headHalfX, headBottomY, -headHalfZ);
	vertexHead[3].color = color;
	vertexHead[3].tex = D3DXVECTOR2(0, 1);
	vertexHead[4].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[4].color = color;
	vertexHead[4].tex = D3DXVECTOR2(0, 0);
	vertexHead[5].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[5].color = color;
	vertexHead[5].tex = D3DXVECTOR2(1, 0);

	//head back
	vertexHead[6].pos = D3DXVECTOR3(-headHalfX, headBottomY, headHalfZ);
	vertexHead[6].color = color;
	vertexHead[6].tex = D3DXVECTOR2(0, 1);
	vertexHead[7].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[7].color = color;
	vertexHead[7].tex = D3DXVECTOR2(1, 0);
	vertexHead[8].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[8].color = color;
	vertexHead[8].tex = D3DXVECTOR2(1, 1);

	vertexHead[9].pos = D3DXVECTOR3(-headHalfX, headBottomY, headHalfZ);
	vertexHead[9].color = color;
	vertexHead[9].tex = D3DXVECTOR2(0, 1);
	vertexHead[10].pos = D3DXVECTOR3(headHalfX, headBottomY, headHalfZ);
	vertexHead[10].color = color;
	vertexHead[10].tex = D3DXVECTOR2(0, 0);
	vertexHead[11].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[11].color = color;
	vertexHead[11].tex = D3DXVECTOR2(1, 0);

	//head left
	vertexHead[12].pos = D3DXVECTOR3(-headHalfX, headBottomY, headHalfZ);
	vertexHead[12].color = color;
	vertexHead[12].tex = D3DXVECTOR2(0, 1);
	vertexHead[13].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[13].color = color;
	vertexHead[13].tex = D3DXVECTOR2(1, 0);
	vertexHead[14].pos = D3DXVECTOR3(-headHalfX, headBottomY, -headHalfZ);
	vertexHead[14].color = color;
	vertexHead[14].tex = D3DXVECTOR2(1, 1);

	vertexHead[15].pos = D3DXVECTOR3(-headHalfX, headBottomY, headHalfZ);
	vertexHead[15].color = color;
	vertexHead[15].tex = D3DXVECTOR2(0, 1);
	vertexHead[16].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[16].color = color;
	vertexHead[16].tex = D3DXVECTOR2(0, 0);
	vertexHead[17].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[17].color = color;
	vertexHead[17].tex = D3DXVECTOR2(1, 0);

	//head right
	vertexHead[18].pos = D3DXVECTOR3(headHalfX, headBottomY, -headHalfZ);
	vertexHead[18].color = color;
	vertexHead[18].tex = D3DXVECTOR2(0, 1);
	vertexHead[19].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[19].color = color;
	vertexHead[19].tex = D3DXVECTOR2(0, 0);
	vertexHead[20].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[20].color = color;
	vertexHead[20].tex = D3DXVECTOR2(1, 0);

	vertexHead[21].pos = D3DXVECTOR3(headHalfX, headBottomY, -headHalfZ);
	vertexHead[21].color = color;
	vertexHead[21].tex = D3DXVECTOR2(0, 1);
	vertexHead[22].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[22].color = color;
	vertexHead[22].tex = D3DXVECTOR2(1, 0);
	vertexHead[23].pos = D3DXVECTOR3(headHalfX, headBottomY, headHalfZ);
	vertexHead[23].color = color;
	vertexHead[23].tex = D3DXVECTOR2(1, 1);

	//head up
	vertexHead[24].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[24].color = color;
	vertexHead[24].tex = D3DXVECTOR2(0, 1);
	vertexHead[25].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[25].color = color;
	vertexHead[25].tex = D3DXVECTOR2(0, 0);
	vertexHead[26].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[26].color = color;
	vertexHead[26].tex = D3DXVECTOR2(1, 0);

	vertexHead[27].pos = D3DXVECTOR3(-headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[27].color = color;
	vertexHead[27].tex = D3DXVECTOR2(0, 1);
	vertexHead[28].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, headHalfZ);
	vertexHead[28].color = color;
	vertexHead[28].tex = D3DXVECTOR2(1, 0);
	vertexHead[29].pos = D3DXVECTOR3(headHalfX, headBottomY + headHeight, -headHalfZ);
	vertexHead[29].color = color;
	vertexHead[29].tex = D3DXVECTOR2(1, 1);

	//head down
	vertexHead[30].pos = D3DXVECTOR3(-headHalfX, headBottomY, -headHalfZ);
	vertexHead[30].color = color;
	vertexHead[30].tex = D3DXVECTOR2(0, 0);
	vertexHead[31].pos = D3DXVECTOR3(headHalfX, headBottomY, headHalfZ);
	vertexHead[31].color = color;
	vertexHead[31].tex = D3DXVECTOR2(1, 1);
	vertexHead[32].pos = D3DXVECTOR3(-headHalfX, headBottomY, headHalfZ);
	vertexHead[32].color = color;
	vertexHead[32].tex = D3DXVECTOR2(1, 0);

	vertexHead[33].pos = D3DXVECTOR3(-headHalfX, headBottomY, -headHalfZ);
	vertexHead[33].color = color;
	vertexHead[33].tex = D3DXVECTOR2(0, 0);
	vertexHead[34].pos = D3DXVECTOR3(headHalfX, headBottomY, -headHalfZ);
	vertexHead[34].color = color;
	vertexHead[34].tex = D3DXVECTOR2(0, 1);
	vertexHead[35].pos = D3DXVECTOR3(headHalfX, headBottomY, headHalfZ);
	vertexHead[35].color = color;
	vertexHead[35].tex = D3DXVECTOR2(1, 1);





	/****************************************************/
	//body front
	vertexBody[0].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[0].color = color;
	vertexBody[0].tex = D3DXVECTOR2(0, 1);
	vertexBody[1].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[1].color = color;
	vertexBody[1].tex = D3DXVECTOR2(1, 0);
	vertexBody[2].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[2].color = color;
	vertexBody[2].tex = D3DXVECTOR2(1, 1);

	vertexBody[3].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[3].color = color;
	vertexBody[3].tex = D3DXVECTOR2(0, 1);
	vertexBody[4].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[4].color = color;
	vertexBody[4].tex = D3DXVECTOR2(0, 0);
	vertexBody[5].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[5].color = color;
	vertexBody[5].tex = D3DXVECTOR2(1, 0);

	//body back
	vertexBody[6].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[6].color = color;
	vertexBody[6].tex = D3DXVECTOR2(0, 1);
	vertexBody[7].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[7].color = color;
	vertexBody[7].tex = D3DXVECTOR2(1, 0);
	vertexBody[8].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[8].color = color;
	vertexBody[8].tex = D3DXVECTOR2(1, 1);

	vertexBody[9].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[9].color = color;
	vertexBody[9].tex = D3DXVECTOR2(0, 1);
	vertexBody[10].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[10].color = color;
	vertexBody[10].tex = D3DXVECTOR2(0, 0);
	vertexBody[11].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[11].color = color;
	vertexBody[11].tex = D3DXVECTOR2(1, 0);

	//body left
	vertexBody[12].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[12].color = color;
	vertexBody[12].tex = D3DXVECTOR2(0, 1);
	vertexBody[13].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[13].color = color;
	vertexBody[13].tex = D3DXVECTOR2(1, 0);
	vertexBody[14].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[14].color = color;
	vertexBody[14].tex = D3DXVECTOR2(1, 1);

	vertexBody[15].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[15].color = color;
	vertexBody[15].tex = D3DXVECTOR2(0, 1);
	vertexBody[16].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[16].color = color;
	vertexBody[16].tex = D3DXVECTOR2(0, 0);
	vertexBody[17].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[17].color = color;
	vertexBody[17].tex = D3DXVECTOR2(1, 0);

	//body right
	vertexBody[18].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[18].color = color;
	vertexBody[18].tex = D3DXVECTOR2(0, 1);
	vertexBody[19].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[19].color = color;
	vertexBody[19].tex = D3DXVECTOR2(0, 0);
	vertexBody[20].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[20].color = color;
	vertexBody[20].tex = D3DXVECTOR2(1, 0);

	vertexBody[21].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[21].color = color;
	vertexBody[21].tex = D3DXVECTOR2(0, 1);
	vertexBody[22].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[22].color = color;
	vertexBody[22].tex = D3DXVECTOR2(1, 0);
	vertexBody[23].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[23].color = color;
	vertexBody[23].tex = D3DXVECTOR2(1, 1);

	//body up
	vertexBody[24].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[24].color = color;
	vertexBody[24].tex = D3DXVECTOR2(0, 1);
	vertexBody[25].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[25].color = color;
	vertexBody[25].tex = D3DXVECTOR2(0, 0);
	vertexBody[26].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[26].color = color;
	vertexBody[26].tex = D3DXVECTOR2(1, 0);

	vertexBody[27].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[27].color = color;
	vertexBody[27].tex = D3DXVECTOR2(0, 1);
	vertexBody[28].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, bodyHalfZ);
	vertexBody[28].color = color;
	vertexBody[28].tex = D3DXVECTOR2(1, 0);
	vertexBody[29].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY + bodyHeight, -bodyHalfZ);
	vertexBody[29].color = color;
	vertexBody[29].tex = D3DXVECTOR2(1, 1);

	//body down
	vertexBody[30].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[30].color = color;
	vertexBody[30].tex = D3DXVECTOR2(0, 0);
	vertexBody[31].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[31].color = color;
	vertexBody[31].tex = D3DXVECTOR2(1, 1);
	vertexBody[32].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[32].color = color;
	vertexBody[32].tex = D3DXVECTOR2(1, 0);

	vertexBody[33].pos = D3DXVECTOR3(-bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[33].color = color;
	vertexBody[33].tex = D3DXVECTOR2(0, 0);
	vertexBody[34].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, -bodyHalfZ);
	vertexBody[34].color = color;
	vertexBody[34].tex = D3DXVECTOR2(0, 1);
	vertexBody[35].pos = D3DXVECTOR3(bodyHalfX, bodyBottomY, bodyHalfZ);
	vertexBody[35].color = color;
	vertexBody[35].tex = D3DXVECTOR2(1, 1);





	/****************************************************/
	//left arm front
	vertexLeftArm[0].pos = D3DXVECTOR3(leftArmLeft, armBottomY, -armHalfZ);
	vertexLeftArm[0].color = color;
	vertexLeftArm[0].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[1].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[1].color = color;
	vertexLeftArm[1].tex = D3DXVECTOR2(1, 0);
	vertexLeftArm[2].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexLeftArm[2].color = color;
	vertexLeftArm[2].tex = D3DXVECTOR2(1, 1);

	vertexLeftArm[3].pos = D3DXVECTOR3(leftArmLeft, armBottomY, -armHalfZ);
	vertexLeftArm[3].color = color;
	vertexLeftArm[3].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[4].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[4].color = color;
	vertexLeftArm[4].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[5].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[5].color = color;
	vertexLeftArm[5].tex = D3DXVECTOR2(1, 0);

	//left arm back
	vertexLeftArm[6].pos = D3DXVECTOR3(leftArmLeft, armBottomY, armHalfZ);
	vertexLeftArm[6].color = color;
	vertexLeftArm[6].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[7].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[7].color = color;
	vertexLeftArm[7].tex = D3DXVECTOR2(1, 0);
	vertexLeftArm[8].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[8].color = color;
	vertexLeftArm[8].tex = D3DXVECTOR2(1, 1);

	vertexLeftArm[9].pos = D3DXVECTOR3(leftArmLeft, armBottomY, armHalfZ);
	vertexLeftArm[9].color = color;
	vertexLeftArm[9].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[10].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, armHalfZ);
	vertexLeftArm[10].color = color;
	vertexLeftArm[10].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[11].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[11].color = color;
	vertexLeftArm[11].tex = D3DXVECTOR2(1, 0);

	//left arm left
	vertexLeftArm[12].pos = D3DXVECTOR3(leftArmLeft, armBottomY, armHalfZ);
	vertexLeftArm[12].color = color;
	vertexLeftArm[12].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[13].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[13].color = color;
	vertexLeftArm[13].tex = D3DXVECTOR2(1, 0);
	vertexLeftArm[14].pos = D3DXVECTOR3(leftArmLeft, armBottomY, -armHalfZ);
	vertexLeftArm[14].color = color;
	vertexLeftArm[14].tex = D3DXVECTOR2(1, 1);

	vertexLeftArm[15].pos = D3DXVECTOR3(leftArmLeft, armBottomY, armHalfZ);
	vertexLeftArm[15].color = color;
	vertexLeftArm[15].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[16].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[16].color = color;
	vertexLeftArm[16].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[17].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[17].color = color;
	vertexLeftArm[17].tex = D3DXVECTOR2(1, 0);

	//left arm right
	vertexLeftArm[18].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexLeftArm[18].color = color;
	vertexLeftArm[18].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[19].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[19].color = color;
	vertexLeftArm[19].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[20].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[20].color = color;
	vertexLeftArm[20].tex = D3DXVECTOR2(1, 0);

	vertexLeftArm[21].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexLeftArm[21].color = color;
	vertexLeftArm[21].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[22].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[22].color = color;
	vertexLeftArm[22].tex = D3DXVECTOR2(1, 0);
	vertexLeftArm[23].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, armHalfZ);
	vertexLeftArm[23].color = color;
	vertexLeftArm[23].tex = D3DXVECTOR2(1, 1);

	//left arm up
	vertexLeftArm[24].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[24].color = color;
	vertexLeftArm[24].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[25].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[25].color = color;
	vertexLeftArm[25].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[26].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[26].color = color;
	vertexLeftArm[26].tex = D3DXVECTOR2(1, 0);

	vertexLeftArm[27].pos = D3DXVECTOR3(leftArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[27].color = color;
	vertexLeftArm[27].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[28].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexLeftArm[28].color = color;
	vertexLeftArm[28].tex = D3DXVECTOR2(1, 0);
	vertexLeftArm[29].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexLeftArm[29].color = color;
	vertexLeftArm[29].tex = D3DXVECTOR2(1, 1);

	//left arm down
	vertexLeftArm[30].pos = D3DXVECTOR3(leftArmLeft, armBottomY, -armHalfZ);
	vertexLeftArm[30].color = color;
	vertexLeftArm[30].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[31].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, armHalfZ);
	vertexLeftArm[31].color = color;
	vertexLeftArm[31].tex = D3DXVECTOR2(1, 1);
	vertexLeftArm[32].pos = D3DXVECTOR3(leftArmLeft, armBottomY, armHalfZ);
	vertexLeftArm[32].color = color;
	vertexLeftArm[32].tex = D3DXVECTOR2(1, 0);

	vertexLeftArm[33].pos = D3DXVECTOR3(leftArmLeft, armBottomY, -armHalfZ);
	vertexLeftArm[33].color = color;
	vertexLeftArm[33].tex = D3DXVECTOR2(0, 0);
	vertexLeftArm[34].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexLeftArm[34].color = color;
	vertexLeftArm[34].tex = D3DXVECTOR2(0, 1);
	vertexLeftArm[35].pos = D3DXVECTOR3(leftArmLeft + armWidth, armBottomY, armHalfZ);
	vertexLeftArm[35].color = color;
	vertexLeftArm[35].tex = D3DXVECTOR2(1, 1);




	/****************************************************/
	//right arm front
	vertexRightArm[0].pos = D3DXVECTOR3(rightArmLeft, armBottomY, -armHalfZ);
	vertexRightArm[0].color = color;
	vertexRightArm[0].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[1].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[1].color = color;
	vertexRightArm[1].tex = D3DXVECTOR2(1, 0);
	vertexRightArm[2].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexRightArm[2].color = color;
	vertexRightArm[2].tex = D3DXVECTOR2(1, 1);

	vertexRightArm[3].pos = D3DXVECTOR3(rightArmLeft, armBottomY, -armHalfZ);
	vertexRightArm[3].color = color;
	vertexRightArm[3].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[4].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[4].color = color;
	vertexRightArm[4].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[5].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[5].color = color;
	vertexRightArm[5].tex = D3DXVECTOR2(1, 0);

	//right arm back
	vertexRightArm[6].pos = D3DXVECTOR3(rightArmLeft, armBottomY, armHalfZ);
	vertexRightArm[6].color = color;
	vertexRightArm[6].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[7].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexRightArm[7].color = color;
	vertexRightArm[7].tex = D3DXVECTOR2(1, 0);
	vertexRightArm[8].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, armHalfZ);
	vertexRightArm[8].color = color;
	vertexRightArm[8].tex = D3DXVECTOR2(1, 1);

	vertexRightArm[9].pos = D3DXVECTOR3(rightArmLeft, armBottomY, armHalfZ);
	vertexRightArm[9].color = color;
	vertexRightArm[9].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[10].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, armHalfZ);
	vertexRightArm[10].color = color;
	vertexRightArm[10].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[11].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexRightArm[11].color = color;
	vertexRightArm[11].tex = D3DXVECTOR2(1, 0);

	//right arm left
	vertexRightArm[12].pos = D3DXVECTOR3(rightArmLeft, armBottomY, armHalfZ);
	vertexRightArm[12].color = color;
	vertexRightArm[12].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[13].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[13].color = color;
	vertexRightArm[13].tex = D3DXVECTOR2(1, 0);
	vertexRightArm[14].pos = D3DXVECTOR3(rightArmLeft, armBottomY, -armHalfZ);
	vertexRightArm[14].color = color;
	vertexRightArm[14].tex = D3DXVECTOR2(1, 1);

	vertexRightArm[15].pos = D3DXVECTOR3(rightArmLeft, armBottomY, armHalfZ);
	vertexRightArm[15].color = color;
	vertexRightArm[15].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[16].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, armHalfZ);
	vertexRightArm[16].color = color;
	vertexRightArm[16].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[17].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[17].color = color;
	vertexRightArm[17].tex = D3DXVECTOR2(1, 0);

	//right arm right
	vertexRightArm[18].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexRightArm[18].color = color;
	vertexRightArm[18].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[19].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[19].color = color;
	vertexRightArm[19].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[20].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexRightArm[20].color = color;
	vertexRightArm[20].tex = D3DXVECTOR2(1, 0);

	vertexRightArm[21].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexRightArm[21].color = color;
	vertexRightArm[21].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[22].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexRightArm[22].color = color;
	vertexRightArm[22].tex = D3DXVECTOR2(1, 0);
	vertexRightArm[23].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, armHalfZ);
	vertexRightArm[23].color = color;
	vertexRightArm[23].tex = D3DXVECTOR2(1, 1);

	//right arm up
	vertexRightArm[24].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[24].color = color;
	vertexRightArm[24].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[25].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, armHalfZ);
	vertexRightArm[25].color = color;
	vertexRightArm[25].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[26].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexRightArm[26].color = color;
	vertexRightArm[26].tex = D3DXVECTOR2(1, 0);

	vertexRightArm[27].pos = D3DXVECTOR3(rightArmLeft, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[27].color = color;
	vertexRightArm[27].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[28].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, armHalfZ);
	vertexRightArm[28].color = color;
	vertexRightArm[28].tex = D3DXVECTOR2(1, 0);
	vertexRightArm[29].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY + armHeight, -armHalfZ);
	vertexRightArm[29].color = color;
	vertexRightArm[29].tex = D3DXVECTOR2(1, 1);

	//right arm down
	vertexRightArm[30].pos = D3DXVECTOR3(rightArmLeft, armBottomY, -armHalfZ);
	vertexRightArm[30].color = color;
	vertexRightArm[30].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[31].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, armHalfZ);
	vertexRightArm[31].color = color;
	vertexRightArm[31].tex = D3DXVECTOR2(1, 1);
	vertexRightArm[32].pos = D3DXVECTOR3(rightArmLeft, armBottomY, armHalfZ);
	vertexRightArm[32].color = color;
	vertexRightArm[32].tex = D3DXVECTOR2(1, 0);

	vertexRightArm[33].pos = D3DXVECTOR3(rightArmLeft, armBottomY, -armHalfZ);
	vertexRightArm[33].color = color;
	vertexRightArm[33].tex = D3DXVECTOR2(0, 0);
	vertexRightArm[34].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, -armHalfZ);
	vertexRightArm[34].color = color;
	vertexRightArm[34].tex = D3DXVECTOR2(0, 1);
	vertexRightArm[35].pos = D3DXVECTOR3(rightArmLeft + armWidth, armBottomY, armHalfZ);
	vertexRightArm[35].color = color;
	vertexRightArm[35].tex = D3DXVECTOR2(1, 1);




	/****************************************************/
	//left leg front
	vertexLeftLeg[0].pos = D3DXVECTOR3(leftLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[0].color = color;
	vertexLeftLeg[0].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[1].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[1].color = color;
	vertexLeftLeg[1].tex = D3DXVECTOR2(1, 0);
	vertexLeftLeg[2].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexLeftLeg[2].color = color;
	vertexLeftLeg[2].tex = D3DXVECTOR2(1, 1);

	vertexLeftLeg[3].pos = D3DXVECTOR3(leftLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[3].color = color;
	vertexLeftLeg[3].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[4].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[4].color = color;
	vertexLeftLeg[4].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[5].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[5].color = color;
	vertexLeftLeg[5].tex = D3DXVECTOR2(1, 0);

	//left leg back
	vertexLeftLeg[6].pos = D3DXVECTOR3(leftLegLeft, legBottomY, legHalfZ);
	vertexLeftLeg[6].color = color;
	vertexLeftLeg[6].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[7].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[7].color = color;
	vertexLeftLeg[7].tex = D3DXVECTOR2(1, 0);
	vertexLeftLeg[8].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[8].color = color;
	vertexLeftLeg[8].tex = D3DXVECTOR2(1, 1);

	vertexLeftLeg[9].pos = D3DXVECTOR3(leftLegLeft, legBottomY, legHalfZ);
	vertexLeftLeg[9].color = color;
	vertexLeftLeg[9].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[10].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, legHalfZ);
	vertexLeftLeg[10].color = color;
	vertexLeftLeg[10].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[11].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[11].color = color;
	vertexLeftLeg[11].tex = D3DXVECTOR2(1, 0);

	//left leg left
	vertexLeftLeg[12].pos = D3DXVECTOR3(leftLegLeft, legBottomY, legHalfZ);
	vertexLeftLeg[12].color = color;
	vertexLeftLeg[12].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[13].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[13].color = color;
	vertexLeftLeg[13].tex = D3DXVECTOR2(1, 0);
	vertexLeftLeg[14].pos = D3DXVECTOR3(leftLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[14].color = color;
	vertexLeftLeg[14].tex = D3DXVECTOR2(1, 1);

	vertexLeftLeg[15].pos = D3DXVECTOR3(leftLegLeft, legBottomY, legHalfZ);
	vertexLeftLeg[15].color = color;
	vertexLeftLeg[15].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[16].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[16].color = color;
	vertexLeftLeg[16].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[17].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[17].color = color;
	vertexLeftLeg[17].tex = D3DXVECTOR2(1, 0);

	//left leg right
	vertexLeftLeg[18].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexLeftLeg[18].color = color;
	vertexLeftLeg[18].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[19].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[19].color = color;
	vertexLeftLeg[19].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[20].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[20].color = color;
	vertexLeftLeg[20].tex = D3DXVECTOR2(1, 0);

	vertexLeftLeg[21].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexLeftLeg[21].color = color;
	vertexLeftLeg[21].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[22].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[22].color = color;
	vertexLeftLeg[22].tex = D3DXVECTOR2(1, 0);
	vertexLeftLeg[23].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, legHalfZ);
	vertexLeftLeg[23].color = color;
	vertexLeftLeg[23].tex = D3DXVECTOR2(1, 1);

	//left leg up
	vertexLeftLeg[24].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[24].color = color;
	vertexLeftLeg[24].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[25].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[25].color = color;
	vertexLeftLeg[25].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[26].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[26].color = color;
	vertexLeftLeg[26].tex = D3DXVECTOR2(1, 0);

	vertexLeftLeg[27].pos = D3DXVECTOR3(leftLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[27].color = color;
	vertexLeftLeg[27].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[28].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexLeftLeg[28].color = color;
	vertexLeftLeg[28].tex = D3DXVECTOR2(1, 0);
	vertexLeftLeg[29].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexLeftLeg[29].color = color;
	vertexLeftLeg[29].tex = D3DXVECTOR2(1, 1);

	//left leg down
	vertexLeftLeg[30].pos = D3DXVECTOR3(leftLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[30].color = color;
	vertexLeftLeg[30].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[31].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, legHalfZ);
	vertexLeftLeg[31].color = color;
	vertexLeftLeg[31].tex = D3DXVECTOR2(1, 1);
	vertexLeftLeg[32].pos = D3DXVECTOR3(leftLegLeft, legBottomY, legHalfZ);
	vertexLeftLeg[32].color = color;
	vertexLeftLeg[32].tex = D3DXVECTOR2(1, 0);

	vertexLeftLeg[33].pos = D3DXVECTOR3(leftLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[33].color = color;
	vertexLeftLeg[33].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[34].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexLeftLeg[34].color = color;
	vertexLeftLeg[34].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[35].pos = D3DXVECTOR3(leftLegLeft + legWidth, legBottomY, legHalfZ);
	vertexLeftLeg[35].color = color;
	vertexLeftLeg[35].tex = D3DXVECTOR2(1, 1);





	/****************************************************/
	//right leg front
	vertexRightLeg[0].pos = D3DXVECTOR3(rightLegLeft, legBottomY, -legHalfZ);
	vertexRightLeg[0].color = color;
	vertexRightLeg[0].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[1].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[1].color = color;
	vertexRightLeg[1].tex = D3DXVECTOR2(1, 0);
	vertexRightLeg[2].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexRightLeg[2].color = color;
	vertexRightLeg[2].tex = D3DXVECTOR2(1, 1);

	vertexRightLeg[3].pos = D3DXVECTOR3(rightLegLeft, legBottomY, -legHalfZ);
	vertexRightLeg[3].color = color;
	vertexRightLeg[3].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[4].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[4].color = color;
	vertexRightLeg[4].tex = D3DXVECTOR2(0, 0);
	vertexRightLeg[5].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[5].color = color;
	vertexRightLeg[5].tex = D3DXVECTOR2(1, 0);

	//right leg back
	vertexRightLeg[6].pos = D3DXVECTOR3(rightLegLeft, legBottomY, legHalfZ);
	vertexRightLeg[6].color = color;
	vertexRightLeg[6].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[7].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[7].color = color;
	vertexRightLeg[7].tex = D3DXVECTOR2(1, 0);
	vertexRightLeg[8].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[8].color = color;
	vertexRightLeg[8].tex = D3DXVECTOR2(1, 1);

	vertexRightLeg[9].pos = D3DXVECTOR3(rightLegLeft, legBottomY, legHalfZ);
	vertexRightLeg[9].color = color;
	vertexRightLeg[9].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[10].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, legHalfZ);
	vertexRightLeg[10].color = color;
	vertexRightLeg[10].tex = D3DXVECTOR2(0, 0);
	vertexRightLeg[11].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[11].color = color;
	vertexRightLeg[11].tex = D3DXVECTOR2(1, 0);

	//right leg left
	vertexRightLeg[12].pos = D3DXVECTOR3(rightLegLeft, legBottomY, legHalfZ);
	vertexRightLeg[12].color = color;
	vertexRightLeg[12].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[13].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[13].color = color;
	vertexRightLeg[13].tex = D3DXVECTOR2(1, 0);
	vertexRightLeg[14].pos = D3DXVECTOR3(rightLegLeft, legBottomY, -legHalfZ);
	vertexRightLeg[14].color = color;
	vertexRightLeg[14].tex = D3DXVECTOR2(1, 1);

	vertexRightLeg[15].pos = D3DXVECTOR3(rightLegLeft, legBottomY, legHalfZ);
	vertexRightLeg[15].color = color;
	vertexRightLeg[15].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[16].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[16].color = color;
	vertexRightLeg[16].tex = D3DXVECTOR2(0, 0);
	vertexRightLeg[17].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[17].color = color;
	vertexRightLeg[17].tex = D3DXVECTOR2(1, 0);

	//right leg right
	vertexRightLeg[18].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexRightLeg[18].color = color;
	vertexRightLeg[18].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[19].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[19].color = color;
	vertexRightLeg[19].tex = D3DXVECTOR2(0, 0);
	vertexRightLeg[20].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[20].color = color;
	vertexRightLeg[20].tex = D3DXVECTOR2(1, 0);

	vertexRightLeg[21].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexRightLeg[21].color = color;
	vertexRightLeg[21].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[22].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[22].color = color;
	vertexRightLeg[22].tex = D3DXVECTOR2(1, 0);
	vertexRightLeg[23].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, legHalfZ);
	vertexRightLeg[23].color = color;
	vertexRightLeg[23].tex = D3DXVECTOR2(1, 1);

	//right leg up
	vertexRightLeg[24].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[24].color = color;
	vertexRightLeg[24].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[25].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[25].color = color;
	vertexRightLeg[25].tex = D3DXVECTOR2(0, 0);
	vertexRightLeg[26].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[26].color = color;
	vertexRightLeg[26].tex = D3DXVECTOR2(1, 0);

	vertexRightLeg[27].pos = D3DXVECTOR3(rightLegLeft, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[27].color = color;
	vertexRightLeg[27].tex = D3DXVECTOR2(0, 1);
	vertexRightLeg[28].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, legHalfZ);
	vertexRightLeg[28].color = color;
	vertexRightLeg[28].tex = D3DXVECTOR2(1, 0);
	vertexRightLeg[29].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY + legHeight, -legHalfZ);
	vertexRightLeg[29].color = color;
	vertexRightLeg[29].tex = D3DXVECTOR2(1, 1);

	//right leg down
	vertexRightLeg[30].pos = D3DXVECTOR3(rightLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[30].color = color;
	vertexLeftLeg[30].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[31].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, legHalfZ);
	vertexLeftLeg[31].color = color;
	vertexLeftLeg[31].tex = D3DXVECTOR2(1, 1);
	vertexLeftLeg[32].pos = D3DXVECTOR3(rightLegLeft, legBottomY, legHalfZ);
	vertexLeftLeg[32].color = color;
	vertexLeftLeg[32].tex = D3DXVECTOR2(1, 0);

	vertexLeftLeg[33].pos = D3DXVECTOR3(rightLegLeft, legBottomY, -legHalfZ);
	vertexLeftLeg[33].color = color;
	vertexLeftLeg[33].tex = D3DXVECTOR2(0, 0);
	vertexLeftLeg[34].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, -legHalfZ);
	vertexLeftLeg[34].color = color;
	vertexLeftLeg[34].tex = D3DXVECTOR2(0, 1);
	vertexLeftLeg[35].pos = D3DXVECTOR3(rightLegLeft + legWidth, legBottomY, legHalfZ);
	vertexLeftLeg[35].color = color;
	vertexLeftLeg[35].tex = D3DXVECTOR2(1, 1);
}

void CubeRobot::Destroy()
{
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);
	SAFE_RELEASE(texture);
}

void CubeRobot::Render(const D3DXMATRIXA16& view, const D3DXMATRIXA16& projection)
{
	GameManager::GetDevice()->SetTransform(D3DTS_VIEW, &view);
	GameManager::GetDevice()->SetTransform(D3DTS_PROJECTION, &projection);
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetFVF(FVF_PositionColorTexture::FVF);

	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexHead,
		sizeof(FVF_PositionColorTexture)
		);

	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexBody,
		sizeof(FVF_PositionColorTexture)
		);

	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexLeftArm,
		sizeof(FVF_PositionColorTexture)
		);

	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexRightArm,
		sizeof(FVF_PositionColorTexture)
		);

	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexLeftLeg,
		sizeof(FVF_PositionColorTexture)
		);

	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		12,
		vertexRightLeg,
		sizeof(FVF_PositionColorTexture)
		);
}

void CubeRobot::Update()
{
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		position += direction * 0.3f;
	}

	if (KEYMANAGER->isStayKeyDown('S'))
	{
		position -= direction * 0.3f;
	}

	//if (KEYMANAGER->isStayKeyDown('Q'))
	//{
	//	xRadian -= 0.05f;
	//}

	//if (KEYMANAGER->isStayKeyDown('E'))
	//{
	//	xRadian += 0.05f;
	//}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		yRadian -= 0.035f;
	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		yRadian += 0.035f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		hasRobotJumped = true;
	}

	if (hasRobotJumped)
	{
		position.y += jumpSpeed - gravity;
		gravity += 0.01f;

		if (position.y < 0)
		{
			position.y = 0;
			gravity = 0.0f;
			hasRobotJumped = false;
		}
	}

	D3DXMatrixIdentity(&world);

	D3DXMatrixScaling(&scale, 0.3f, 0.3f, 0.3f);
	world *= scale;

	D3DXMatrixRotationX(&rotX, xRadian);
	D3DXMatrixRotationY(&rotY, yRadian);
	D3DXMatrixRotationZ(&rotZ, zRadian);
	world *= rotX * rotY * rotZ;

	D3DXVec3TransformCoord(&direction, &D3DXVECTOR3(0, 0, 1), &world);

	D3DXMatrixTranslation(&trans, position.x, position.y, position.z);
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