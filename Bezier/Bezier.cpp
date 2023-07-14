#include "Bezier.h"
#include "Novice.h"
#include <algorithm>

Bezier::Bezier() :
	division(8),
	positions(0),
	pibot(),
	start(),
	end(),
	t(0.0f),
	tSpd(1.0f / static_cast<float>(division)),
	pibotPoint(),
	startPoint(),
	endPoint()
{
	pibotPoint.radius = 0.01f;
	startPoint.radius = 0.01f;
	endPoint.radius = 0.01f;
}

Bezier::Bezier(uint32_t division) :
	division(division),
	positions(0),
	pibot(),
	start(),
	end(),
	t(0.0f),
	tSpd(1.0f / static_cast<float>(division)),
	pibotPoint(),
	startPoint(),
	endPoint()
{
	pibotPoint.radius = 0.01f;
	startPoint.radius = 0.01f;
	endPoint.radius = 0.01f;
}

void Bezier::Update() {
	positions.clear();
	t = 0.0f;

	for (uint32_t i = 0; i <= division; i++) {
		Vector3 p0p1 = Lerp(start, pibot, t);
		Vector3 p1p2 = Lerp(pibot, end, t);
		Vector3 p = Lerp(p0p1, p1p2, t);
		positions.push_back(p);
		t += tSpd;
	}

	pibotPoint.translation = pibot;
	startPoint.translation = start;
	endPoint.translation = end;

	pibotPoint.Update();
	startPoint.Update();
	endPoint.Update();
}

void Bezier::Draw(const Mat4x4& viewProjectionMatrix, const Mat4x4& viewPortMatrix, uint32_t color) {
	auto vpvpMat = viewProjectionMatrix * viewPortMatrix;

	auto screenPos = positions;

	for (auto& i : screenPos) {
		i *= vpvpMat;
	}

	auto nextItr = screenPos.begin();
	nextItr++;

	for (auto i = screenPos.begin(); nextItr != screenPos.end();i++, nextItr++) {
		Novice::DrawLine(static_cast<int>(i->x), static_cast<int>(i->y), static_cast<int>(nextItr->x), static_cast<int>(nextItr->y), color);
	}

	pibotPoint.Draw(viewProjectionMatrix, viewPortMatrix, 0xff);
	startPoint.Draw(viewProjectionMatrix, viewPortMatrix, 0xff);
	endPoint.Draw(viewProjectionMatrix, viewPortMatrix, 0xff);
}