#ifndef _VEC_2D_H_
#define _VEC_2D_H_

#include <vector>

namespace Math {
	
	struct struct_vec2d {
		int x;
		int y;
	};

	typedef struct_vec2d Vec2D;
	typedef std::vector<Vec2D> Vec2DVector;

	static Vec2D &operator+ (Vec2D *ret, Vec2D const& v) {
		ret->x += v.x;
		ret->y += v.y;
		return *ret;
	}

	static Vec2D &operator- (Vec2D *ret, Vec2D const& v) {
		ret->x -= v.x;
		ret->y -= v.y;
		return *ret;
	}
}

#endif // !_VEC_2D_H_
