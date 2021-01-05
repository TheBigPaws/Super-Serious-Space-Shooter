#include "FurnitureAndDetails.h"

FurnitureAndDetails::FurnitureAndDetails() {
	rock.load("models/Rock.obj", "gfx/StoneObjText.png");
	tree.load("models/OakTree.obj", "gfx/TreeTexture.png");
	log.load("models/WoodenLog.obj", "gfx/texture_log.png");
	armchair.load("models/chair.obj", "gfx/chair_DIFF.png");
	boat.load("models/veliero.obj", "gfx/shipTexture.png");
	TreeTexture = SOIL_load_OGL_texture(
		"gfx/Tree.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	imposterShadow = SOIL_load_OGL_texture(
		"gfx/imposter.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}


void FurnitureAndDetails::generateTree(float x, float y, float z, Vector3 CameraPosition) {



	glEnable(GL_BLEND);

	glPushMatrix();

	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, imposterShadow);

	glBegin(GL_QUADS);//SHADOW

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-2.0, 0.01, -2.0);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-2.0, 0.01, 2.0);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(2.0, 0.01, 2.0);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(2.0, 0.01, -2.0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, TreeTexture);
	glRotatef(atan((CameraPosition.x - x) / (CameraPosition.z - z)) * 57.3, 0.0, 1.0, 0.0);

	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-5.0,15.0, 0.0);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-5.0, 0.0, 0.0);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(5.0, 0.0, 0.0);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(5.0, 15.0, 0.0);

	glEnd();

	glPopMatrix();
	glDisable(GL_BLEND);
}

void FurnitureAndDetails::renderAll(Vector3 CameraPosition, bool displayAll) {

	if (displayAll) {
		glPushMatrix();

		glTranslatef(6.0, 0.3, 15.0);
		rock.render();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(-13.0, -0.5, -12.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		//glRotatef(-90.0, 0.0, 0.0, 1.0);
		glScalef(0.4f, 0.4f, 0.4f);
		tree.render();

		glPopMatrix();


		glPushMatrix();

		glTranslatef(-2.0, 1.0, 1.0);
		glRotatef(150.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.3);
		armchair.render();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.0, 5.15, 8.8);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(0.25, 0.25, 0.25);
		boat.render();

		glPopMatrix();

	}
	generateTree(8, 0, -27.0, CameraPosition);
	generateTree(-10, 0, -31.0, CameraPosition);
	generateTree(7, 0, -20.0, CameraPosition);
	generateTree(0, 0, -13.0, CameraPosition);
	generateTree(13, 0, -8.0, CameraPosition);
	generateTree(-14, 0, 0, CameraPosition);
	generateTree(11, 0, 13, CameraPosition);
	generateTree(-12, 0, 13, CameraPosition);
}

void FurnitureAndDetails::renderOutside(bool displayAll) {

	if (displayAll) {

		glPushMatrix();

		glTranslatef(6.0, 0.0, 15.0);
		rock.render();

		glPopMatrix();

		glPushMatrix();

		glTranslatef(-13.0, -0.5, -12.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		//glRotatef(-90.0, 0.0, 0.0, 1.0);
		glScalef(0.4f, 0.4f, 0.4f);
		tree.render();

		glPopMatrix();
	}
}

void FurnitureAndDetails::renderLog() {

	glPushMatrix();

	glTranslatef(-0.8, 1.85, -4.0);
	glRotatef(-85.0, 0.0, 0.0, 1.0);
	glScalef(1.3f, 1.8f, 1.3f);
	log.render();

	glPopMatrix();
}