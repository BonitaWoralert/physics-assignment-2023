#pragma once
#include "Collider.h"
class PlaneCollider : public Collider
{
public:
	Vector3 normal;
	float offset;
};

