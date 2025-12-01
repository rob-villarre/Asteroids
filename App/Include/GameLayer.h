#ifndef ASTEROIDS_GAMELAYER_H
#define ASTEROIDS_GAMELAYER_H

#include "Layer.h"
#include "Application.h"
#include "InputHandler.h"
#include "Player.h"

class GameLayer final : public Juno::Layer
{
public:
    explicit GameLayer(Juno::Application& app);
    ~GameLayer() override = default;

    void OnUpdate(float deltaTime) override;
    void OnRender() override;

private:
    Juno::Application& m_App;
    Player m_Player;
    InputHandler m_InputHandler;
};


#endif //ASTEROIDS_GAMELAYER_H