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

struct Line {
	Vec2 p1;
	Vec2 p2;
	Line() = default;
	Line(Vec2 p_p1, Vec2 p_p2) {
		p1 = p_p1;
		p2 = p_p2;
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
	Line* as_lines() {
		Line lines[4] = { 
		Line( get_UR(*this), get_UL(*this) ),
		Line( get_BR(*this), get_BL(*this) ),
		Line( get_UR(*this), get_BR(*this) ),
		Line( get_UL(*this), get_BL(*this) ) 
		};

		return lines;
	}
};

struct HitResult {
	bool valid_hit;
	Vec2 location;
	HitResult(bool is_hit, Vec2 loc) {
		location = loc;
		valid_hit = is_hit;
	}
	HitResult() = default;
};

inline Vec2 operator*( Vec2 const& lhs, float const& rhs ){
	return Vec2{lhs.x * rhs, lhs.y * rhs};
}


static HitResult line_intersects(Line& l1, Line& l2)
{
	
	float denominator = ((l1.p2.x - l1.p1.x) * (l2.p2.y - l2.p1.y)) - ((l1.p2.y - l1.p1.y) * (l2.p2.x - l2.p1.x));
	float numerator1 = ((l1.p1.y - l2.p1.y) * (l2.p2.x - l2.p1.x)) - ((l1.p1.x - l2.p1.x) * (l2.p2.y - l2.p1.y));
	float numerator2 = ((l1.p1.y - l2.p1.y) * (l1.p2.x - l1.p1.x)) - ((l1.p1.x - l2.p1.x) * (l1.p2.y - l1.p1.y));

	HitResult hr;
	if (denominator == 0) hr.valid_hit = numerator1 == 0 && numerator2 == 0;

	float r = numerator1 / denominator;
	float s = numerator2 / denominator;
	hr = HitResult((r >= 0 && r <= 1) && (s >= 0 && s <= 1), Vec2());

	return hr;
}

// Get upper right point
static inline Vec2 get_UR(Rect r) {
	return Vec2{r.location.x + r.size.x, r.location.y + r.size.y};
}
// Get opper left point
static inline Vec2 get_UL(Rect r) {
	return Vec2{ r.location.x - r.size.x, r.location.y + r.size.y };
}
// Get lower right point
static inline Vec2 get_BR(Rect r) {
	return Vec2{ r.location.x + r.size.x, r.location.y - r.size.y };
}
// Get lower left point
static inline Vec2 get_BL(Rect r) {
	return Vec2{ r.location.x - r.size.x, r.location.y - r.size.y };
}

static inline bool rect_intersects_rect(Rect r1, Rect r2){
	Line r1_upper = Line(get_UR(r1), get_UL(r1));
	Line r1_lower = Line(get_BR(r1), get_BL(r1));
	Line r1_right = Line(get_UR(r1), get_BL(r1));
	Line r1_left =	Line(get_UL(r1), get_BL(r1));

	Line r2_upper = Line(get_UR(r2), get_UL(r2));
	Line r2_lower = Line(get_BR(r2), get_BL(r2));
	Line r2_left = Line(get_BR(r2), get_BL(r2));
	Line r2_right = Line(get_BR(r2), get_BL(r2));

	Line r1_lines[4] = r1.as_lines();

	// Find whether points overlap here
	for()
	return false;
	
}
static inline bool rect_intersects_line(Rect r1, Line r2) {
	Line r1_upper = Line(get_UR(r1), get_UL(r1));
	Line r1_lower = Line(get_BR(r1), get_BL(r1));
	Line r1_right = Line(get_UR(r1), get_BL(r1));
	Line r1_left = Line(get_UL(r1), get_BL(r1));


	// Find whether points overlap here
	line_intersects()
	return HitResult();

}

template<typename T>
constexpr const T& clamp(const T& val, const T& lo, const T& hi){
	if (val > hi)      { return hi; }
	else if (val < lo) { return lo; }
	else               { return val;}
}
	

