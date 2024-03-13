#pragma once
#include "Collider.h"
#include "SphereCollider.h"

class AABBCollider : public Collider
{
private:
	Vector3 min = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 max = Vector3(0.0f, 0.0f, 0.0f);
public:
	AABBCollider(Transform* tf, Vector3 min, Vector3 max) : Collider(tf) { this->min = min, this->max = max; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(AABBCollider& other) override;
	virtual bool CollidesWith(PlaneCollider& other) override;
	virtual bool CollidesWith(SphereCollider& other) override;

	Vector3 GetMin() const { return min; }
	Vector3 GetMax() const { return max; }

	float SqDistPointAABB(Vector3 point);
};

