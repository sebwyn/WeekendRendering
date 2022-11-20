#include <iostream>

#include "rendering/window.hpp"
#include "rendering/render_api.hpp"

using namespace std;

int main(int argc, const char *argv[]) {
    cout << "Hello, World!" << endl;
    
    Window window(800, 600);
    //make a backend here
    RenderApi* api = create_render_api(window);
    //cout << api << endl;
    cout << api->info() << endl;

    while(!window.closed()){
        window.update();
        api->draw();
    }
    
    delete api;
    return 0;
}
