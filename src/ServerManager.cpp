#include "ServerManager.h"

RenderServer* Server::ServerManager::render_server = new RenderServer();

RenderServer* Server::ServerManager::get_render_server()
{
    return render_server;
}

Server::ServerManager::ServerManager()
{
    //render_server = new RenderServer;
}
