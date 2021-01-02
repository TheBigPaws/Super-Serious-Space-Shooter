#include "Effects.h"

smokeParticle::smokeParticle() {
	direction.x = 0.25 - float(rand() % 500) / 1000.0;
	direction.y = 0.75 + float(rand() % 500) / 1000.0;
	direction.z = 0.25 - float(rand() % 500) / 1000.0;

	position.x = 0.0;
	position.y = 10.0;
	position.z = -4.2;

	sizeX = 0.1;
	sizeY = 0.1;
	transparency = 1.0;
}


Effects::Effects() {
	timePassed = 0.0;
	X_SSH = 0.0;
	Y_SSH = 0.0;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	FireSpriteSheet = SOIL_load_OGL_texture(
		"gfx/FireSSH.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void Effects::incrementTime(float dt) {
	timePassed += dt;
	spawnNewSmoke += dt;

	if (spawnNewSmoke > 1.0) {
		spawnNewSmoke = 0.0;
		SmokeParts.push_back(smokeParticle());
	}

	if (timePassed > 0.03) {
		timePassed = 0.0;
		X_SSH += 0.125;

		if (X_SSH == 1.0) {
			X_SSH = 0.0;
			Y_SSH += 0.25;
			if (Y_SSH == 1.0) {
				Y_SSH = 0.0;
			}
		}

		for (int i = 0; i < SmokeParts.size(); i++) {
			if (SmokeParts.at(i).position.y > 30) {
				SmokeParts.erase(SmokeParts.begin() + i);
				break;
			}
		}

	}


	for (int i = 0; i < SmokeParts.size(); i++) {
		SmokeParts.at(i).position.x += SmokeParts.at(i).direction.x * dt;
		SmokeParts.at(i).position.y += SmokeParts.at(i).direction.y * dt;
		SmokeParts.at(i).position.z += SmokeParts.at(i).direction.z * dt;
		if (SmokeParts.at(i).sizeX < 1.0) {
			SmokeParts.at(i).sizeX += dt*0.1;
			SmokeParts.at(i).sizeY += dt * 0.1;
			SmokeParts.at(i).transparency -= dt * 0.07;
		}
	}
} 


void Effects::renderFire() {

	glBindTexture(GL_TEXTURE_2D, FireSpriteSheet);
	glEnable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_EMISSION, new GLfloat[]{ 1.0f,1.0f,0.0f,1.0, });
	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 0.0);
	//FRONT
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH, Y_SSH);
	glVertex3f(-1.0,4.20,-3.75);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH, Y_SSH + 0.25);
	glVertex3f(-1.0, 1.6, -3.75);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH + 0.125, Y_SSH+0.25);
	glVertex3f(1.0, 1.6, -3.75);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH + 0.125, Y_SSH);
	glVertex3f(1.0, 4.20, -3.75);

	glEnd();
	glDisable(GL_BLEND);
	glMaterialfv(GL_FRONT, GL_EMISSION, new GLfloat[]{ 0.0f,0.0f,0.0f,1.0, });
	glEnable(GL_COLOR_MATERIAL);
}

void Effects::renderSmoke(Vector3 CameraPosition) {
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);

	for (int i = 0; i < SmokeParts.size(); i++) {

		glPushMatrix();
		glColor4f(0.8, 0.8, 0.8, SmokeParts.at(i).transparency);
			glTranslatef(SmokeParts.at(i).position.x, SmokeParts.at(i).position.y, SmokeParts.at(i).position.z);
			glRotatef(atan( (CameraPosition.x - SmokeParts.at(i).position.x) / (CameraPosition.z - SmokeParts.at(i).position.z)) * 57.3, 0.0, 1.0, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(- SmokeParts.at(i).sizeX, SmokeParts.at(i).sizeY, 0);

			glVertex3f(- SmokeParts.at(i).sizeX, - SmokeParts.at(i).sizeY, 0);

			glVertex3f(SmokeParts.at(i).sizeX,  - SmokeParts.at(i).sizeY, 0);

			glVertex3f(SmokeParts.at(i).sizeX, SmokeParts.at(i).sizeY, 0);
			glEnd();
		glPopMatrix();

	}

	//glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

}


void Effects::renderEffects(Vector3 CameraPosition) {
	renderFire();
	renderSmoke(CameraPosition);
}