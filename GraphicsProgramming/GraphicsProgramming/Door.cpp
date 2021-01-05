#include "Door.h"

Door::Door() {
	doortext = SOIL_load_OGL_texture(
		"gfx/Door.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void Door::incrementDT(float dt) {
	if (!Open) {
		if (rotation < 0) {
			rotation += dt * 100;
		}
	}
	else{
		if (rotation > -120) {
			rotation -= dt * 100;
		}
	}

}

void Door::renderDoor() {
	glBindTexture(GL_TEXTURE_2D, doortext);
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);*/

	glPushMatrix();

		glTranslatef(-1.0, 0.0, 4.8);
		glRotatef(rotation, 0.0, 1.0, 0.0);

		glBegin(GL_QUADS);
		//FRONT
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.0, 5.0, 0.1);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.0, 1.0, 0.1);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(2.0, 1.0, 0.1);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2.0, 5.0, 0.1);

		//RIGHT
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.90f, 0.0f);
		glVertex3f(2.0, 5.0, 0.1);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.90f, 1.0f);
		glVertex3f(2.0, 1.0, 0.1);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2.0, 1.0, -0.1);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.0, 5.0, -0.1);

		//back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(2.0, 5.0, -0.1);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(2.0, 1.0, -0.1);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.0, 1.0, -0.1);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.0, 5.0, -0.1);

		//left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.90f, 0.0f);
		glVertex3f(0.0, 5.0, -0.1);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.90f, 1.0f);
		glVertex3f(0.0, 1.0, -0.1);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.0, 1.0, 0.1);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.0, 5.0, 0.1);

		//top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0, 5.0, -0.1);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.02f);
		glVertex3f(0.0, 5.0, 0.1);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.02f);
		glVertex3f(2.0, 5.0, 0.1);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.0, 5.0, -0.1);

		//bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0, 1.0, -0.1);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.02f);
		glVertex3f(0.0, 1.0, 0.1);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.02f);
		glVertex3f(2.0, 1.0, 0.1);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.0, 1.0, -0.1);

		glEnd();

	glPopMatrix();
}
void Door::switchOpen() {
	if (Open == true) {
		Open = false;
	}
	else { Open = true; }
}