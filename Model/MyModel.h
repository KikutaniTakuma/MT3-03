#pragma once
#include <vector>
#include <string> 
#include "Math/Vector3/Vector3.h"
#include "Math/Mat4x4/Mat4x4.h"

class MyModel {
public:
	MyModel();
	~MyModel() = default;

	MyModel(const MyModel&) = default;
	MyModel(MyModel&&) = default;
	MyModel& operator=(const MyModel&) = default;

public:
	void LoadObj(const std::string& fileName);

	void WorldMatUpdate();

	bool IsCollision(const MyModel& model) const;
	bool IsCollision(const class Sphere& sphere) const;
	bool IsCollision(const struct Segment& segment) const;

	void Draw(const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color);

public:
	Vector3 pos;
	Vector3 scale;
	Vector3 rotation;

private:
	Mat4x4 worldMat;

private:
	std::vector<Vector3> vertex;
	std::vector<uint32_t> index;

	Vector3 maxLocalPos;
	Vector3 minLocalPos;
};