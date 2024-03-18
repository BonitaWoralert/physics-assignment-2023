#include "PlaneCollider.h"

bool PlaneCollider::CollidesWith(SphereCollider& other)
{
    return false;
}

bool PlaneCollider::CollidesWith(AABBCollider& other)
{
    return false;
}

bool PlaneCollider::CollidesWith(PlaneCollider& other)
{
    return false;
}
