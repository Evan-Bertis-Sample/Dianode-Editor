#pragma once

namespace App {

class Application;

class Layer {
 public:
    virtual ~Layer() = default;

    // Called when the layer is attached to the application
    virtual void OnAttach() {}

    // Called when the layer is detached to application, most often on application shutdown
    virtual void OnDetatch() {}

    // Called on every update loop of the application, before rendering
    virtual void OnUpdate(float dt) {}

    // Called on every update loop of the application, after rendering
    virtual void OnUIRender(App::Application &app) {}
};

}  // namespace App