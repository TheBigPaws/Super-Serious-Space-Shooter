#include "Lights.h"

void Lights::renderLights() {

	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, strengthOfFire);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

	glLightfv(GL_LIGHT2, GL_AMBIENT, aLight_Ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, aLight_Diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, aLight_Position);
}
void Lights::calculate(float dt) {

	if (abs(float(strengthOfFire - goalFire)) < 0.05) {
		goalFire = float(rand() % 3000) / 10000.0;
	}
	else if (strengthOfFire < goalFire) {
		strengthOfFire += dt / 2.0;
	}
	else {
		strengthOfFire -= dt / 2.0;
	}

}


void Lights::changeOutsideLight() {
	if (outsidelight == true) {
		outsidelight = false;
		glDisable(GL_LIGHT2);
	}
	else {
		outsidelight = true; 
		glEnable(GL_LIGHT2);
	}
}