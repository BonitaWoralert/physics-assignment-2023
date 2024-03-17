#pragma once

#include <directxmath.h>
#include <d3d11_4.h>
#include <string>
#include "Vector3.h"
#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"
#include "RigidBodyModel.h"

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Appearance* appearance, PhysicsModel* physics);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(float t);

	Transform* GetTransform() { return _transform; }
	Appearance* GetAppearance() { return _appearance; }
	PhysicsModel* GetPhysicsModel() { return _physicsModel; }
private:
	Transform* _transform;
	Appearance* _appearance;
	PhysicsModel* _physicsModel;

	string _type;

	GameObject * _parent;

};

