#pragma once
#include "Structures.h"
class Appearance
{
private:
	Geometry _geometry;
	Material _material;
	ID3D11ShaderResourceView* _textureRV;
public:
	Appearance();
	Appearance(Geometry geo, Material mat) : _geometry(geo), _material(mat) {}

	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* GetTextureRV() const { return _textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }
	Geometry GetGeometryData() const { return _geometry; }
	Material GetMaterial() const { return _material; }

	void Draw(ID3D11DeviceContext* pImmediateContext);
};

