#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include "Vector3.h"
#include <math.h>
class Door
{
private:
	bool Open = false;
	float rotation = 0.0;
	GLuint doortext;
public:
	Door();
	void incrementDT(float dt);
	void renderDoor();
	void switchOpen();

};

