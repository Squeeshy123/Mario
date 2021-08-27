#pragma once
#include <stdint.h>
struct Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};
struct Vec2 {
	float x = 0;
	float y = 0;

	Vec2(const float& x, const float& y) {
		this->x = x;
		this->y = y;
	}
	Vec2() = default;

	Vec2 operator+(const Vec2& b) {
		return Vec2(this->x + b.x, this->y + b.y);
	}
	Vec2 operator-(const Vec2& b) {
		return Vec2(this->x - b.x, this->y - b.y);
	}
};
struct Rect {
	Vec2 location;
	Vec2 size;

	Rect(const float& x, const float& y, const float& w, const float& h) {
		this->location.x = x;
		this->location.y = y;

		this->size.x = w;
		this->size.y = h;
	}
};

inline Vec2 operator*( Vec2 const& lhs, float const& rhs ){
	return Vec2{lhs.x * rhs, lhs.y * rhs};
}
	
/*
Vec2 get_UR(Rect r) {
	return Vec2{r.x + r.w, r.y + r.h};
}

static inline Vec2 get_UL(Rect r) {
	return Vec2{ r.x - r.w, r.y + r.h };
}

static inline Vec2 get_BR(Rect r) {
	return Vec2{ r.x + r.w, r.y - r.h };
}

static inline Vec2 get_BL(Rect r) {
	return Vec2{ r.x - r.w, r.y - r.h };
}

static inline Rect* intersects(Rect r1, Rect r2){
	Vec2 r1_UR = get_UR(r1);
	Vec2 r1_UL = get_UL(r1);
	Vec2 r1_BR = get_BR(r1);
	Vec2 r1_BL = get_BL(r1);

	Vec2 r2_UR = get_UR(r2);
	Vec2 r2_UL = get_UL(r2);
	Vec2 r2_BR = get_BR(r2);
	Vec2 r2_BL = get_BL(r2);

	// Find whether points overlap here
	return 0;
	
}
*/
template<typename T>
constexpr const T& clamp(const T& val, const T& lo, const T& hi){
	if (val > hi)      { return hi; }
	else if (val < lo) { return lo; }
	else               { return val;}
}
	

