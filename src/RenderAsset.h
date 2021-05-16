#pragma once
#include <string>

#include "MMath.h"

#include "RenderServer.h"
#include "ServerManager.h"

enum class RenderType {
	Texture,
	Shape
};

using namespace MMath;

class RenderAsset
{
	private:
		std::string spr_path;

		Rect r;
	
	public:
		RenderType render_type;

		RenderAsset(RenderServer* render_server, RenderType p_render_type, std::string path, float p_x, float p_y, float p_width, float p_height) {
			render_type = p_render_type;

			spr_path = path;

			r.x = p_x; r.y = p_y; r.w = p_width; r.h = p_height;

			switch (render_type)
			{
			case RenderType::Texture:
				render_server->load_texture(path);
				break;
			case RenderType::Shape:
				break;
			default:
				break;
			}
		}

		void set_rect(float p_x, float p_y, float p_width, float p_height) {
			r.x = p_x; r.y = p_y; r.w = p_width; r.h = p_height;
		}

		Rect get_rect() {
			return r;
		}

		void set_path(std::string path) {
			spr_path = path;
		}

		std::string get_path() {
			return spr_path;
		}
};

