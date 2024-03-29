#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance, PhysicsModel* physics) : _type(type), _appearance(appearance), _physicsModel(physics)
{
	_transform = new Transform();
	_physicsModel->SetTransform(_transform);
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

