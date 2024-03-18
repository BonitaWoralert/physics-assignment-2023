#pragma once
#include "Transform.h"

//forward declare colllision classes
class SphereCollider;

class Collider abstract
{
protected:
	Transform* _transform;
public:
	Collider(Transform* t) : _transform(t) {}

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;

	Vector3 GetPosition() const { return _transform->GetPosition(); }
};

