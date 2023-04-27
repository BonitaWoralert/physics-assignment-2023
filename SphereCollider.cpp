#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other)
{
    Vector3 midline = GetPosition() - other.GetPosition();
    float distance = midline.Magnitude(); //length of the vector between the two positions
    float combinedRadius = GetRadius() + other.GetRadius();
     
    if (distance < combinedRadius) //if the distance between positions is less than combined radius, they are colliding
    {
        normal = midline * (1.0 / distance);
        contactPoint = GetPosition() + midline * 0.5;
        penetration = combinedRadius - distance;
        return true;
    }
    else
        return false;
}

bool SphereCollider::CollidesWith(PlaneCollider& other)
{

    return false;
}
