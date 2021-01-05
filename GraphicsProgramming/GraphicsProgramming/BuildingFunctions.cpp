#include "BuildingFunctions.h"

void BuildingFunctions::makeBlock(GLfloat MidPozX, GLfloat MidPozY, GLfloat MidPozZ, GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ, GLfloat scaleTXTvSIZE, GLuint texture) {
	
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	glBegin(GL_QUADS);
	//FRONT
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(MidPozX - sizeX / 2, MidPozY + sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX - sizeX / 2, MidPozY - sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX + sizeX / 2, MidPozY - sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, 0.0f);
	glVertex3f(MidPozX + sizeX / 2, MidPozY + sizeY / 2, MidPozZ + sizeZ / 2);

	//RIGHT
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(MidPozX + sizeX / 2, MidPozY + sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX + sizeX / 2, MidPozY - sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(sizeZ / scaleTXTvSIZE, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX + sizeX / 2, MidPozY - sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(sizeZ / scaleTXTvSIZE, 0.0f);
	glVertex3f(MidPozX + sizeX / 2, MidPozY + sizeY / 2, MidPozZ - sizeZ / 2);

	//back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(MidPozX + sizeX / 2, MidPozY + sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX + sizeX / 2, MidPozY - sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX - sizeX / 2, MidPozY - sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, 0.0f);
	glVertex3f(MidPozX - sizeX / 2, MidPozY + sizeY / 2, MidPozZ - sizeZ / 2);

	//left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(MidPozX - sizeX / 2, MidPozY + sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX - sizeX / 2, MidPozY - sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(sizeZ / scaleTXTvSIZE, sizeY / scaleTXTvSIZE);
	glVertex3f(MidPozX - sizeX / 2, MidPozY - sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(sizeZ / scaleTXTvSIZE, 0.0f);
	glVertex3f(MidPozX - sizeX / 2, MidPozY + sizeY / 2, MidPozZ + sizeZ / 2);

	//top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(MidPozX - sizeX / 2, MidPozY + sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, sizeZ / scaleTXTvSIZE);
	glVertex3f(MidPozX - sizeX / 2, MidPozY + sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, sizeZ / scaleTXTvSIZE);
	glVertex3f(MidPozX + sizeX / 2, MidPozY + sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, 0.0f);
	glVertex3f(MidPozX + sizeX / 2, MidPozY + sizeY / 2, MidPozZ - sizeZ / 2);

	//bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(MidPozX - sizeX / 2, MidPozY - sizeY / 2, MidPozZ - sizeZ / 2);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, sizeZ / scaleTXTvSIZE);
	glVertex3f(MidPozX - sizeX / 2, MidPozY - sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, sizeZ / scaleTXTvSIZE);
	glVertex3f(MidPozX + sizeX / 2, MidPozY - sizeY / 2, MidPozZ + sizeZ / 2);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(sizeX / scaleTXTvSIZE, 0.0f);
	glVertex3f(MidPozX + sizeX / 2, MidPozY - sizeY / 2, MidPozZ - sizeZ / 2);

	glEnd();

}

void BuildingFunctions::makeTextRect(Vector3 leftup, Vector3 leftdown, Vector3 rightdown, Vector3 rightup, Vector3 normal, GLfloat textsizeX, GLfloat textsizeY, GLuint texture) {

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glBegin(GL_QUADS);

	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(leftup.x, leftup.y, leftup.z);

	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(0.0f, textsizeY);
	glVertex3f(leftdown.x, leftdown.y, leftdown.z);

	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(textsizeX, textsizeY);
	glVertex3f(rightdown.x, rightdown.y, rightdown.z);

	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(textsizeX, 0.0f);
	glVertex3f(rightup.x, rightup.y, rightup.z);

	glEnd();
}

void BuildingFunctions::makeTextTria(Vector3 vert1, Vector3 vert2, Vector3 vert3, Vector3 normal, Vector3 textv1, Vector3 textv2, Vector3 textv3, GLuint texture) {
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glBegin(GL_TRIANGLES);
	//FRONT
	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(textv1.x, textv1.y);
	glVertex3f(vert1.x, vert1.y, vert1.z);

	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(textv2.x, textv2.y);
	glVertex3f(vert2.x, vert2.y, vert2.z);

	glNormal3f(normal.x, normal.y, normal.z);
	glTexCoord2f(textv3.x, textv3.y);
	glVertex3f(vert3.x, vert3.y, vert3.z);

	glEnd();

}
