#pragma once

#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
class Skybox
{
private:
	GLuint skyboxTexture;
	int banana;
	bool outsidelight = true;
	//GLfloat Light_Diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//GLfloat Light_Position[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat Light_Ambient[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
public:
	Skybox();
	void RenderSBOX(GLfloat x, GLfloat y, GLfloat z);
	void changeOutsideLight();
};

