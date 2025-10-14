/**
 * @file Vector.h
 * @brief Заголовочный файл с объявлением класса Vector для работы с векторами.
 * @author Darya
 * @date 2025
 */
#pragma once
#include <iostream>
using namespace std;
/**
 * @class Vector
 * @brief Класс для работы с векторами.
 *
 * Класс реализует операции:
 * - сложение, вычитание
 * - умножение вектора на число и векторное произведение
 * - вычисление длины
 * - вычисление косинуса между векторами
 * - сравнение длин векторов
 * - ввод и вывод через потоки
 */
class Vector
{
private:
    int x, y, z;
public:
    /**
    * @brief Конструктор инициализации
    * @param x координата X
    * @param y координата Y
    * @param z координата Z
    */
    Vector(int x, int y, int z);
    /**
     * @brief Конструктор по умолчанию (инициализация нулевым вектором).
     */
    Vector();

    int GetX() const;
    int GetY() const;
    int GetZ() const;
    /**
    * @brief Вычисление длины вектора
    * @return длина (модуль) вектора
    */
    double Length() const;

    friend ostream& operator<<(ostream& out, const Vector& v);
    /**
     * @brief Оператор ввода из потока
     * @param in поток ввода
     * @param v вектор
     * @return поток ввода
     */
    friend istream& operator>>(istream& in, Vector& v);

    Vector operator+(const Vector& other) const;
    Vector& operator+=(const Vector& other);
    Vector operator-(const Vector& other) const;
    Vector& operator-=(const Vector& other);
    Vector operator*(const Vector& other) const;
    Vector& operator*=(const Vector& other);
    Vector operator*(double digit) const;
    Vector& operator*=(double digit);
    Vector operator/(const Vector& other) const;
    Vector& operator/=(const Vector& other);
    double operator^(const Vector& other) const;

    bool operator>(const Vector& other) const;
    bool operator>=(const Vector& other) const;
    bool operator<(const Vector& other) const;
    bool operator<=(const Vector& other) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

};
