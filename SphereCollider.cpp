#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other)
{
    float distance = (other.GetPosition() - GetPosition()).Magnitude(); //length of the vector between the two positions
    float combinedRadius = radius + other.radius; 
    if (distance < combinedRadius) //if the distance between positions is less than combined radius, they are colliding
        return true;
    else
        return false;
}
