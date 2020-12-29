#include "Effects.h"

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
	}

} 


void Effects::renderFire() {

	glBindTexture(GL_TEXTURE_2D, FireSpriteSheet);
	glEnable(GL_BLEND);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	//FRONT
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH, Y_SSH);
	glVertex3f(-1.0,4.0,-3.5);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH, Y_SSH + 0.25);
	glVertex3f(-1.0, 1.0, -3.5);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH + 0.125, Y_SSH+0.25);
	glVertex3f(1.0, 1.0, -3.5);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(X_SSH + 0.125, Y_SSH);
	glVertex3f(1.0, 4.0, -3.5);

	glEnd();
	glDisable(GL_BLEND);
}