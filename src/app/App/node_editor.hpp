#pragma once

#include <imgui.h>
#include <imnodes.h>

#include <iostream>
#include <map>

#include "Core/Application.hpp"
#include "Core/Layer.hpp"

class NodeEditor : public App::Layer {
 public:
  NodeEditor() {}

  void OnAttach() {
    ImNodes::CreateContext();
  }

  void OnDetach() {
    ImNodes::DestroyContext();
  }

  void OnUIRender(App::Application &app) {
	ImGui::Begin("Dialogue Node Editor", NULL, ImGuiWindowFlags_MenuBar);
    const int hardcoded_node_id = 1;

    ImNodes::BeginNodeEditor();

    ImNodes::BeginNode(hardcoded_node_id);
    ImGui::Dummy(ImVec2(80.0f, 45.0f));
    ImNodes::EndNode();

    ImNodes::EndNodeEditor();

	ImGui::End();
  }
};