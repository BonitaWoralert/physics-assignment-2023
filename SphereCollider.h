#pragma once
#include "Collider.h"
class SphereCollider : public Collider
{
private:
	float radius = 1.0f;

	float penetration = 0.0f;
	Vector3 normal = Vector3(0.0f,0.0f,0.0f);
	Vector3 contactPoint = Vector3(0.0f, 0.0f, 0.0f);
public:
	SphereCollider(Transform* tf, float r) : Collider(tf) { radius = r; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(PlaneCollider& other) override;

	float GetRadius() const { return radius; }

	float GetPenetration() const { return penetration; }
	Vector3 GetNormal() const { return normal; }
	Vector3 GetContactPoint() const { return contactPoint; }
};

