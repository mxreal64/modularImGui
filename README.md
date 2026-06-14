# modularImGui 

a zero-overhead c++26 named module gateway for **dear imgui**. it does a brutal macroexorcism on toxic preprocessor pollution, stops global namespace leaks, and forces explicit symbol serialization. 

built for systems engineers who want pure modern c++ with zero-magic build scripts.

## why
traditional dear imgui forces absolute macro garbage and header clutter into your clean code. this repo acts as a strict compilation firewall, giving you faster incremental rebuilds and a pristine global namespace.

### before (legacy header soup)
```cpp
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
// congrats, your global namespace is now trashed
```

### after (pristine c++26)
```cpp
import modularImGui;

int main() {
    imgui::createcontext();
    imgui::backend::imgui_impl_glfw_initforopengl(window, true);
    // 0% macro leakage. zero abstraction penalty.
}
```

## setup & build (gcc 14+ / arch)

1. grab the code:
```bash
git clone https://github.com/mxreal64/modularImGui.git
cd modularImGui
```

2. grab dependencies:
```bash
sudo pacman -s glfw-x11
```

3. screw bloated build systems. just run the bare-metal shell script:
```bash
chmod +x build.sh
./build.sh
```

4. compile your application against the static library:
```bash
g++ -std=c++26 -fmodules-ts main.cpp build/libmodularImGui.a -lglfw -lgl -o app
```

## license

copyright mxreal64, 2026

licensed under GNU GPLv3, more info at <https://gnu.org>
