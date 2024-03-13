#include "AABBCollider.h"

bool AABBCollider::CollidesWith(AABBCollider& other)
{
    Vector3 max = GetPosition() + GetMax();
    Vector3 otherMax = other.GetPosition() + GetMax();
    Vector3 min = GetPosition() + GetMin();
    Vector3 otherMin = other.GetPosition() + GetMin();

    //no intersection if separated along an axis
    if (max.x < otherMin.x || min.x > otherMax.x) return false;
    if (max.y < otherMin.y || min.y > otherMax.y) return false;
    if (max.z < otherMin.z || min.z > otherMax.z) return false;
    
    //overlapping on all axes, return true!
    return true;
}

bool AABBCollider::CollidesWith(PlaneCollider& other)
{
    return false;
}

bool AABBCollider::CollidesWith(SphereCollider& other)
{
    //they intersect if the (squared) distance between them is less than the (squared) sphere radius!
    float sqDist = SqDistPointAABB(other.GetPosition());
    return sqDist <= other.GetRadius() * other.GetRadius(); 
}

float AABBCollider::SqDistPointAABB(Vector3 point)
{
    float sqDist = 0.0f;
    
    if (point.x < GetMin().x) sqDist += (GetMin().x - point.x) * (GetMin().x - point.x);
    if (point.x < GetMax().x) sqDist += (point.x - GetMax().x) * (point.x - GetMax().x);

    if (point.y < GetMin().y) sqDist += (GetMin().y - point.y) * (GetMin().y - point.y);
    if (point.y < GetMax().y) sqDist += (point.y - GetMax().y) * (point.y - GetMax().y);

    if (point.z < GetMin().z) sqDist += (GetMin().z - point.z) * (GetMin().z - point.z);
    if (point.z < GetMax().z) sqDist += (point.z - GetMax().z) * (point.z - GetMax().z);
    
    return sqDist;
}
