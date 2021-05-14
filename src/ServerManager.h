#pragma once


#include "RenderServer.h"


namespace Server {
	class ServerManager
	{
		private:
			static RenderServer* render_server;

		public:
			static RenderServer* get_render_server();

			ServerManager();
	};
}

