#pragma once


#include "BuildingFunctions.h"
class Structures
{ 
private:
	GLuint stoneTexture;
	GLuint snowTexture;
	GLuint woodenFloorTexture;
	GLuint LogWallTexture;
	GLuint DoorTexture;
	GLuint roofTexture;
	GLuint darkwoodTexture;
	GLuint lightwoodTexture;
	GLuint brickWall;
	GLfloat wondowsAmbAndDIff[4] = { 0.8, 0.8, 1.0, 0.35 };
	GLfloat specularMat[4] = { 1.0, 1.0, 1.0, 1.0 };
public:
	Structures();
	void generateStructures(int shadower);
	void generateWindow();
};

