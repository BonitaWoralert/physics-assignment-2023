#pragma once

#include <directxmath.h>
#include <d3d11_4.h>
#include <string>
#include "Structures.h"
#include "Vector3.h"

#include "Transform.h"
#include "Appearance.h"

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

private:
	string _type;

	GameObject * _parent;
	Transform* _transform;
	Appearance* _appearance;
};

