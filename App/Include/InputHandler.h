#ifndef ASTEROIDS_INPUTHANDLER_H
#define ASTEROIDS_INPUTHANDLER_H

#include "Command.h"
#include <memory>
#include <vector>

#include "Player.h"

class InputHandler
{
public:
    InputHandler();
    [[nodiscard]] std::vector<Juno::Command*> HandleInput() const;
private:
    std::unique_ptr<ThrustCommand> m_ButtonW;
    std::unique_ptr<ThrustCommand> m_ButtonS;
    std::unique_ptr<TurnCommand> m_ButtonA;
    std::unique_ptr<TurnCommand> m_ButtonD;
    std::unique_ptr<ThrustCommand> m_NoThrust;
    std::unique_ptr<TurnCommand> m_NoTurn;
};

#endif //ASTEROIDS_INPUTHANDLER_H