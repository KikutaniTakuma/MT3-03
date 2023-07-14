#pragma once
#include <vector>
#include "Math/Vector3/Vector3.h"
#include "Math/Mat4x4/Mat4x4.h"
#include "Sphere/Sphere.h"

class Bezier {
public:
	Bezier();
	Bezier(uint32_t division);
	Bezier(const Bezier&) = default;
	Bezier(Bezier&&) noexcept = default;
	~Bezier() = default;

public:
	Bezier& operator=(const Bezier&) = default;
	Bezier& operator=(Bezier&&) noexcept = default;


public:
	void Update();

	void Draw(const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color);

private:
	const uint32_t division;

	std::vector<Vector3> positions;

	float t;
	float tSpd;

	Sphere pibotPoint;
	Sphere startPoint;
	Sphere endPoint;
public:
	Vector3 pibot;
	Vector3 start;
	Vector3 end;
};