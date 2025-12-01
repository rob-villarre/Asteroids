#include "Player.h"

#include <algorithm>
#include <cmath>

Player::Player(const raylib::Vector2 position)
    : m_Position(position),
      m_Velocity{0.0f, 0.0f},
      m_Speed{0.0f},
      m_TurnRate{0.0f},
      m_Thrust{0.0f},
      m_Heading{0.0f},
      m_MaxSpeed{240.0f},
      m_Drag{80.0f},
      m_Radius{25.0f},
      m_mass{300.0f}
{
}

void Player::Thrust(float const deltaTime, float const thrust)
{
  // bound check thrust
  m_Thrust = std::clamp(thrust, m_ThrustRange[0], m_ThrustRange[1]);

  m_Speed += m_Thrust * deltaTime;

  m_Speed = std::clamp(m_Speed, -m_MaxSpeed, m_MaxSpeed);
}

void Player::Turn(float const deltaTime, float const turnRate)
{
  // bound check turn rate
  m_TurnRate = std::clamp(turnRate, m_TurnRateRange[0], m_TurnRateRange[1]);

  m_Heading += m_TurnRate * deltaTime;

  m_Heading = std::fmod(m_Heading, 360.0f);
  if (m_Heading < 0) {
    m_Heading += 360.0;
  }
}

void Player::Drag(float const deltaTime)
{
  if(const float drag = m_Drag * deltaTime; drag > std::abs(m_Speed)) {
    m_Speed = 0.0;
  } else {
    m_Speed -= drag * std::copysign(1.0f, m_Speed);
  }
}

void Player::OnUpdate(const float deltaTime)
{
  Drag(deltaTime);

  // use speed magnitude to get velocity vector
  const float headingRad = DEG2RAD * m_Heading;
  m_Velocity = raylib::Vector2{m_Speed * std::sin(headingRad), m_Speed * -std::cos(headingRad)};

  // update position based on velocity
  m_Position = raylib::Vector2{m_Position.x + m_Velocity.x * deltaTime, m_Position.y + m_Velocity.y * deltaTime};

  const auto screenWidth = static_cast<float>(GetScreenWidth());
  const auto screenHeight = static_cast<float>(GetScreenHeight());
  constexpr float wrapThreshold = 20.0f * 0.7f;

  // Wrap horizontally
  if (m_Position.x < -wrapThreshold) {
    m_Position.x = static_cast<float>(screenWidth);
  } else if (m_Position.x > screenWidth + wrapThreshold) {
    m_Position.x = 0;
  }

  // Wrap vertically
  if (m_Position.y < -wrapThreshold) {
    m_Position.y = static_cast<float>(screenHeight);
  } else if (m_Position.y > screenHeight + wrapThreshold) {
    m_Position.y = 0;
  }
}

void Player::OnRender()
{
  DrawRectanglePro(
      raylib::Rectangle{m_Position.x, m_Position.y, 40, 40},
      raylib::Vector2{20, 20},
      m_Heading,
      RED
  );
}
