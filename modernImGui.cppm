module;
// 1. All raw headers safely sandboxed in the global fragment
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

export module modernImGui;

import std;

// 2. MANUAL EXPORT PURVIEW
// We explicitly point to the true global namespace symbols using 'using' aliases
export namespace ImGui {
    // ------------------------------------------------------------------------
    // 1. CORE LIFECYCLE & CONTEXT
    // ------------------------------------------------------------------------
    using ::ImGuiContext;
    using ::ImGui::CreateContext;
    using ::ImGui::DestroyContext;
    using ::ImGui::GetCurrentContext;
    using ::ImGui::SetCurrentContext;
    using ::ImGui::NewFrame;
    using ::ImGui::Render;
    using ::ImGui::GetDrawData;
    using ::ImGui::ShowDemoWindow;

    // ------------------------------------------------------------------------
    // 2. WINDOW CONTROLS
    // ------------------------------------------------------------------------
    using ::ImGui::Begin;
    using ::ImGui::End;
    using ::ImGui::BeginChild;
    using ::ImGui::EndChild;

    // ------------------------------------------------------------------------
    // 3. BASE BUTTONS & CLICKS
    // ------------------------------------------------------------------------
    using ::ImGui::Button;
    using ::ImGui::SmallButton;
    using ::ImGui::InvisibleButton;
    using ::ImGui::ArrowButton;
    using ::ImGui::Checkbox;
    using ::ImGui::RadioButton;

    // ------------------------------------------------------------------------
    // 4. DATA COMPONENT INPUTS
    // ------------------------------------------------------------------------
    using ::ImGui::InputText;
    using ::ImGui::InputTextMultiline;
    using ::ImGui::InputInt;
    using ::ImGui::InputFloat;
    using ::ImGui::InputDouble;

    // ------------------------------------------------------------------------
    // 5. SLIDERS & DRAG CONTROLS
    // ------------------------------------------------------------------------
    using ::ImGui::SliderFloat;
    using ::ImGui::SliderFloat2;
    using ::ImGui::SliderFloat3;
    using ::ImGui::SliderInt;
    using ::ImGui::DragFloat;
    using ::ImGui::DragInt;

    // ------------------------------------------------------------------------
    // 6. COMPLEX CHOOSE BOXES
    // ------------------------------------------------------------------------
    using ::ImGui::BeginCombo;
    using ::ImGui::EndCombo;
    using ::ImGui::Combo;
    using ::ImGui::ListBox;

    // ------------------------------------------------------------------------
    // 7. MULTIMEDIA & VISUAL DRAWING
    // ------------------------------------------------------------------------
    using ::ImGui::Text;
    using ::ImGui::TextColored;
    using ::ImGui::TextWrapped;
    using ::ImGui::Image;
    using ::ImGui::ImageButton;
    using ::ImGui::ProgressBar;
    using ::ImGui::Bullet;

    // ------------------------------------------------------------------------
    // 8. GRAPHICAL LAYOUT MECHANICS
    // ------------------------------------------------------------------------
    using ::ImGui::Separator;
    using ::ImGui::SameLine;
    using ::ImGui::NewLine;
    using ::ImGui::Spacing;
    using ::ImGui::Dummy;
    using ::ImGui::Indent;
    using ::ImGui::Unindent;
    using ::ImGui::BeginGroup;
    using ::ImGui::EndGroup;

    // ------------------------------------------------------------------------
    // 9. TREE STRUCTURES & STRUCTURAL TABS
    // ------------------------------------------------------------------------
    using ::ImGui::TreeNode;
    using ::ImGui::TreePop;
    using ::ImGui::CollapsingHeader;
    using ::ImGui::BeginTabBar;
    using ::ImGui::EndTabBar;
    using ::ImGui::BeginTabItem;
    using ::ImGui::EndTabItem;

    // ------------------------------------------------------------------------
    // 10. GRID ARCHITECTURE & HOVER POPUPS
    // ------------------------------------------------------------------------
    using ::ImGui::BeginTable;
    using ::ImGui::EndTable;
    using ::ImGui::TableNextRow;
    using ::ImGui::TableNextColumn;
    using ::ImGui::BeginTooltip;
    using ::ImGui::EndTooltip;
    using ::ImGui::OpenPopup;
    using ::ImGui::BeginPopup;
    using ::ImGui::EndPopup;

    // ------------------------------------------------------------------------
    // 11. CONFIGURATION FLAGS (CLEAN NAMESPACE MAPPING)
    // ------------------------------------------------------------------------
    using WindowFlags = ::ImGuiWindowFlags;
    using ::ImGuiWindowFlags_None;
    using ::ImGuiWindowFlags_NoTitleBar;
    using ::ImGuiWindowFlags_NoMove;
    using ::ImGuiWindowFlags_NoResize;
    using ::ImGuiWindowFlags_NoScrollbar;
}

// 3. MANUAL BACKEND EXPORTS
export namespace ImGui::Backend {
    using ::ImGui_ImplGlfw_InitForOpenGL;
    using ::ImGui_ImplGlfw_NewFrame;
    using ::ImGui_ImplGlfw_Shutdown;
    
    using ::ImGui_ImplOpenGL3_Init;
    using ::ImGui_ImplOpenGL3_NewFrame;
    using ::ImGui_ImplOpenGL3_RenderDrawData;
    using ::ImGui_ImplOpenGL3_Shutdown;
}

// 4. CORE STRUCTS & TYPES
export {
    using ::ImVec2;
    using ::ImVec4;
    using ::ImGuiID;
    using ::ImTextureID;
    using ImGuiTableColumnIdx = short;
    using ImGuiTableDrawChannelIdx = unsigned char;
}
