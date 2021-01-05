#pragma once

#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <vector>
#include "Vector3.h"
#include "Structures.h"
#include "FurnitureAndDetails.h"
class Shadow
{
	//custom variables:
	private:
		Structures Structures;
		//variables for the static shadow
		FurnitureAndDetails FurnitureAndDetails;
		GLfloat OutsideLight_Position[4] = { -100.0f, 100.0f, 70.0f, 0.0f };
		GLfloat planeverts[12] = { -20.0, 0.0, -20.0,
							 -20.0, 0.0, 20.0,
							  20.0, 0.0, 20.0,
							  20.0, 0.0, -20.0 };
		float  shadowMatrix[16];
	public:
		Shadow();
		static void generateShadowMatrix(float* shadowMatrix, float light_pos[4], GLfloat floor[12]);
		static void extendVertex(float newVert[3], float lightPosit[4], float x, float y, float z, float ext);
		static std::vector<float> buildShadowVolume(float lightPosit[4], std::vector<float> verts);

		//custom function:
		void generateOutsideShadows(bool displayAll);
};