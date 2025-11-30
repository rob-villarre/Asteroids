#include "TestLayer.h"

#include <raylib-cpp/Functions.hpp>
#include <raylib-cpp/Keyboard.hpp>

void TestLayer::OnUpdate()
{
    raylib::DrawText(m_Name, 10, 10, 20, BLACK);

    if (raylib::Keyboard::IsKeyDown(KEY_UP)) {
        m_App.TransitionToLayerDeferred(this, std::make_unique<TestLayer>(m_App, "Up key Pressed Layer"));
    } else if (raylib::Keyboard::IsKeyDown(KEY_DOWN)) {
        m_App.TransitionToLayerDeferred(this, std::make_unique<TestLayer>(m_App, "Down key Pressed Layer"));
    }
}

void TestLayer::OnAttach()
{
    // Called when the layer is attached to the layer stack
}

void TestLayer::OnDetach()
{
    // Called when the layer is detached from the layer stack
}