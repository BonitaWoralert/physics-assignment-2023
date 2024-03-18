#include "AABBCollider.h"

bool AABBCollider::CollidesWith(SphereCollider& other)
{
	return false;
}

//AABB-AABB intersection
bool AABBCollider::CollidesWith(AABBCollider& other)
{
	Vector3 pos = _transform->GetPosition();
	Vector3 otherPos = other._transform->GetPosition();

	//overlap tests
	if (std::abs(pos.x - otherPos.x) > (_halfWidth.x + other._halfWidth.x)) return 0;
	if (std::abs(pos.y - otherPos.y) > (_halfWidth.y + other._halfWidth.y)) return 0;
	if (std::abs(pos.z - otherPos.z) > (_halfWidth.z + other._halfWidth.z)) return 0;

	//collided
	return 1;
}
