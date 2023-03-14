#pragma once

#include <directxmath.h>
#include <d3d11_4.h>
#include <string>
#include "Structures.h"
#include "Vector3.h"

#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Appearance* appearance);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject* parent) { _parent = parent; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

	Transform* GetTransform() { return _transform; }
	Appearance* GetAppearance() { return _appearance; }
	//PhysicsModel* GetPhysicsModel() { return _physics; }
	ParticleModel* GetParticleModel() { return _particleModel; }

	//world matrix
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

private:
	string _type;
	XMFLOAT4X4 _world;

	GameObject * _parent;
	Transform* _transform;
	Appearance* _appearance;
	//PhysicsModel* _physics;
	ParticleModel* _particleModel;
};

