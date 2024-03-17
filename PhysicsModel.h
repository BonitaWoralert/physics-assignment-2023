#pragma once
#include "Transform.h"
class PhysicsModel
{
private:
public:
	PhysicsModel(Transform* t);
	void Update(float deltaTime);

	void SetVelocity(Vector3 newVelocity) { _velocity = newVelocity; }
	Vector3 GetVelocity() { return _velocity; }
	
	void SetAcceleration(Vector3 newAcceleration) { _acceleration = newAcceleration; }
	Vector3 GetAcceleration() { return _acceleration; }
protected:
	Transform* _transform = nullptr;
	Vector3 _velocity;
	Vector3 _acceleration;
};

