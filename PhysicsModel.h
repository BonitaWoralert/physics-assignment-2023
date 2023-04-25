#pragma once
#define GRAVITYSTRENGTH -9.81
#define DRAGCOEFFICIENT 0.5f
#define DENSITY 1.2
#define AREA 1.0

#include "Transform.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "Debug.h"
class PhysicsModel
{
protected:
	Collider* _collider;
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;
	float _mass;
	bool _simulateGravity = false;
public:
	PhysicsModel(Transform* tf);

	//OLD
	//instead, make get and set for mass / grav
	//PhysicsModel(Transform* transform, float mass, bool simulateGravity);

	virtual void Update(float deltaTime);

	//forces
	virtual void AddForce(Vector3 force) { _netForce += force; }
	virtual Vector3 GravityForce() { return Vector3(0, -0.981*_mass, 0); }

	virtual Vector3 DragForce() { 
		Vector3 direction = _velocity;
		direction.Reverse();
		direction.Normalize();
		Vector3 dragForce = 0.5 * DENSITY * DRAGCOEFFICIENT * AREA * _velocity.Magnitude() * direction;

		DebugPrintF("drag is = (%f, %f, %f)\n", dragForce.x, dragForce.y, dragForce.z);
		return dragForce;
	}

	//get and set
	virtual Vector3 GetVelocity() { return _velocity;}
	virtual void SetVelocity(Vector3 velocity) { _velocity = velocity; }

	virtual void SetMass(float mass) { _mass = mass; }
	virtual void SetGravity(bool grav) { _simulateGravity = grav; }

	//colliders
	bool IsCollideable() const { return _collider != nullptr; }
	Collider* GetCollider() const { return _collider; }
	void SetCollider(Collider* newCollider) { _collider = newCollider; }

	//impulse
	void ApplyImpulse(Vector3 impulse) { _velocity += impulse; }
};

