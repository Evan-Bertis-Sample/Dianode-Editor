/*
 * Copyright (c) 2022 Martin Helmut Fieber <info@martin-fieber.se>
 * Modifications made by Evan Bertis-Sample (2023)
 */

#pragma once

#include <SDL.h>

#include <memory>
#include <string>
#include <vector>

#include "Core/Window.hpp"
#include "Layer.hpp"

namespace App {

enum class ExitStatus : int { SUCCESS = 0, FAILURE = 1 };

class Application {
 public:
  struct State {
    bool running{false};
    bool minimized{false};
  };
  State State{};

  explicit Application(const std::string& title);
  ~Application();

  Application(const Application&) = delete;
  Application(Application&&) = delete;
  Application& operator=(Application other) = delete;
  Application& operator=(Application&& other) = delete;

  ExitStatus run();
  void stop();

  void on_event(const SDL_WindowEvent& event);
  void on_resize(const SDL_WindowEvent& event);
  void on_minimize();
  void on_shown();
  void on_close();

  // * Layer methods added by Evan Bertis-sample
  void push_layer(const std::shared_ptr<Layer>& layerPtr) {
    this->m_layer_stack.emplace_back(layerPtr);
    layerPtr->OnAttach();
  }

  template <typename T>
  void push_layer(T layer) {
    static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not a subclass of Layer!");
    auto layerPtr = std::make_shared<T>(layer);
    this->m_layer_stack.emplace_back(layerPtr);
    layerPtr->OnAttach();
  }

 private:
  void set_theme() const;

  ExitStatus m_exit_status{ExitStatus::SUCCESS};
  std::shared_ptr<Window> m_window{nullptr};

  std::vector<std::shared_ptr<Layer>> m_layer_stack;
};

}  // namespace App
