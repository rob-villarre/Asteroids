#include "Application.h"
#include "GameLayer.h"

int main()
{
    const Juno::ApplicationSpecification appSpec{
        Juno::WindowSpecification{800, 600, "Juno Application"}
    };

    Juno::Application app(appSpec);

    app.PushLayer(std::make_unique<GameLayer>(app));
    app.Run();


    return 0;
}