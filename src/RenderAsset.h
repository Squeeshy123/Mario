#pragma once
#include <string>

#include "RenderServer.h"

struct Rect {
	int x;
	int y;
	int w;
	int h;
};

class RenderAsset
{
	private:
		std::string spr_path;

		Rect r;
	
	public:
		RenderAsset(std::string path, int p_x, int p_y, int p_width, int p_height) {
			spr_path = path;

			r.x = p_x; r.y = p_y; r.w = p_width; r.h = p_height;
		}

		void set_rect(int p_x, int p_y, int p_width, int p_height) {
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

