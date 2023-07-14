#include "Camera.h"

Camera::Camera():
	viewMatrix(),
	projectionMatrix(),
	viewPortMatirx(),
	viewProjection(),
	windowWidth(1280),
	windowHeight(720),
	fovY(0.45f),
	nearClip(0.1f),
	farClip(100.0f),
	left(0.0f),
	right(0.0f),
	minDepth(0.0f),
	maxDepth(1.0f)
{}

void Camera::Update() {
	viewMatrix.HoriAffin(scale, rotate, pos);
	viewMatrix *= HoriMakeMatrixAffin(Vector3(1.0f, 1.0f, 1.0f), moveRotate, Vector3());
	viewMatrix.Inverse();

	projectionMatrix.HoriPerspectiveFov(fovY, static_cast<float>(windowWidth) / static_cast<float>(windowHeight), nearClip, farClip);

	viewPortMatirx.HoriViewPort(left, right, static_cast<float>(windowWidth), static_cast<float>(windowHeight), minDepth, maxDepth);

	viewProjection = viewMatrix * projectionMatrix;
}