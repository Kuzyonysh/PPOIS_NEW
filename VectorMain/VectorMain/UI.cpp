
#include "Vector.h"
#include "UI.h"
#include <iostream>

void UI(istream& in, ostream& out) {
    setlocale(LC_ALL, "ru");
    Vector a, b;
    out << "Введите вектор a: "; in >> a;
    out << "Введите вектор b: "; in >> b;
    int choice;

    do {
        out << "\nВыберите операцию:\n"
            << "1. Вывод конца вектора;\n"
            << "2. Длина вектора;\n"
            << "3. Сложение векторов;\n"
            << "4. Вычитание векторов;\n"
            << "5. Векторное произведение;\n"
            << "6. Произведение вектора на число;\n"
            << "7. Деление векторов;\n"
            << "8. Косинус между векторами;\n"
            << "9. Сравнение векторов;\n"
            << "10. Выход из программы;\n";

        in >> choice;

        switch (choice) {
        case 1:
            out << "a = " << a << "\n";
            out << "b = " << b << "\n"; break;
        case 2:
            out << "Длина вектора a: " << a.Length()
                << "\nДлина вектора b: " << b.Length() << "\n"; break;
        case 3:
            out << "a + b = " << (a + b) << "\n";
            out << "a += b : " << (a += b) << "\n"; break;
        case 4:
            out << "a - b = " << (a - b) << "\n";
            out << "a -= b : " << (a -= b) << "\n"; break;
        case 5:
            out << "a * b  = " << (a * b) << "\n";
            out << "a *= b : " << (a *= b) << "\n"; break;
        case 6: {
            double digit;
            out << "Введите число: ";
            in >> digit;
            out << "a * " << digit << " = " << (a * digit) << "\n";
            out << "a *= " << digit << " : " << (a *= digit) << "\n"; break;
        }
        case 7:
            out << "a / b  = " << (a / b) << "\n";
            out << "a /= b : " << (a /= b) << "\n"; break;
        case 8:
            out << "cos(a, b) = " << (a ^ b) << "\n"; break;
        case 9:
            out << "Сравнение длин:\n";
            out << "a > b ? " << (a > b ? "Да" : "Нет") << "\n";
            out << "a < b ? " << (a < b ? "Да" : "Нет") << "\n";
            out << "a >= b ? " << (a >= b ? "Да" : "Нет") << "\n";
            out << "a <= b ? " << (a <= b ? "Да" : "Нет") << "\n";
            out << "a==b ?  " << (a == b ? "Да" : "Нет") << "\n";
            out << "a!=b ? " << (a != b ? "Да" : "Нет") << "\n"; break;
        case 10:
            out << "Выход из программы...\n"; break;
        default:
            out << "Некорректный выбор!\n";
        }
    } while (choice != 10);
}
