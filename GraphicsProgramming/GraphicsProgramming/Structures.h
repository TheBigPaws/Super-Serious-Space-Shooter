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

public:
	Structures();
	void generateStructures();
};

