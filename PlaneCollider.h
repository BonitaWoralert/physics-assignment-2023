#pragma once
#include "Collider.h"
class PlaneCollider : public Collider
{
private:
	Vector3 _normal;
	float _offset;
public:
	PlaneCollider(Transform* t, Vector3 normal, float offset) : Collider(t) { _normal = normal, _offset = offset; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;
	virtual bool CollidesWith(PlaneCollider& other) override;
};

