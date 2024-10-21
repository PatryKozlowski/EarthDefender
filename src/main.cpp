#include "Application.hpp"
#include "GameConfig.hpp"

int main()
{
    Application *app = new Application(g_WindowConfig.WIDTH, g_WindowConfig.HEIGHT, g_WindowConfig.TITLE, g_WindowConfig.STYLE, g_WindowConfig.TARGET_FPS);

    app->Run();

    delete app;
}