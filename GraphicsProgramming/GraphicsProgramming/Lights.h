#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "time.h"
// Further includes should go here:
#include "SOIL.h"
#include "Vector3.h"
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <fstream>
class Lights
{
private:
	GLfloat goalFire = 0.1;
	GLfloat strengthOfFire = 0.1;
	GLfloat aLight_Diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat aLight_Position[4] = { -1.0f, 1.0f, 0.3f, 0.0f };
	GLfloat aLight_Ambient[4] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat Light_Diffuse[4] = { 1.0f, 0.6f, 0.0f, 1.0f };
	GLfloat Light_Position[4] = { 0.0f, 2.5f, -3.85f, 1.0f };
public:
	void renderLights();
	void calculate(float dt);
};

