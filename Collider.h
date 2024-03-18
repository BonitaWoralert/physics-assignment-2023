#pragma once
#include "Transform.h"

//forward declare collision classes
class SphereCollider;
class AABBCollider;
class PlaneCollider;

class Collider abstract
{
protected:
	Transform* _transform;
public:
	Collider(Transform* t) : _transform(t) {}

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;
	virtual bool CollidesWith(AABBCollider& other) = 0;
	virtual bool CollidesWith(PlaneCollider& other) = 0;

	Vector3 GetPosition() const { return _transform->GetPosition(); }
};

