#include "PhysicsModel.h"

PhysicsModel::PhysicsModel()
{
}

PhysicsModel::PhysicsModel(float mass, bool grav) : _mass(mass), _simulateGravity(grav)
{
}

void PhysicsModel::Update(float deltaTime)
{
	//initialise position
	Vector3 position = _transform->GetPosition();

	//gravity
	if (_simulateGravity && position.y > 1.0f)
	{
		_netForce += GravityForce();
	}
	else //temporary until collision with ground is added
	{
		_velocity.y = 0;
	}

	//add drag
	_netForce += DragForce();

	//add friction
	_netForce += FrictionForce();

	//calculate acceleration using F = M * A
	_acceleration = _netForce / _mass;

	//calculate velocity using V = A * dt
	_velocity += _acceleration * deltaTime;

	//position is updated based on constant velocity
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	//velo and pos calculations complete, reset force and acceleration
	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
}

Vector3 PhysicsModel::GravityForce()
{
	//gravity strength * mass
	return Vector3(0, GRAVITYSTRENGTH * _mass, 0);
}

Vector3 PhysicsModel::DragForce()
{
	//F = 0.5 * density * drag coefficient * reference area * velocity^2
	// 
	//start as negative velocity normalised
	Vector3 dragForce = -_velocity; 
	dragForce.Normalize();

	//use formula to calculate value to scale by
	float scaledValue = 0.5 * DENSITY * DRAGCOEFFICIENT * AREA * _velocity.Magnitude();

	dragForce *= scaledValue;

	return dragForce;
}

Vector3 PhysicsModel::FrictionForce()
{
	//F = coefficient of static friction * normal force
	Vector3 frictionForce = -_velocity;
	frictionForce.Normalize();
	
	float coefficient = 0.5f;

	float scalar;

	return Vector3();
}
