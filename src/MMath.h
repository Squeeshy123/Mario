#pragma once

namespace MMath {

	struct Vec2 {
		float x;
		float y;
	};
	struct Rect {
		float x;
		float y;
		float h;
		float w;
	};

	Vec2 get_UR(Rect r) {
		return Vec2{r.x + r.w, r.y + r.h};
	}

	Vec2 get_UL(Rect r) {
		return Vec2{ r.x - r.w, r.y + r.h };
	}

	Vec2 get_BR(Rect r) {
		return Vec2{ r.x + r.w, r.y - r.h };
	}

	Vec2 get_BL(Rect r) {
		return Vec2{ r.x - r.w, r.y - r.h };
	}

	Rect* intersects(Rect r1, Rect r2){
		Vec2 r1_UR = get_UR(r1);
		Vec2 r1_UL = get_UL(r1);
		Vec2 r1_BR = get_BR(r1);
		Vec2 r1_BR = get_BL(r1);

		Vec2 r2_UR = get_UR(r2);
		Vec2 r2_UL = get_UL(r2);
		Vec2 r2_BR = get_BR(r2);
		Vec2 r2_BR = get_BL(r2);

		// Find whether points overlap here
	}
	template<typename T>
	constexpr const T& clamp(const T& val, const T& lo, const T& hi){
		if (val > hi) { return hi; }
		else if (val < lo) { return lo; }
		else { return val; }
	}
}