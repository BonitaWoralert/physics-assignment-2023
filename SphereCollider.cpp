#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other)
{
    //vector between the 2 objects
    Vector3 midline = _transform->GetPosition() - other._transform->GetPosition();
    float size = midline.Magnitude();

    //check if size is large enough
    if (size <= 0.0f || size >= _radius + other._radius)
        return 0;

    //create normal, check penetration etc

    //return collision
    return 1;
}

bool SphereCollider::CollidesWith(AABBCollider& other)
{
    return false;
}
