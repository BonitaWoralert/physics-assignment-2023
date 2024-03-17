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
protected:
	Transform* _transform = nullptr;
	Vector3 _velocity;
};

