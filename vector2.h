#ifndef Debry_Vector2T_H
#define Debry_Vector2T_H

#include "math.h"

namespace debry {
	template <class ctype> class Vector2;
	/* common types */
	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2ui;

	template <class ctype>
	class Vector2 {
		ctype x;
		ctype y;
	public:
		Vector2(ctype x, ctype y) : x{ x }, y{ y } { }
		Vector2(ctype s) : Vector2{ s,s } { }

		ctype getX() const { return this->x; }
		ctype getY() const { return this->y; }
		
		Vector2* setX(const ctype x) { this->x = x; return this; }
		Vector2* setY(const ctype y) { this->y = y; return this; }

		Vector2 getVector() const { return Vector2{ x,y }; }

		Vector2 operator+(const Vector2& other) const {
			return Vector2{ this->x + other.x,this->y + other.y };
		}

		void operator+=(const Vector2& other) {
			this->x += other.x;
			this->y += other.y;
		}
		
		Vector2 operator-(const Vector2& other) const {
			return Vector2{ this->x - other.x,this->y - other.y };
		}

		void operator-=(const Vector2& other) {
			this->x -= other.x;
			this->y -= other.y;
		}

		Vector2 operator*(const ctype& scalar) const {
			return Vector2{ x * scalar, y * scalar };
		}

		void operator*=(const ctype& scalar) {
			this->x *= scalar;
			this->y *= scalar;
		}

		void Clear() { x = y = (ctype)0; }
		void Negate() { this->x = -x; this->y = -y; }

		/* Euclidean Norm */
		ctype Magnitude() const {
			return ctype{ (x * x) + (y * y) };
		}
		
		ctype MagnitudeSqrt() const {
			return ctype{ sqrtf(Magnitude()) };
		}
		
		void Normalize() {
			ctype norm = MagnitudeSqrt();
			if (norm > 0) {
				x *= 1.0f / norm;
				y *= 1.0f / norm;
			}
			else {
				this->Clear();
			}
		}

	};

}

#endif
