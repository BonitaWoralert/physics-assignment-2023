#pragma once
#include "Collider.h"
#include <cmath>
class AABBCollider : public Collider
{
private:
	Vector3 _halfWidth; //half width extents (x,y,z)
public:
	AABBCollider(Transform* t, Vector3 halfWidth) : Collider(t) { _halfWidth = halfWidth;}

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;
};

