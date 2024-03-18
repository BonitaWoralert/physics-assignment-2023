#pragma once
#include "Collider.h"
class SphereCollider : public Collider
{
private:
	float _radius = 1.0f;
public:
	SphereCollider(Transform* t, float r) : Collider(t) { _radius = r; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;

	float GetRadius() const { return _radius; }
};

