#pragma once
#include "Math/Vector3/Vector3.h"
#include "Math/Mat4x4/Mat4x4.h"

class Camera {
public:
	Camera();


public:
	void Update();

	inline Mat4x4 getViewProjectionMatrix() const {
		return viewProjection;
	}

	inline Mat4x4 getViewPortMatrix() const {
		return viewPortMatirx;
	}

private:
	Mat4x4 viewMatrix;
	Mat4x4 projectionMatrix;
	Mat4x4 viewPortMatirx;
	Mat4x4 viewProjection;

public:
	int32_t windowWidth;
	int32_t windowHeight;

	Vector3 pos;
	Vector3 scale;
	Vector3 rotate;
	Vector3 moveRotate;

	float fovY;
	float nearClip;
	float farClip;

	float left;
	float right;
	float minDepth;
	float maxDepth;
};