#include "Skybox.h"

Skybox::Skybox() {
	skyboxTexture = SOIL_load_OGL_texture(
		"gfx/Snowy.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}
void Skybox::RenderSBOX(GLfloat x, GLfloat y, GLfloat z) {

	Light_Position[0] = x;
	Light_Position[1] = y;
	Light_Position[2] = z;
	glBindTexture(GL_TEXTURE_2D, skyboxTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, Light_Position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient);

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT2);
	glDisable(GL_DEPTH_TEST);

	glEnable(GL_LIGHT1);

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
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT0);
	//END OF SKYBOX
}