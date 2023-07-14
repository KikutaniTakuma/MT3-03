#include "Bone.h"
#include "Novice.h"

Bone::Bone():
	scale(Vector3::identity),
	rotate(),
	translation(),
	parent(nullptr),
	sphere(),
	worldAffin()
{
	sphere.radius = 0.1f;
}

void Bone::Update() {
	worldAffin.HoriAffin(scale, rotate, translation);

	if (parent) {
		worldAffin *= parent->worldAffin;
	}

	sphere.translation = { worldAffin[3][0],worldAffin[3][1],worldAffin[3][2] };

	sphere.Update();
}

void Bone::Draw(const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color) {
	auto vpvpMat = viewProjectionMatrix * viewPortMatrix;
	auto screenPos = sphere.translation * vpvpMat;
	if (parent) {
		auto screenParentPos = parent->sphere.translation * vpvpMat;
		Novice::DrawLine(static_cast<int>(screenPos.x), static_cast<int>(screenPos.y), static_cast<int>(screenParentPos.x), static_cast<int>(screenParentPos.y), 0xffffffff);
	}
	else {

	}


	sphere.Draw(viewProjectionMatrix, viewPortMatrix, color);
}