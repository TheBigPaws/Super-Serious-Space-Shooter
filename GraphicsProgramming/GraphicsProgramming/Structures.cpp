#include "Structures.h"

Structures::Structures() {
	stoneTexture = SOIL_load_OGL_texture(
		"gfx/stone.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	snowTexture = SOIL_load_OGL_texture(
		"gfx/Snow_ground.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	woodenFloorTexture = SOIL_load_OGL_texture(
		"gfx/woodenFloor.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	LogWallTexture = SOIL_load_OGL_texture(
		"gfx/LogWall.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	DoorTexture = SOIL_load_OGL_texture(
		"gfx/door.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	roofTexture = SOIL_load_OGL_texture(
		"gfx/snowroof.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	darkwoodTexture = SOIL_load_OGL_texture(
		"gfx/wooddark.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	lightwoodTexture = SOIL_load_OGL_texture(
		"gfx/woodlight.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	brickWall = SOIL_load_OGL_texture(
		"gfx/brickwall.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}



void Structures::generateStructures() {


	//SNOW GROUND -------------------------------------------------------------------
	
	BuildingFunctions::makeTextRect(Vector3(-20.0f, 0.0f, -20.0f), Vector3(-20.0f, 0.0f, 20.0f), Vector3(20.0f, 0.0f, 20.0f), Vector3(20.0f, 0.0f, -20.0f), Vector3(0.0f, 1.0f, 0.0f), 10.0f, 10.0f, snowTexture);

	//COTTAGE FLOOR, STONE FOUNDATION & STAIRS  -------------------------------------------------------------------
	glColor3f(0.7f, 0.8f, 0.8f);
	BuildingFunctions::makeBlock(0, 0.49, 2, 10, 0.98, 14, 3, stoneTexture);
	BuildingFunctions::makeBlock(0, 0.25, 9.25, 2, 0.5, 0.5, 3, stoneTexture);
	glColor3f(0.7f, 0.6f, 0.6f); //slightly edit colour for more realism
	BuildingFunctions::makeBlock(0, 0.99, 2, 10, 0.02, 14, 2, woodenFloorTexture);

	glColor3f(1.0f, 1.0f, 1.0f);
	
	//WALLS -------------------------------------------------------------------
	//back wall
	BuildingFunctions::makeBlock(0, 4, -4.8, 9.2, 6, 0.4, 4, LogWallTexture);

	//right wall
	BuildingFunctions::makeBlock(4.8, 2, 0, 0.4, 2, 10, 4, LogWallTexture);
	BuildingFunctions::makeBlock(4.8, 6.25, 0, 0.4, 1.5, 10, 4, LogWallTexture);
	BuildingFunctions::makeBlock(4.8, 4.25, -3.125, 0.4, 2.5, 3.75, 4, LogWallTexture);
	BuildingFunctions::makeBlock(4.8, 4.25, 3.125, 0.4, 2.5, 3.75, 4, LogWallTexture);

	//left wall
	BuildingFunctions::makeBlock(-4.8, 2, 0, 0.4, 2, 10, 4, LogWallTexture);
	BuildingFunctions::makeBlock(-4.8, 6.25, 0, 0.4, 1.5, 10, 4, LogWallTexture);
	BuildingFunctions::makeBlock(-4.8, 4.25, -3.125, 0.4, 2.5, 3.75, 4, LogWallTexture);
	BuildingFunctions::makeBlock(-4.8, 4.25, 3.125, 0.4, 2.5, 3.75, 4, LogWallTexture);

	//front wall
	BuildingFunctions::makeBlock(0, 6.0, 4.8, 9.2, 2.0, 0.4, 4, LogWallTexture);
	BuildingFunctions::makeBlock(-2.8, 3.0, 4.8, 3.6, 4.0, 0.4, 4, LogWallTexture);
	BuildingFunctions::makeBlock(2.8, 3.0, 4.8, 3.6, 4.0, 0.4, 4, LogWallTexture);
	
	//DOORTEMP
	glPushMatrix();
	//open
	//glTranslatef(1.5, 0.0, 5.8);
	//glRotatef(-45.0f,0.0f,1.0f,0.0f);

	//creaked
	glTranslatef(0.0, 0.0, 5.2);
	glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
	BuildingFunctions::makeBlock(0, 3.0, 0.0, 2.0, 4.0, 0.2, 4, DoorTexture);
	glPopMatrix();
	
	//PORCH COLLUMS & RAILINGS
	glColor3f(0.5f, 0.4f, 0.4f);

	BuildingFunctions::makeBlock(4.79, 3.5, 8.79, 0.4, 5.4, 0.4, 2, lightwoodTexture);
	BuildingFunctions::makeBlock(-4.79, 3.5, 8.79, 0.4, 5.4, 0.4, 2, lightwoodTexture);

	BuildingFunctions::makeBlock(4.8, 2.0, 7.0, 0.2, 2.0, 0.2, 2, lightwoodTexture);
	BuildingFunctions::makeBlock(-4.8, 2.0, 7.0, 0.2, 2.0, 0.2, 2, lightwoodTexture);

	BuildingFunctions::makeBlock(1.10, 2.0, 8.8, 0.2, 2.0, 0.2, 2, lightwoodTexture);
	BuildingFunctions::makeBlock(-1.10, 2.0, 8.8, 0.2, 2.0, 0.2, 2, lightwoodTexture);

	BuildingFunctions::makeBlock(3.10, 2.0, 8.8, 0.2, 2.0, 0.2, 2, lightwoodTexture);
	BuildingFunctions::makeBlock(-3.10, 2.0, 8.8, 0.2, 2.0, 0.2, 2, lightwoodTexture);

	BuildingFunctions::makeBlock(4.8, 3.05, 6.8, 0.2, 0.1, 3.6, 2, lightwoodTexture);
	BuildingFunctions::makeBlock(-4.8, 3.05, 6.8, 0.2, 0.1, 3.6, 2, lightwoodTexture);

	BuildingFunctions::makeBlock(3.0, 3.05, 8.8, 4.0, 0.1, 0.2, 2, lightwoodTexture);
	BuildingFunctions::makeBlock(-3.0, 3.05, 8.8, 4.0, 0.1, 0.2, 2, lightwoodTexture);

	glColor3f(1.0f, 1.0f, 1.0f);

	//ROOF -------------------------------------------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	//roof, shields and overhang
	glPushMatrix();
	glTranslatef(0, 8.55, 2.5);
	glRotatef(33.0, 1.0, 0.0, 0.0);
	BuildingFunctions::makeBlock(0.0, 0.0, 0.0, 12, 0.2, 6.1, 5, roofTexture); //roof front
	BuildingFunctions::makeTextRect(Vector3(-6.005, -0.101, -3.05), Vector3(-6.005, -0.101, 3.05), Vector3(6.005, -0.101, 3.05), Vector3(6.005, -0.101, -3.05), Vector3(0.0, -1.0, 0.0), 4.8, 2, darkwoodTexture);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 8.2, -3.1);
	glRotatef(-33.0, 1.0, 0.0, 0.0);
	BuildingFunctions::makeBlock(0.0, 0.0, 0.0, 12.01, 0.2, 7.5, 5, roofTexture); //roof back
	BuildingFunctions::makeTextRect(Vector3(-6.005, -0.101, -3.75), Vector3(-6.005, -0.101, 3.75), Vector3(6.005, -0.101, 3.75), Vector3(6.005, -0.101, -3.75), Vector3(0.0, -1.0, 0.0), 7.2, 3, darkwoodTexture);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 6.5, 7.3);
	glRotatef(10.0, 1.0, 0.0, 0.0);
	BuildingFunctions::makeBlock(0.0, 0.0, 0.0, 12.01, 0.2, 5.0, 5, roofTexture); //roof front overhang
	BuildingFunctions::makeTextRect(Vector3(-6.005, -0.101, -2.5), Vector3(-6.005, -0.101, 2.5), Vector3(6.005, -0.101, 2.5), Vector3(6.005, -0.101, -2.5), Vector3(0.0, -1.0, 0.0), 4.8, 2, darkwoodTexture);
	glPopMatrix();

	BuildingFunctions::makeTextTria(Vector3(-4.6, 10.2, 0.0), Vector3(-4.6, 7.0, -4.9), Vector3(-4.6, 7.0, 4.9), Vector3(1.0, 0.0, 0.0), Vector3(0.5, 0.0, 0.0), Vector3(-1.0, 0.75, 0.0), Vector3(1.5, 0.75, 0.0), LogWallTexture);
	BuildingFunctions::makeTextTria(Vector3(-5, 10.2, 0.0), Vector3(-5, 7.0, -4.9), Vector3(-5, 7.0, 4.9), Vector3(-1.0, 0.0, 0.0), Vector3(0.5, 0.0, 0.0), Vector3(-1.0, 0.75, 0.0), Vector3(1.5, 0.75, 0.0), LogWallTexture);

	BuildingFunctions::makeTextTria(Vector3(5, 10.2, 0.0), Vector3(5, 7.0, -4.9), Vector3(5, 7.0, 4.9), Vector3(1.0, 0.0, 0.0), Vector3(0.5, 0.0, 0.0), Vector3(-1.0, 0.75, 0.0), Vector3(1.5, 0.75, 0.0), LogWallTexture);
	BuildingFunctions::makeTextTria(Vector3(4.6, 10.2, 0.0), Vector3(4.6, 7.0, -4.9), Vector3(4.6, 7.0, 4.9), Vector3(-1.0, 0.0, 0.0), Vector3(0.5, 0.0, 0.0), Vector3(-1.0, 0.75, 0.0), Vector3(1.5, 0.75, 0.0), LogWallTexture);
	
	//FIREPLACE & CHIMNEY
	BuildingFunctions::makeBlock(0.0, 7.0, -4.2, 0.8, 6, 0.8, 3, brickWall);
	BuildingFunctions::makeBlock(0.0, 1.25, -3.6, 3.0, 0.5, 2.0, 3, brickWall);
	BuildingFunctions::makeBlock(0.0, 3.75, -3.85, 3.0, 0.5, 1.5, 3, brickWall);
	BuildingFunctions::makeBlock(1.25, 2.5, -3.85, 0.5, 2.0, 1.5, 3, brickWall);
	BuildingFunctions::makeBlock(-1.25, 2.5, -3.85, 0.5, 2.0, 1.5, 3, brickWall);
	BuildingFunctions::makeBlock(0.0, 2.5, -4.5, 2.0, 2.0, 0.2, 3, brickWall);

	//windows -------------------------------------------------------------------
	BuildingFunctions::makeBlock(4.8, 4.25, 0.0, 0.1, 2.5, 0.1, 4, LogWallTexture);
	BuildingFunctions::makeBlock(4.8, 4.25, 0.0, 0.09, 0.1, 2.5, 4, LogWallTexture);

	BuildingFunctions::makeBlock(-4.8, 4.25, 0.0, 0.1, 2.5, 0.1, 4, LogWallTexture);
	BuildingFunctions::makeBlock(-4.8, 4.25, 0.0, 0.09, 0.1, 2.5, 4, LogWallTexture);

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glColor4f(0.8, 0.8, 1.0, 0.35);

	glBegin(GL_QUADS);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(4.8, 5.5, 1.25);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(4.8, 3, 1.25);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(4.8, 3, -1.25);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(4.8, 5.5, -1.25);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-4.8, 5.5, 1.25);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-4.8, 3, 1.25);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-4.8, 3, -1.25);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-4.8, 5.5, -1.25);

	glEnd();

	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	
}