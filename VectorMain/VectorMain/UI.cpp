
#include "Vector.h"
#include "UI.h"
#include <iostream>

void UI(istream& in, ostream& out) {
    setlocale(LC_ALL, "ru");
    Vector a, b;
    out << "������� ������ a: "; in >> a;
    out << "������� ������ b: "; in >> b;
    int choice;

    do {
        out << "\n�������� ��������:\n"
            << "1. ����� ����� �������;\n"
            << "2. ����� �������;\n"
            << "3. �������� ��������;\n"
            << "4. ��������� ��������;\n"
            << "5. ��������� ������������;\n"
            << "6. ������������ ������� �� �����;\n"
            << "7. ������� ��������;\n"
            << "8. ������� ����� ���������;\n"
            << "9. ��������� ��������;\n"
            << "10. ����� �� ���������;\n";

        in >> choice;

        switch (choice) {
        case 1:
            out << "a = " << a << "\n";
            out << "b = " << b << "\n"; break;
        case 2:
            out << "����� ������� a: " << a.Length()
                << "\n����� ������� b: " << b.Length() << "\n"; break;
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
            out << "������� �����: ";
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
            out << "��������� ����:\n";
            out << "a > b ? " << (a > b ? "��" : "���") << "\n";
            out << "a < b ? " << (a < b ? "��" : "���") << "\n";
            out << "a >= b ? " << (a >= b ? "��" : "���") << "\n";
            out << "a <= b ? " << (a <= b ? "��" : "���") << "\n";
            out << "a==b ?  " << (a == b ? "��" : "���") << "\n";
            out << "a!=b ? " << (a != b ? "��" : "���") << "\n"; break;
        case 10:
            out << "����� �� ���������...\n"; break;
        default:
            out << "������������ �����!\n";
        }
    } while (choice != 10);
}
