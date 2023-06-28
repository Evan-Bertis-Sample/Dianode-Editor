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
    if (app.State.minimized)
      return;

    ImGui::DockSpaceOverViewport();

    if (ImGui::BeginMainMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Exit", "Cmd+Q")) {
          app.stop();
        }
        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu("View")) {
        ImGui::MenuItem("Some Panel", nullptr, true);
        ImGui::EndMenu();
      }

      ImGui::EndMainMenuBar();
    }
  }
};