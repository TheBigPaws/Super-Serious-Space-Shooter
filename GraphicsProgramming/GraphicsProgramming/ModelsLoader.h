#pragma once

#ifndef _MODEL_H_
#define _MODEL_H_

// INCLUDES //
#include <glut.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>

using namespace std;

// MY CLASS INCLUDES //
#include <vector>
#include "Vector3.h"
#include "SOIL.h"
class ModelsLoader
{
public:

	bool load(char* modelFilename, char* textureFilename);
	void render();

private:

	void loadTexture(char*);
	bool loadModel(char*);

	// model texture
	GLuint texture;

	// Stoagre for sorted data
	vector<float> vertex, normals, texCoords;
};

#endif