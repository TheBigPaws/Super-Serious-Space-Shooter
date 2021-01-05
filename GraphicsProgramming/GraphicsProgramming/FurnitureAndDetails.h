#pragma once
#include "ModelsLoader.h"
#include <math.h>
class FurnitureAndDetails
{
private:
	ModelsLoader rock;
	ModelsLoader tree;
	ModelsLoader log;
	ModelsLoader armchair;
	ModelsLoader boat;
	GLuint TreeTexture;
	GLuint imposterShadow;
public:
	FurnitureAndDetails();
	void generateTree(float x, float y, float z, Vector3 CameraPosition);
	void renderAll(Vector3 CameraPosition, bool displayAll);
	void renderOutside(bool displayAll);
	void renderLog();
};

