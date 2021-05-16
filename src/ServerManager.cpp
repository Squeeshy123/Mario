#include "ServerManager.h"

SDL_Window* window;

RenderServer* Server::ServerManager::render_server;

RenderServer* Server::ServerManager::get_render_server()
{
    return render_server;
}

Server::ServerManager::ServerManager(SDL_Window* window)
{
    //render_server = new RenderServer;
    Server::ServerManager::render_server = new RenderServer(window);

}
