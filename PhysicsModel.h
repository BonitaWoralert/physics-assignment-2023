#pragma once
#include "Transform.h"
#include "Collider.h"

#define GRAVITYSTRENGTH -9.81f

#define DRAGCOEFFICIENT 0.5f
#define DENSITY 1.2f
#define AREA 1.0f

//abstract class
class PhysicsModel
{
public:
	//constructors
	PhysicsModel();
	PhysicsModel(float mass, bool grav);

	//physics functions
	virtual void Update(float deltaTime) = 0;
	void AddForce(Vector3 force) { _netForce += force; }
	Vector3 GravityForce();
	Vector3 DragForce();
	Vector3 FrictionForce();
	void ApplyImpulse(Vector3 impulse) { _velocity += impulse; }
	void CollisionResponse();

	//getters and setters
	float GetMass() { return _mass; }

	void SetVelocity(Vector3 newVelocity) { _velocity = newVelocity; }
	Vector3 GetVelocity() { return _velocity; }
	
	void SetAcceleration(Vector3 newAcceleration) { _acceleration = newAcceleration; }
	Vector3 GetAcceleration() { return _acceleration; }

	void SetTransform(Transform* newTransform) { _transform = newTransform; }

	bool IsCollideable() const { return _collider != nullptr; }
	Collider* GetCollider() const { return _collider; }
	void SetCollider(Collider* newCollider) { _collider = newCollider; }
protected:
	//collision
	Collider* _collider = nullptr;

	//transform	
	Transform* _transform = nullptr;

	//forces
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;
	float _mass = 1.0f;
	bool _simulateGravity = false;
	float _drag;


};

