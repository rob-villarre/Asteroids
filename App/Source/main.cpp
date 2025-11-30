#include "Application.h"
#include "TestLayer.h"

int main()
{
    const Juno::ApplicationSpecification appSpec{
        Juno::WindowSpecification{800, 600, "Juno Application"}
    };

    Juno::Application app(appSpec);

    app.PushLayer(std::make_unique<TestLayer>(app, "Initial Test Layer"));
    app.Run();


    return 0;
}