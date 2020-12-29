#pragma once


#include <vector>
#include "Vector3.h"
#include "Input.h"
class Camera
{
public:
	void updateRotation();
	//MOVEMENTS
	void moveUp(float dt, float speed);
	void moveSide(float dt, float speed);
	void moveForward(float dt, float speed);
	void InputMovement(Input& input, float dt, int width, int height);

	Vector3 position = { 0.0f, 1.0f, 6.0f };
	Vector3 lookat = { 0.0f, 0.0f, 0.0f };
	Vector3 up = { 0.0f, 1.0f, 0.0f };
	//PITCH , YAW, ROLL
	Vector3 rotation = { 0, 0, 0 };
protected:
	void updateLookAt();

	//values for sin/cos for calculating rotation
	float cosR, cosP, cosY;
	float sinR, sinP, sinY;
	//vectors for camera
	Vector3 forward = { 0.0f, 0.0f, -1.0f };
	Vector3 right = { 1.0f, 0.0f, 0.0f };
};

