#ifndef DEBRY_Vector2T_H
#define DEBRY_Vector2T_H

#include <cmath>

namespace debry {
	template <typename ctype>
	struct Vector2T {
		ctype x;
		ctype y;

		Vector2T() : Vector2T{ 0.0, 0.0 } { }
		Vector2T(ctype x, ctype y) : x{ x }, y{ y } { }
		explicit Vector2T(ctype s) : Vector2T{ s, s } { }

		Vector2T operator+(const Vector2T& other) const {
			return Vector2T{ this->x + other.x,this->y + other.y };
		}

		void operator+=(const Vector2T& other) {
			this->x += other.x;
			this->y += other.y;
		}

		Vector2T operator-(const Vector2T& other) const {
			return Vector2T{ this->x - other.x,this->y - other.y };
		}

		void operator-=(const Vector2T& other) {
			this->x -= other.x;
			this->y -= other.y;
		}

		Vector2T operator*(const ctype& scalar) const {
			return Vector2T{ x * scalar, y * scalar };
		}

		void operator*=(const ctype& scalar) {
			this->x *= scalar;
			this->y *= scalar;
		}

		void Zero() { x = y = 0.0; }
		void Negate() { this->x = -x; this->y = -y; }

		[[nodiscard]] ctype Magnitude() const {
			return ctype{ (x * x) + (y * y) };
		}

		[[nodiscard]] ctype MagnitudeSqrt() const {
			return ctype{ std::sqrt(Magnitude()) };
		}

		void Normalize() {
			ctype norm = MagnitudeSqrt();
			if (norm > 0) {
				x *= 1.0f / norm;
				y *= 1.0f / norm;
			}
			else {
				this->Zero();
			}
		}

	};
	/* common types */
	typedef Vector2T<float> Vector2f;
	typedef Vector2T<int> Vector2i;
	typedef Vector2T<unsigned int> Vector2ui;
}

#endif
