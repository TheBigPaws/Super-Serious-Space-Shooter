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
public:
	Skybox();
	void RenderSBOX(GLfloat x, GLfloat y, GLfloat z);
};

