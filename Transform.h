#pragma once
#include "Vector3.h"
class Transform
{
private:
	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;
public:
	// Setters and Getters for position/rotation/scale
	void SetPosition(Vector3 position) { _position = position; }
	void SetPosition(float x, float y, float z) 
	{ _position.x = x; _position.y = y; _position.z = z; }
	Vector3 GetPosition() { return _position; }

	void SetRotation(Vector3 rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) 
	{ _rotation.x = x; _rotation.y = y; _rotation.z = z; }
	Vector3 GetRotation() { return _rotation; }

	void SetScale(Vector3 scale) { _scale = scale; }
	void SetScale(float x, float y, float z) 
	{ _scale.x = x; _scale.y = y; _scale.z = z; }
	Vector3 GetScale() { return _scale; }
};

