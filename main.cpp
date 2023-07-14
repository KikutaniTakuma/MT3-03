#include <Novice.h>
#include <array>
#include <string>
#include <memory>
#include <cassert>
#include <imgui.h>
#include <numbers>
#include "Math/Vector3/Vector3.h"
#include "Math/Mat4x4/Mat4x4.h"
#include "Camera/Camera.h"
#include "Sphere/Sphere.h"
#include "Grid/Grid.h"
#include "Mouse/Mouse.h"
#include "Model/MyModel.h"
#include "Bezier/Bezier.h"
#include "Bone/Bone.h"

const std::string kWindowTitle{ "LE2A_04_キクタニ_タクマ_タイトル" };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle.c_str(), 1280, 720);

	// キー入力結果を受け取る箱
	std::array<char, 256> keys = { 0 };
	std::array<char, 256> preKeys = { 0 };

	Vector3 a{ 0.2f,1.0f,0.0f };
	Vector3 b{ 2.4f,3.1f,1.2f };
	Vector3 c = a + b;
	Vector3 d = a - b;
	Vector3 e = a * 2.4f;
	Vector3 rotate{ 0.4f,1.43f,-0.8f };
	Mat4x4 rotateXMat = HoriMakeMatrixRotateX(rotate.x);
	Mat4x4 rotateYMat = HoriMakeMatrixRotateY(rotate.y);
	Mat4x4 rotateZMat = HoriMakeMatrixRotateZ(rotate.z);
	auto rotateMat = rotateXMat * rotateYMat * rotateZMat;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();


		// キー入力を受け取る
		std::copy(keys.begin(), keys.end(), preKeys.begin());
		Novice::GetHitKeyStateAll(keys.data());
		Mouse::Input();

		///
		/// ↓更新処理ここから
		///


		ImGui::Begin("Window");
		ImGui::Text("c:%f, %f, %f", c.x, c.y, c.z);
		ImGui::Text("d:%f, %f, %f", d.x, d.y, d.z);
		ImGui::Text("e:%f, %f, %f", e.x, e.y, e.z);

		ImGui::Text(
			"matrix:\n%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n%f, %f, %f, %f\n",
			rotateMat[0][0], rotateMat[0][1], rotateMat[0][2], rotateMat[0][3],
			rotateMat[1][0], rotateMat[1][1], rotateMat[1][2], rotateMat[1][3],
			rotateMat[2][0], rotateMat[2][1], rotateMat[2][2], rotateMat[2][3],
			rotateMat[3][0], rotateMat[3][1], rotateMat[3][2], rotateMat[3][3]
		);
		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
