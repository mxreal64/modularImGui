#!/usr/bin/env bash
set -e 

IMGUI_DIR="./imgui"
FLAGS="-std=c++26 -O3 -fmodules-ts -I${IMGUI_DIR} -I${IMGUI_DIR}/backends"

# Create build folder if it doesn't exist
mkdir -p build

#  THE FIX: Bootstrap the C++ Standard library module if it's missing
if [ ! -f "gcm.cache/std.gcm" ]; then
    echo " Bootstrapping 'import std;' for GCC (This takes a few seconds)..."
    # -fsearch-include-path instructs GCC to find and build its internal bits/std.cc
    g++ $FLAGS -fsearch-include-path -c bits/std.cc
fi

echo " Step 1: Compiling raw legacy ImGui source files..."
g++ $FLAGS -c ${IMGUI_DIR}/imgui.cpp -o build/imgui.o
g++ $FLAGS -c ${IMGUI_DIR}/imgui_draw.cpp -o build/imgui_draw.o
g++ $FLAGS -c ${IMGUI_DIR}/imgui_widgets.cpp -o build/imgui_widgets.o
g++ $FLAGS -c ${IMGUI_DIR}/imgui_tables.cpp -o build/imgui_tables.o
g++ $FLAGS -c ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp -o build/imgui_impl_glfw.o
g++ $FLAGS -c ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp -o build/imgui_impl_opengl3.o

echo " Step 2: Compiling the C++ module interface file..."
g++ $FLAGS -c modernImGui.cppm -o build/modularImGui.o

echo " Step 3: Packing everything into a clean static library..."
ar rcs build/modularImGui.a build/*.o

echo " Success! Your pure GCC-built library is at build/modularImGui.a"
