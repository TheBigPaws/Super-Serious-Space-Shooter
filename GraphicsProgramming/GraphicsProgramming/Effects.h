#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include "Vector3.h"

class Effects
{
private:
	GLuint FireSpriteSheet;
	float X_SSH, Y_SSH;
	float timePassed;
public:
	Effects();
	void incrementTime(float dt);
	void renderFire();
};

