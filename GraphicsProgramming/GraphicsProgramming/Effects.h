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
	float X_SSH, Y_SSH;
	float timePassed;
	float spawnNewSmoke;
	std::vector <smokeParticle> SmokeParts;
public:
	Effects();
	void incrementTime(float dt);
	void renderFire();
	void renderSmoke(Vector3 CameraPosition);
	void renderEffects(Vector3 CameraPosition);
};

