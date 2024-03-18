#include "AABBCollider.h"

bool AABBCollider::CollidesWith(SphereCollider& other)
{
	/*NEED TO IMPLEMENT :
	- sphere's center position must be converted into the box's local coordinates
	to do this, we do:
	centerpos * inverse(cube model matrix)
	*/

	//distance between sphere center and AABB position
	//then compare with radius
	//if distance < radius, then they are colliding

	Vector3 closestPoint;
	Vector3 otherPos = other.GetPosition();
	float dist;

	//clamp coordinates to box
	dist = otherPos.x;
	if (dist > _halfWidth.x) dist = _halfWidth.x;
	if (dist < -_halfWidth.x) dist = -_halfWidth.x;
	closestPoint.x = dist;

	dist = otherPos.y;
	if (dist > _halfWidth.y) dist = _halfWidth.y;
	if (dist < -_halfWidth.y) dist = -_halfWidth.y;
	closestPoint.y = dist;

	dist = otherPos.z;
	if (dist > _halfWidth.z) dist = _halfWidth.z;
	if (dist < -_halfWidth.z) dist = -_halfWidth.z;
	closestPoint.z = dist;

	//distance bigger than radius
	dist = (closestPoint - otherPos).SquareMagnitude(); //square magnitude to avoid sqrt
	if (dist > other.GetRadius() * other.GetRadius()) return 0;

	//return collision
	return 1;
}

//AABB-AABB intersection
bool AABBCollider::CollidesWith(AABBCollider& other)
{
	Vector3 pos = GetPosition();
	Vector3 otherPos = other.GetPosition();

	//overlap tests
	if (std::abs(pos.x - otherPos.x) > (_halfWidth.x + other._halfWidth.x)) return 0;
	if (std::abs(pos.y - otherPos.y) > (_halfWidth.y + other._halfWidth.y)) return 0;
	if (std::abs(pos.z - otherPos.z) > (_halfWidth.z + other._halfWidth.z)) return 0;

	//collided
	return 1;
}

bool AABBCollider::CollidesWith(PlaneCollider& other)
{
	return false;
}
