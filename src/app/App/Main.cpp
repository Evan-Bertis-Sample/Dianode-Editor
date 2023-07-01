/*
 * Copyright (c) 2022 Martin Helmut Fieber <info@martin-fieber.se>
 */

#define SDL_MAIN_HANDLED

#include <dialogue_driver/fact.h>

#include <iostream>

#include "Core/Application.hpp"
#include "Core/Instrumentor.hpp"
#include "Core/Log.hpp"
#include "main_menu_bar.hpp"
#include "node_editor.hpp"

int main() {
  try {
    APP_PROFILE_BEGIN_SESSION_WITH_FILE("App", "profile.json");

    {
      APP_PROFILE_SCOPE("Test scope");
      App::Application app{"Dianode"};
      MainMenuBar bar;
      NodeEditor ne;
      app.push_layer(bar);
      app.push_layer(ne);
      app.run();
    }

    APP_PROFILE_END_SESSION();
  } catch (std::exception& e) {
    APP_ERROR("Main process terminated with: {}", e.what());
  }

  return 0;
}
