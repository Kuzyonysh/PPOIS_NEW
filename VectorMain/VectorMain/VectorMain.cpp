/**
 * @file Vector.cpp
 * @brief Реализация методов класса Vector
 */

#include "Header.h"
#include <cmath>

Vector::Vector(int x, int y, int z) :x(x), y(y), z(z) {}

Vector::Vector() {
    x = y = z = 0;
}

int Vector::GetX() const { return x; }
int Vector::GetY() const { return y; }
int Vector::GetZ() const { return z; }

double Vector::Length() const {
    return sqrt(x * x + y * y + z * z);
}

ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

istream& operator>>(istream& in, Vector& v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector& Vector::operator+=(const Vector& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector& Vector::operator-=(const Vector& other) {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
}

Vector Vector::operator*(const Vector& other) const {
    return Vector(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector& Vector::operator*=(const Vector& other) {
    int x_new = y * other.z - z * other.y;
    int y_new = z * other.x - x * other.z;
    int z_new = x * other.y - y * other.x;
    x = x_new; y = y_new; z = z_new;
    return *this;
}

Vector Vector::operator*(double digit) const {
    return Vector(x * digit, y * digit, z * digit);
}

Vector& Vector::operator*=(double digit) {
    x *= digit; y *= digit; z *= digit;
    return *this;
}

Vector Vector::operator/(const Vector& other)const
{
    if (other.x == 0 || other.y == 0 || other.z == 0) {
        cerr << "Ошибка: деление на вектор с нулевой координатой!\n";
        return Vector(0, 0, 0);
    }
    return Vector(x / other.x, y / other.y, z / other.z);
}

Vector& Vector:: operator/=(const Vector& other)
{
    if (other.x == 0 || other.y == 0 || other.z == 0) {
        cerr << "Ошибка: деление на вектор с нулевой координатой!\n";
        x = y = z = 0;
        return *this;
    }
    x /= other.x; y /= other.y; z /= other.z;
    return *this;
}

double Vector::operator^(const Vector& other) const {
    if (Length() == 0 || other.Length() == 0)
    {
        cerr << "Ошибка: невозможно найти косинус между нулевыми веторами!\n";
        return 0;
    }
    return (x * other.x + y * other.y + z * other.z) / (Length() * other.Length());
}

bool Vector::operator>(const Vector& other) const { return Length() > other.Length(); }
bool Vector::operator>=(const Vector& other) const { return Length() >= other.Length(); }
bool Vector::operator<(const Vector& other) const { return Length() < other.Length(); }
bool Vector::operator<=(const Vector& other) const { return Length() <= other.Length(); }
bool Vector::operator==(const Vector& other)const { return x == other.x && y == other.y && z == other.z; }
bool Vector::operator!=(const Vector& other)const { return x != other.x || y != other.y || z != other.z; }