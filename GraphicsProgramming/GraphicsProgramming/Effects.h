#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include "Vector3.h"
#include <stdlib.h>
#include <vector>
#include <math.h>
class smokeParticle {
public:
	Vector3 direction, position;
	float sizeX, sizeY, transparency;
	smokeParticle();
};

class Effects
{
private:
	GLuint FireSpriteSheet;
	float fire_X_SSH, fire_Y_SSH;
	float nextFireFrame;
	float spawnNewSmoke;
	std::vector <smokeParticle> SmokeParts;
	GLfloat fireGlowOn[4]{ 1.0f,1.0f,0.0f,1.0, };
	GLfloat fireGlowOff[4]{ 0.0f,0.0f,0.0f,1.0, };
public:
	Effects();
	void incrementTime(float dt);
	void renderFire();
	void renderSmoke(Vector3 CameraPosition);
	void renderEffects(Vector3 CameraPosition);
};

