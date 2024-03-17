#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance) : _type(type), _appearance(appearance)
{
	_transform = new Transform();
	_physicsModel = new PhysicsModel(_transform);
	_parent = nullptr;
}

GameObject::~GameObject()
{
	_transform = nullptr;
	_appearance = nullptr;
	_parent = nullptr;
}

void GameObject::Update(float t)
{
	_physicsModel->Update(t);
	_transform->Update();
	
	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_transform->GetWorld(), _transform->GetWorldMatrix() * _parent->GetTransform()->GetWorldMatrix());
	}
}

