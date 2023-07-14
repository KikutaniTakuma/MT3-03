#pragma once
#include <vector>
#include "Math/Vector3/Vector3.h"
#include "Math/Mat4x4/Mat4x4.h"

class Grid {
public:
	Grid();
	~Grid() {}

public:
	void Update(int32_t division);
	void Draw(const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color);

public:
	Vector3 scalar;
	Vector3 rotate;
	Vector3 translate;

private:
	std::vector<float> localPosX;
	std::vector<float> localPosZ;

	Mat4x4 worldMat;
};

struct Plane {
	Vector3 normal;
	float distance;
};

bool IsCollisioPlaneSegment(const Plane& plane, const Segment& segment);

void DrawPlane(const Plane& plane, const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color);

bool IsCollisionTriangle(const Vector3& pos1, const Vector3& pos2, const Vector3& pos3, const Segment& segment);

void DrawTriangle(const Vector3& pos1, const Vector3& pos2, const Vector3& pos3, const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color);