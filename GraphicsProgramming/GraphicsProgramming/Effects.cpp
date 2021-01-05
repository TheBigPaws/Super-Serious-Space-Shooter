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
	nextFireFrame = 0.0;
	fire_X_SSH = 0.0;
	fire_Y_SSH = 0.0;
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	FireSpriteSheet = SOIL_load_OGL_texture(
		"gfx/FireSSH.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

//increments delta time to all relevant variables and does the corresponding functions
void Effects::incrementTime(float dt) {
	nextFireFrame += dt;
	spawnNewSmoke += dt;

	if (spawnNewSmoke > 1.0) {
		spawnNewSmoke = 0.0;
		SmokeParts.push_back(smokeParticle());
	}
	//iterates through the spritesheet for the fire, simulating animated fire
	if (nextFireFrame > 0.03) {
		nextFireFrame = 0.0;
		fire_X_SSH += 0.125;

		if (fire_X_SSH == 1.0) {
			fire_X_SSH = 0.0;
			fire_Y_SSH += 0.25;
			if (fire_Y_SSH == 1.0) {
				fire_Y_SSH = 0.0;
			}

			//this piece of code is only nested here so it doesn't need to execute with every frame - saves some memory
			for (int i = 0; i < SmokeParts.size(); i++) { //checks if the smoke particle is too high - delete it if it is
				if (SmokeParts.at(i).position.y > 30) {
					SmokeParts.erase(SmokeParts.begin() + i);
					break;
				}
			}
		}

	}

	//moves smoke particles
	for (int i = 0; i < SmokeParts.size(); i++) {
		SmokeParts.at(i).position.x += SmokeParts.at(i).direction.x * dt;
		SmokeParts.at(i).position.y += SmokeParts.at(i).direction.y * dt;
		SmokeParts.at(i).position.z += SmokeParts.at(i).direction.z * dt;
		if (SmokeParts.at(i).sizeX < 1.0) {//simulates the smoke dispersing
			SmokeParts.at(i).sizeX += dt*0.1;
			SmokeParts.at(i).sizeY += dt * 0.1;
			SmokeParts.at(i).transparency -= dt * 0.07;
		}
	}
} 

//renders the current frame of the fire animation
void Effects::renderFire() {

	glBindTexture(GL_TEXTURE_2D, FireSpriteSheet);
	glEnable(GL_BLEND);
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_EMISSION, fireGlowOn); //makes the fire glow
	glBegin(GL_QUADS);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(fire_X_SSH, fire_Y_SSH);
		glVertex3f(-1.0,4.20,-3.75);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(fire_X_SSH, fire_Y_SSH + 0.25);
		glVertex3f(-1.0, 1.6, -3.75);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(fire_X_SSH + 0.125, fire_Y_SSH+0.25);
		glVertex3f(1.0, 1.6, -3.75);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(fire_X_SSH + 0.125, fire_Y_SSH);
		glVertex3f(1.0, 4.20, -3.75);

	glEnd();
	glDisable(GL_BLEND);
	glMaterialfv(GL_FRONT, GL_EMISSION, fireGlowOff);
	glEnable(GL_COLOR_MATERIAL);
}

//renders every particle of smoke.
void Effects::renderSmoke(Vector3 CameraPosition) {
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);

	for (int i = 0; i < SmokeParts.size(); i++) {

		glPushMatrix();
		glColor4f(0.8, 0.8, 0.8, SmokeParts.at(i).transparency);
			//translate to the current particle's position for easier calculations
			glTranslatef(SmokeParts.at(i).position.x, SmokeParts.at(i).position.y, SmokeParts.at(i).position.z);
			//rotate the smoke particles towards the camera
			glRotatef(atan( (CameraPosition.x - SmokeParts.at(i).position.x) / (CameraPosition.z - SmokeParts.at(i).position.z)) * 57.3, 0.0, 1.0, 0.0);
			glBegin(GL_QUADS);//normals not necessary, doesn't interact with light
				
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

//renders effects
void Effects::renderEffects(Vector3 CameraPosition) {
	renderFire();
	renderSmoke(CameraPosition);
}