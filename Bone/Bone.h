#pragma once

#include "Math/Vector3/Vector3.h"
#include "Math/Mat4x4/Mat4x4.h"
#include "Sphere/Sphere.h"

class Bone {
public:
	Bone();
	Bone(const Bone&) = default;
	Bone(Bone&&) noexcept = default;
	~Bone() = default;

public:
	void Update();
	void Draw(const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color);

public:
	Vector3 scale;
	Vector3 rotate;
	Vector3 translation;

private:
	Mat4x4 worldAffin;

	Bone* parent;

	Sphere sphere;
	
public:
	inline void Setparent(Bone* const parent_) {
		parent = parent_;
	}
};