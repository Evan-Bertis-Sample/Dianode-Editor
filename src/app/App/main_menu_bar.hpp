#pragma once

#include <imgui.h>

#include <map>
#include <iostream>

#include "Core/Application.hpp"
#include "Core/Layer.hpp"

class MainMenuBar : public App::Layer {
 public:
  MainMenuBar() {}

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