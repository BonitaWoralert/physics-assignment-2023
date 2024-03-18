#pragma once
#include "Collider.h"
class SphereCollider : public Collider
{
private:
	float _radius = 1.0f;

	//collision
	float _penetration = 0.0f;
	Vector3 _normal = Vector3(0, 0, 0);
	Vector3 _contactPoint = Vector3(0, 0, 0);
public:
	SphereCollider(Transform* t, float r) : Collider(t) { _radius = r; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AABBCollider& other) override;
	virtual bool CollidesWith(PlaneCollider& other) override;

	float GetRadius() const { return _radius; }
};

