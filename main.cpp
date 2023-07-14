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

	auto camera = std::make_unique<Camera>();
	assert(camera);

	camera->pos = { 0.0f,1.9f, -6.49f };
	camera->rotate = { 0.26f,0.0f,0.0f };
	camera->scale = { 1.0f,1.0f,1.0f };

	auto grid = std::make_unique<Grid>();
	grid->scalar = { 4.0f,0.0f,4.0f };

	int gridDivision = 10;

	auto shoulder = std::make_unique<Bone>();
	shoulder->translation = { 0.2f,1.0f,0.0f };
	shoulder->rotate = { 0.0f,0.0f,-6.8f };
	auto elbow = std::make_unique<Bone>();
	elbow->translation = { 0.4f,0.0f,0.0f };
	elbow->rotate = { 0.0f,0.0f,-1.4f };
	elbow->Setparent(shoulder.get());
	auto hand = std::make_unique<Bone>();
	hand->translation = { 0.3f,1.0f,0.0f };
	hand->rotate = { 0.0f,0.0f,0.0f };
	hand->Setparent(elbow.get());


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
		ImGui::DragFloat3("Camera pos", &camera->pos.x, 0.01f);
		ImGui::DragFloat3("Camera rotate", &camera->rotate.x, 0.01f);
		ImGui::DragFloat3("Camera scale", &camera->scale.x, 0.01f);
		ImGui::DragFloat3("Camera moveRotate", &camera->moveRotate.x, 0.01f);
		ImGui::End();

		ImGui::Begin("Bone");
		ImGui::DragFloat3("Shoulder translation", &shoulder->translation.x, 0.01f);
		ImGui::DragFloat3("Shoulder rotate", &shoulder->rotate.x, 0.01f);
		ImGui::DragFloat3("Shoulder scale", &shoulder->scale.x, 0.01f);
		ImGui::DragFloat3("Elbow translation", &elbow->translation.x, 0.01f);
		ImGui::DragFloat3("Elbowrotate", & elbow->rotate.x, 0.01f);
		ImGui::DragFloat3("Elbowscale", &elbow->scale.x, 0.01f);
		ImGui::DragFloat3("Hand translation", &hand->translation.x, 0.01f);
		ImGui::DragFloat3("Handrotate", & hand->rotate.x, 0.01f);
		ImGui::DragFloat3("Handscale", &hand->scale.x, 0.01f);
		ImGui::End();

		grid->Update(gridDivision);

		shoulder->Update();
		elbow->Update();
		hand->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		camera->Update();

		grid->Draw(camera->getViewProjectionMatrix(), camera->getViewPortMatrix(), 0xaaaaaaff);

		shoulder->Draw(camera->getViewProjectionMatrix(), camera->getViewPortMatrix(), RED);
		elbow->Draw(camera->getViewProjectionMatrix(), camera->getViewPortMatrix(),GREEN);
		hand->Draw(camera->getViewProjectionMatrix(), camera->getViewPortMatrix(), BLUE);
		
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
