#ifndef DEBRY_VECTOR2T_H
#define DEBRY_VECTOR2T_H

#include <cmath>

namespace debry {

	template <typename ctype> struct Vector2T;
	/* common types */
	using Vector2f = Vector2T<float>;
	using Vector2i = Vector2T<int>;
	
	template <typename ctype>
	struct Vector2T {
		ctype x;
		ctype y;

		Vector2T() : Vector2T{ 0, 0 } { }
		Vector2T(ctype x, ctype y) : x{ x }, y{ y } { }
		explicit Vector2T(ctype s) : Vector2T{ s, s } { }

		inline void set(const ctype x, const ctype y) { 
			this->x = x; this->y = y; 
		}
		
		inline void clear() {
			this->x = this->y = 0;
		}

		inline void negate() {
			this->x = -x; this->y = -y;
		}
		
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

		Vector2T operator*(const ctype scalar) const {
			return Vector2T{ x * scalar, y * scalar };
		}

		void operator*=(const ctype scalar) {
			this->x *= scalar;
			this->y *= scalar;
		}

		[[nodiscard]] ctype Magnitude() const {
			return ctype{ (x * x) + (y * y) };
		}

		[[nodiscard]] ctype MagnitudeSqrt() const {
			return ctype{ std::sqrt((x * x) + (y * y)) };
		}

		[[nodiscard]] Vector2T NormalizedVector() const {
			ctype norm = MagnitudeSqrt();
			if (norm > 0) {
				norm = 1 / norm;
				return Vector2T{ x * norm, y * norm };
			}
			return Vector2T{ 0, 0 };
		}

		void NormalizeIt() {
			ctype norm = MagnitudeSqrt();
			if (norm > 0) {
				x *= 1.0f / norm;
				y *= 1.0f / norm;
			}
			else {
				this->clear();
			}
		}

	};
}

#endif
