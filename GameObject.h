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
	GameObject(string type, Appearance* appearance, bool gravity, float mass);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject* parent) { _parent = parent; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

	Transform* GetTransform() { return _transform; }
	Appearance* GetAppearance() { return _appearance; }
	ParticleModel* GetParticleModel() { return _particleModel; }

	//world matrix
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

private:
	string _type;
	bool _gravity;
	float _mass = 10.0f;
	XMFLOAT4X4 _world;

	GameObject * _parent;
	Transform* _transform;
	Appearance* _appearance;
	ParticleModel* _particleModel;
};

