#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other)
{
    //vector between the 2 objects
    Vector3 midline = GetPosition() - other.GetPosition();
    float size = midline.Magnitude();

    //check if size is large enough
    if (size <= 0.0f || size >= _radius + other._radius)
        return 0;

    //create normal, check penetration etc
    _normal = midline * (1.0 / size);
    _contactPoint = GetPosition() + midline * 0.5;
    _penetration = _radius + other._radius - size;

    //return collision
    return 1;
}

bool SphereCollider::CollidesWith(AABBCollider& other)
{
    return false;
}

bool SphereCollider::CollidesWith(PlaneCollider& other)
{
    return false;
}
