#pragma once
#include "Collider.h"
class SphereCollider : public Collider
{
	float radius = 1.0f;

public:
	SphereCollider(Transform* tf, float r) : Collider(tf) { radius = r; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;

	float GetRadius() const { return radius; }
};

