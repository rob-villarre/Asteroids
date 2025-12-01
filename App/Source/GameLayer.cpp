#include "GameLayer.h"

GameLayer::GameLayer(Juno::Application& app)
    : Layer("Game Layer"), m_App(app), m_Player(raylib::Vector2{50.0f, 50.0f})
{
}

void GameLayer::OnUpdate(const float deltaTime)
{
    for (const auto command : m_InputHandler.HandleInput())
    {
        command->Execute(m_Player, deltaTime);
    }

    m_Player.OnUpdate(deltaTime);
}

void GameLayer::OnRender()
{
    m_App.GetWindow().ClearBackground(raylib::Color::Black());
    m_Player.OnRender();
}