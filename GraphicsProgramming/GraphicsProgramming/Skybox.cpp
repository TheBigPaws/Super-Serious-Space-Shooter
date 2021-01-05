#include "Skybox.h"

Skybox::Skybox() {
	skyboxTexture = SOIL_load_OGL_texture(
		"gfx/Snowy.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}
void Skybox::RenderSBOX(GLfloat x, GLfloat y, GLfloat z) {

	glBindTexture(GL_TEXTURE_2D, skyboxTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient);

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT2);
	glEnable(GL_LIGHT1);
	
	glDisable(GL_DEPTH_TEST);

	glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_QUADS);


	//front face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.25f, 0.3333f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.25f, 0.6666f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.5f, 0.6666f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.5f, 0.3333f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//right face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.5f, 0.334f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.5f, 0.665f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.75f, 0.665f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.75f, 0.334f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//back face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.75f, 0.334f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.75f, 0.665f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 0.665f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 0.334f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	//left face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.334f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.665f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.25f, 0.665f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.25f, 0.334f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	//top face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.251f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.251f, 0.3333f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.499f, 0.3333f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.499f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//bottom face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.251f, 0.6666f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.251f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.499f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.499f, 0.6666f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	glDisable(GL_LIGHT1);
	if (outsidelight == true) {
		glEnable(GL_LIGHT2);
	}
	glEnable(GL_LIGHT0);
	//END OF SKYBOX
}

void Skybox::changeOutsideLight() {
	if (outsidelight == true) {
		outsidelight = false;
		Light_Ambient[0] = 0.1f;
		Light_Ambient[1] = 0.1f;
		Light_Ambient[2] = 0.1f;
	}
	else {
		outsidelight = true;
		Light_Ambient[0] = 1.0f;
		Light_Ambient[1] = 1.0f;
		Light_Ambient[2] = 1.0f;
	}
}