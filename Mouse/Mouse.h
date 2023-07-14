#pragma once
#include <memory>
#include "Math/Vector3/Vector3.h"

class Mouse {
public:
	enum class Button : short {
	LEFT_BUTTON,
	RIGHT_BUTTON,
	MIDDLE_BUTTON,
	BACK_SIDE_BUTTON, 
	FORWARD_SIDE_BUTTON,

	MOUSE_BUTTON_NUMBER  
	};

private:
	static bool isButton[static_cast<short>(Button::MOUSE_BUTTON_NUMBER)];
	static bool isPreButton[static_cast<short>(Button::MOUSE_BUTTON_NUMBER)];

	static int wheel;

	static void CheckPreButton();

	static void SetPos();

	static void Wheel();

public:
	static int x;
	static int y;

	static void Input();

	static bool Pushed(Button buttonNumber);

	static bool LongPush(Button buttonNumber);

	static bool Releaseed(Button buttonNumber);

	static void Draw();

	static Vector3 GetWorldPos(const Mat4x4& vpvpMat);

	static bool IsMouseRange(const Vector3& pos, float radius, const Mat4x4& vpvpMat);

	///
	/// getter
	///
	
	static inline int getWheel() {
		return wheel;
	}
};
