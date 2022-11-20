#pragma once

#include "window.hpp"

#include <string>
using namespace std;

class RenderApi {
  public:
    virtual ~RenderApi() = default;   
    virtual string info() = 0;
};

RenderApi* create_render_api(const Window& window);
