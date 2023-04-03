#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance, bool gravity, float mass) : _type(type), _appearance(appearance), _gravity(gravity), _mass(mass)
{	
	_transform = new Transform();

	_parent = nullptr;
	_transform->SetScale(Vector3(1.0f, 1.0f, 1.0f));
	_appearance->SetTextureRV(nullptr);

	_particleModel = new ParticleModel(_transform);
	_particleModel->SetMass(_mass);
	if (gravity)
		_particleModel->SetGravity(true);
}

GameObject::~GameObject()
{
	_appearance->SetTextureRV(nullptr);
	_appearance = nullptr;
	_parent = nullptr;
	_transform = nullptr;
}

void GameObject::Update(float t)
{
	_particleModel->Update(t);

	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_transform->GetScale().x, _transform->GetScale().y, _transform->GetScale().z);
	XMMATRIX rotation = XMMatrixRotationX(_transform->GetRotation().x) * XMMatrixRotationY(_transform->GetRotation().y) * XMMatrixRotationZ(_transform->GetRotation().z);
	XMMATRIX translation = XMMatrixTranslation(_transform->GetPosition().x, _transform->GetPosition().y, _transform->GetPosition().z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	Geometry* temp = &_appearance->GetGeometryData();

	pImmediateContext->IASetVertexBuffers(0, 1, &temp->vertexBuffer, &temp->vertexBufferStride, &temp->vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(temp->indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(temp->numberOfIndices, 0, 0);
}
