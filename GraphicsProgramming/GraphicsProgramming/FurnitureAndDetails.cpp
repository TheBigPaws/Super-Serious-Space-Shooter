#include "FurnitureAndDetails.h"

FurnitureAndDetails::FurnitureAndDetails() {
	rock.load("models/Rock.obj", "gfx/StoneObjText.png");
	tree.load("models/OakTree.obj", "gfx/TreeTexture.png");
	log.load("models/WoodenLog.obj", "gfx/texture_log.png");
}

void FurnitureAndDetails::renderAll() {

	glPushMatrix();

		glTranslatef(6.0, 0.0, 15.0);
		//glScalef(0.2f, 0.2f, 0.2f);
		rock.render();

	glPopMatrix();

	glPushMatrix();

		glTranslatef(-6.0, -0.5, 22.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(0.2f, 0.2f, 0.2f);
		tree.render();

	glPopMatrix();

	glPushMatrix();

		glTranslatef(-0.8, 1.85, -4.0);
		glRotatef(-85.0, 0.0, 0.0, 1.0);
		glScalef(1.3f, 1.8f, 1.3f);
		log.render();

	glPopMatrix();
}