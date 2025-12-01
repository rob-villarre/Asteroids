#include "InputHandler.h"

#include <raylib.h>
#include <raylib-cpp/Keyboard.hpp>

InputHandler::InputHandler()
{
    m_ButtonA = std::make_unique<TurnCommand>(-180.0f);
    m_ButtonD = std::make_unique<TurnCommand>(180.0f);
    m_ButtonW = std::make_unique<ThrustCommand>(150.0f);
    m_ButtonS = std::make_unique<ThrustCommand>(-150.0f);
    m_NoThrust = std::make_unique<ThrustCommand>(0.0f);
    m_NoTurn = std::make_unique<TurnCommand>(0.0f);
}

std::vector<Juno::Command*> InputHandler::HandleInput() const
{
    std::vector<Juno::Command*> commands;
    bool hasThrustInput = false;
    bool hasTurnInput = false;

    if (raylib::Keyboard::IsKeyDown(KEY_A))
    {
        commands.push_back(m_ButtonA.get());
        hasTurnInput = true;
    }
    if (raylib::Keyboard::IsKeyDown(KEY_D))
    {
        commands.push_back(m_ButtonD.get());
        hasTurnInput = true;
    }
    if (raylib::Keyboard::IsKeyDown(KEY_W))
    {
        commands.push_back(m_ButtonW.get());
        hasThrustInput = true;
    }
    if (raylib::Keyboard::IsKeyDown(KEY_S))
    {
        commands.push_back(m_ButtonS.get());
        hasThrustInput = true;
    }

    if (!hasThrustInput)
    {
        commands.push_back(m_NoThrust.get());
    }
    if (!hasTurnInput)
    {
        commands.push_back(m_NoTurn.get());
    }

    return commands;
}