#pragma once

#include <imgui.h>

#include <map>
#include <iostream>
#include "Core/Layer.hpp"

class MainMenuBar : public App::Layer {
 public:
  MainMenuBar() {}

  void OnUIRender(bool applicationMinimized) override {
    if (applicationMinimized)
      return;

    ImGui::DockSpaceOverViewport();

    if (ImGui::BeginMainMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Exit", "Cmd+Q")) {
            std::cout << "Exit" << std::endl;
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