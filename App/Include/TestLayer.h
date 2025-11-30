#ifndef ASTEROIDS_TESTLAYER_H
#define ASTEROIDS_TESTLAYER_H

#include "Application.h"
#include "Layer.h"

class TestLayer final : public Juno::Layer
{
public:
    explicit TestLayer(Juno::Application& app, const std::string& name) : Layer(name), m_App(app) {}
    ~TestLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;

    void OnUpdate() override;

private:
    Juno::Application& m_App;
};

#endif //ASTEROIDS_TESTLAYER_H