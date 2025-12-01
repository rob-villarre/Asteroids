#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <raylib-cpp/raylib-cpp.hpp>

#include "IEntity.h"
#include "Command.h"

class Player final : public IEntity
{
public:
    explicit Player(raylib::Vector2 position);
    ~Player() override = default;

    void OnUpdate(float deltaTime) override;
    void OnRender() override;

    void Thrust(float deltaTime, float thrust);
    void Turn(float deltaTime, float turnRate);

    void SetThrust(const float thrust) { m_Thrust = thrust; }
    void SetTurnRate(const float turnRate) { m_TurnRate = turnRate; }

private:
    void Drag(float deltaTime);

    raylib::Vector2 m_Position;
    raylib::Vector2 m_Velocity;
    float m_Speed;
    float m_TurnRate;
    float m_Thrust;
    float m_Heading;

    const std::vector<float> m_ThrustRange{-480.0f, 480.0f};
    const std::vector<float> m_TurnRateRange{-180.0f, 180.0f};
    const float m_MaxSpeed;
    const float m_Drag;
    const float m_Radius;
    const float m_mass;
};

class ThrustCommand final : public Juno::Command
{
public:

    explicit ThrustCommand(const float thrust) : m_Thrust(thrust)
    {
    }

    void Execute(IEntity& actor, float const deltaTime) override
    {
        if (auto* player = dynamic_cast<Player*>(&actor))
        {
            player->Thrust(deltaTime, m_Thrust);
        }
    }
private:
    float m_Thrust;
};

class TurnCommand final : public Juno::Command
{
public:
    explicit TurnCommand(const float turnRate) : m_TurnRate(turnRate)
    {
    }

    void Execute(IEntity& actor, float const deltaTime) override
    {
        if (auto* player = dynamic_cast<Player*>(&actor))
        {
            player->Turn(deltaTime, m_TurnRate);
        }
    }

private:
    float m_TurnRate;
};

#endif //ASTEROIDS_PLAYER_H