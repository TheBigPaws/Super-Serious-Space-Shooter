#include "FurnitureAndDetails.h"

FurnitureAndDetails::FurnitureAndDetails() {
	rock.load("models/Rock.obj", "gfx/StoneObjText.png");
	tree.load("models/OakTree.obj", "gfx/TreeTexture.png");
	log.load("models/WoodenLog.obj", "gfx/texture_log.png");
	shelf.load("models/chair.obj", "gfx/chair_DIFF.png");
	//shelf.load("models/veliero.obj", "gfx/shipTexture.png");
}

void FurnitureAndDetails::renderAll() {

	glPushMatrix();

		glTranslatef(6.0, 0.0, 15.0);
		//glScalef(0.2f, 0.2f, 0.2f);
		rock.render();

	glPopMatrix();

	glPushMatrix();
		glTranslatef(-13.0, -0.5, 15.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(0.2f, 0.2f, 0.2f);
		tree.render();
		glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.8, 1.85, -4.0);
		glRotatef(-85.0, 0.0, 0.0, 1.0);
		glScalef(1.3f, 1.8f, 1.3f);
		log.render();

	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.0, 1.0, 1.0);
		glRotatef(-165.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.3);
		shelf.render();

	glPopMatrix();
}