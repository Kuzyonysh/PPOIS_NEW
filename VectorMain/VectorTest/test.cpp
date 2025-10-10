#include <gtest/gtest.h>
#include "D:\Projects\VectorMain\VectorMain\Header.h"
#include <windows.h>
#include <iostream>
void UI(std::istream& in, std::ostream& out);
using namespace std;



int main(int argc, char** argv) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    setlocale(LC_ALL, "ru");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// �������� ������������ � ������� Get
TEST(VectorTest, ConstructorAndGetters) {
    Vector v(1, 2, 3);
    EXPECT_EQ(v.GetX(), 1);
    EXPECT_EQ(v.GetY(), 2);
    EXPECT_EQ(v.GetZ(), 3);

    Vector zero;
    EXPECT_EQ(zero.GetX(), 0);
    EXPECT_EQ(zero.GetY(), 0);
    EXPECT_EQ(zero.GetZ(), 0);
}
// �������� ������ ������
TEST(VectorTest, StreamOutput) {
    Vector v(1, 2, 3);
    std::ostringstream out;
    out << v;
    EXPECT_EQ(out.str(), "(1, 2, 3)");
}
// �������� ������ �����
TEST(VectorTest, StreamInput) {
    Vector v;
    std::istringstream in("4 5 6");
    in >> v;
    EXPECT_EQ(v, Vector(4, 5, 6));
}
// �������� �� ������� ����� ��������� ���������
TEST(VectorTest, CosineBothZeroVectors) {
    Vector zero1(0, 0, 0);
    Vector zero2(0, 0, 0);
    EXPECT_DOUBLE_EQ(zero1 ^ zero2, 0.0);
}

// �������� ����� �������
TEST(VectorTest, Length) {
    Vector v(3, 4, 0);
    EXPECT_DOUBLE_EQ(v.Length(), 5.0);
}

// �������� �������� � ���������
TEST(VectorTest, AdditionAndSubtraction) {
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);

    EXPECT_EQ(a + b, Vector(5, 7, 9));
    a += b;
    EXPECT_EQ(a, Vector(5, 7, 9));

    EXPECT_EQ(a - b, Vector(1, 2, 3));
    a -= b;
    EXPECT_EQ(a, Vector(1, 2, 3));
}

// �������� ��������� (��������� ������������ � �� �����)
TEST(VectorTest, Multiplication) {
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);

    EXPECT_EQ(a * b, Vector(-3, 6, -3)); // ��������� ������������
    EXPECT_EQ(a * 2.0, Vector(2, 4, 6)); // ��������� �� �����

    a *= b;
    EXPECT_EQ(a, Vector(-3, 6, -3));
}

// �������� �������
TEST(VectorTest, Division) {
    Vector a(8, 9, 10);
    Vector b(2, 3, 5);

    EXPECT_EQ(a / b, Vector(4, 3, 2));
    a /= b;
    EXPECT_EQ(a, Vector(4, 3, 2));

    // ������� �� ������ � ������� �����������
    Vector zero(0, 1, 1);
    Vector res = a / zero;
    EXPECT_EQ(res, Vector(0, 0, 0));
}

// �������� �������� ����� ���������
TEST(VectorTest, Cosine) {
    Vector a(1, 0, 0);
    Vector b(0, 1, 0);
    EXPECT_DOUBLE_EQ(a ^ b, 0.0); // ����������������

    Vector c(1, 0, 0);
    Vector d(1, 0, 0);
    EXPECT_DOUBLE_EQ(c ^ d, 1.0); // ������������

    Vector zero(0, 0, 0);
    EXPECT_DOUBLE_EQ(c ^ zero, 0.0); // ������� ������
}

// �������� ���������� ���������
TEST(VectorTest, Comparison) {
    Vector a(3, 4, 0); // ����� 5
    Vector b(0, 0, 0); // ����� 0

    EXPECT_TRUE(a > b);
    EXPECT_TRUE(a >= b);
    EXPECT_FALSE(a < b);
    EXPECT_FALSE(a <= b);

    Vector c(3, 4, 0);
    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a != c);
}
// ������� �� ������ � ������� ����������� �� ��������� ����
TEST(VectorTest, DivisionByZeroCoordinate) {
    Vector a(10, 20, 30);

    Vector zeroX(0, 5, 5);
    Vector zeroY(5, 0, 5);
    Vector zeroZ(5, 5, 0);

    EXPECT_EQ(a / zeroX, Vector(0, 0, 0));
    EXPECT_EQ(a / zeroY, Vector(0, 0, 0));
    EXPECT_EQ(a / zeroZ, Vector(0, 0, 0));

    Vector b(1, 1, 1);
    b /= zeroX;
    EXPECT_EQ(b, Vector(0, 0, 0));
}

// ��������� ������������ � ������� ��������
TEST(VectorTest, CrossProductWithZeroVector) {
    Vector v1(1, 2, 3);
    Vector zero(0, 0, 0);

    EXPECT_EQ(v1 * zero, Vector(0, 0, 0));
    Vector tmp = v1;
    tmp *= zero;
    EXPECT_EQ(tmp, Vector(0, 0, 0));
}

// ��������� �� ���� � ������������� �����
TEST(VectorTest, ScalarMultiplicationEdgeCases) {
    Vector v(1, -2, 3);

    EXPECT_EQ(v * 0.0, Vector(0, 0, 0));
    EXPECT_EQ(v * -2.0, Vector(-2, 4, -6));

    v *= -3.0;
    EXPECT_EQ(v, Vector(-3, 6, -9));
}

// ��������� �������� ���������� �����
TEST(VectorTest, ComparisonSameLengthDifferentCoords) {
    Vector a(3, 4, 0); // ����� 5
    Vector b(0, -5, 0); // ����� 5

    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a >= b);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}

// ���������� ����������
TEST(VectorTest, CompoundOperators) {
    Vector a(1, 1, 1);
    Vector b(2, 2, 2);

    a += b;
    EXPECT_EQ(a, Vector(3, 3, 3));
    a -= b;
    EXPECT_EQ(a, Vector(1, 1, 1));

    Vector c(1, 0, 0);
    Vector d(0, 1, 0);
    c *= d; // ��������� ������������
    EXPECT_EQ(c, Vector(0, 0, 1));
}

// �������� Length() ��� �������� �������
TEST(VectorTest, LengthZeroVector) {
    Vector zero;
    EXPECT_DOUBLE_EQ(zero.Length(), 0.0);
}

// ������� ��� �������� � ������ ����������
TEST(VectorTest, CosineDifferentVectors) {
    Vector a(1, 0, 0);
    Vector b(-1, 0, 0);
    EXPECT_DOUBLE_EQ(a ^ b, -1.0);

    Vector c(1, 1, 0);
    Vector d(1, 0, 0);
    EXPECT_NEAR(c ^ d, 0.70710678, 1e-6); // cos(45�)
}


// ������� ��� ������� � ��������������� ��������
TEST(VectorTest, CosineEdgeCases) {
    Vector zero(0, 0, 0);
    Vector v1(1, 0, 0);
    Vector v2(-1, 0, 0);

    EXPECT_DOUBLE_EQ(zero ^ v1, 0.0);
    EXPECT_DOUBLE_EQ(v1 ^ zero, 0.0);
    EXPECT_DOUBLE_EQ(v1 ^ v2, -1.0);
}

// ��������� ��������� � ������� �������� � �������������� ������������
TEST(VectorTest, CrossProductEdgeCases) {
    Vector zero(0, 0, 0);
    Vector v1(1, -2, 3);

    EXPECT_EQ(v1 * zero, Vector(0, 0, 0));
    EXPECT_EQ(zero * v1, Vector(0, 0, 0));

    Vector v2(-1, 2, -3);
    EXPECT_EQ(v1 * v2, Vector(0, 0, 0)); // ������������ ���������������
}

// �������� ����� � ����������� �����
TEST(VectorTest, StreamInputInvalid) {
    Vector v;
    std::istringstream in1("1 2"); // ������ 3 �����
    in1 >> v;
    // ���������� ������ �������� �������� ������������ ��� 0
    EXPECT_EQ(v.GetX(), 1);
    EXPECT_EQ(v.GetY(), 2);

    Vector v2;
    std::istringstream in2(""); // ������ �����
    in2 >> v2;
    EXPECT_EQ(v2, Vector(0, 0, 0));
}

// �������� ��������� ������ �����, �� ������ ���������
TEST(VectorTest, ComparisonEqualLengthDifferentCoords2) {
    Vector a(3, 4, 0); // ����� 5
    Vector b(0, 0, 5); // ����� 5

    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a >= b);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}

// �������� �������� � ��������� � �������� � �������������� ������������
TEST(VectorTest, AddSubtractZeroNegative) {
    Vector a(1, -2, 3);
    Vector zero(0, 0, 0);
    Vector b(-1, 2, -3);

    EXPECT_EQ(a + zero, a);
    EXPECT_EQ(a + b, Vector(0, 0, 0));
    EXPECT_EQ(a - b, Vector(2, -4, 6));
}
// �������� ������� �� ������������� ����������
TEST(VectorTest, DivisionNegativeComponents) {
    Vector a(10, -20, 30);
    Vector b(-2, 4, -5);

    EXPECT_EQ(a / b, Vector(-5, -5, -6));
    a /= b;
    EXPECT_EQ(a, Vector(-5, -5, -6));
}



// �������� �������� � �������������� ������������
TEST(VectorTest, CosineNegativeVectors) {
    Vector a(-1, 0, 0);
    Vector b(0, -1, 0);
    Vector c(1, 1, 0);

    EXPECT_DOUBLE_EQ(a ^ b, 0.0); // ����������������
    EXPECT_DOUBLE_EQ(a ^ c, -0.7071067811865475); // ���� 135�
}

// �������� ����� � ������� �������
TEST(VectorTest, StreamInputExtraNumbers) {
    Vector v;
    std::istringstream in("1 2 3 4 5");
    in >> v;
    EXPECT_EQ(v, Vector(1, 2, 3)); // ������������ ������ �����
}

// �������� ����� � ��������� � ����������
TEST(VectorTest, StreamInputSpacesTabs) {
    Vector v;
    std::istringstream in("7\t8  9");
    in >> v;
    EXPECT_EQ(v, Vector(7, 8, 9));
}

// �������� ��������� � ������ ������ �� ���������������� ������������
TEST(VectorTest, ComparisonEqualLengthOppositeCoords) {
    Vector a(3, 4, 0); // ����� 5
    Vector b(-3, -4, 0); // ����� 5

    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a >= b);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}

// �������� ��������� �� 0
TEST(VectorTest, MultiplicationByZero) {
    Vector v(1, 2, 3);
    EXPECT_EQ(v * 0.0, Vector(0, 0, 0));
    v *= 0.0;
    EXPECT_EQ(v, Vector(0, 0, 0));
}
// �������� ������� �� ������ � ����� ������� �����������
TEST(VectorTest, DivisionWithSingleZero) {
    Vector a(6, 9, 12);
    Vector b(3, 0, 2);
    Vector res = a / b;
    EXPECT_EQ(res, Vector(0, 0, 0)); // ������ � ������� (0,0,0)

    a /= b; // �������� ��������� ���������
    EXPECT_EQ(a, Vector(0, 0, 0));
}

// �������� ��������� �� ������� � �������
TEST(VectorTest, DivisionErrorMessage) {
    testing::internal::CaptureStderr();
    Vector a(1, 2, 3);
    Vector b(0, 2, 3);
    a /= b;
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("������: ������� �� ������ � ������� �����������"), std::string::npos);
}

// �������� ��������� �� ������� ��� �������� � ������� ��������
TEST(VectorTest, CosineZeroErrorMessage) {
    testing::internal::CaptureStderr();
    Vector a(1, 2, 3);
    Vector zero(0, 0, 0);
    double result = a ^ zero;
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_DOUBLE_EQ(result, 0.0);
    EXPECT_NE(output.find("������: ���������� ����� ������� ����� �������� ��������"), std::string::npos);
}

// �������� ������� ������ �����
TEST(VectorTest, StreamInputEmpty) {
    Vector v;
    std::istringstream in("");
    in >> v;
    EXPECT_EQ(v, Vector(0, 0, 0)); // ������ �������� ��� ���������
}

// �������� ���������� ��������� � ������� ���������
TEST(VectorTest, ComparisonEqualVectors) {
    Vector a(5, 5, 5);
    Vector b(5, 5, 5);

    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a >= b);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}


// �������� ��������� << � �������������� �������
TEST(VectorTest, StreamOutputNegative) {
    Vector v(-7, -8, -9);
    std::ostringstream out;
    out << v;
    EXPECT_EQ(out.str(), "(-7, -8, -9)");
}


// �������� �������� "1. ����� ����� �������"
TEST(UITest, Option1_ShowVectors) {
    std::istringstream in("1 2 3\n4 5 6\n1\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("a = (1, 2, 3)"), std::string::npos);
    EXPECT_NE(output.find("b = (4, 5, 6)"), std::string::npos);
}

// �������� "2. ����� ��������"
TEST(UITest, Option2_VectorLength) {
    std::istringstream in("3 4 0\n0 0 0\n2\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("����� ������� a:"), std::string::npos);
    EXPECT_NE(output.find("5"), std::string::npos); // ����� (3,4,0) = 5
}

// �������� "3. ��������"
TEST(UITest, Option3_Addition) {
    std::istringstream in("1 2 3\n4 5 6\n3\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("a + b = (5, 7, 9)"), std::string::npos);
    EXPECT_NE(output.find("a += b"), std::string::npos);
}

// �������� "4. ���������"
TEST(UITest, Option4_Subtraction) {
    std::istringstream in("5 5 5\n2 2 2\n4\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("a - b = (3, 3, 3)"), std::string::npos);
    EXPECT_NE(output.find("a -= b"), std::string::npos);
}

// �������� "5. ��������� ������������"
TEST(UITest, Option5_CrossProduct) {
    std::istringstream in("1 0 0\n0 1 0\n5\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("a * b"), std::string::npos);
    EXPECT_NE(output.find("(0, 0, 1)"), std::string::npos);
}

// �������� "6. ��������� �� �����"
TEST(UITest, Option6_MultiplyByScalar) {
    std::istringstream in("1 2 3\n0 0 0\n6\n2\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("������� �����:"), std::string::npos);
    EXPECT_NE(output.find("a * 2 = (2, 4, 6)"), std::string::npos);
}

// �������� "7. ������� ��������"
TEST(UITest, Option7_Division) {
    std::istringstream in("8 9 10\n2 3 5\n7\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("a / b"), std::string::npos);
    EXPECT_NE(output.find("(4, 3, 2)"), std::string::npos);
}

// �������� "8. ������� ����� ���������"
TEST(UITest, Option8_Cosine) {
    std::istringstream in("1 0 0\n0 1 0\n8\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("cos(a, b)"), std::string::npos);
    EXPECT_NE(output.find("0"), std::string::npos);
}

// �������� "9. ��������� ���� ��������"
TEST(UITest, Option9_Comparison) {
    std::istringstream in("3 4 0\n1 1 1\n9\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("��������� ����"), std::string::npos);
    EXPECT_NE(output.find("a > b ? ��"), std::string::npos);
}

// �������� ������������� ������
TEST(UITest, InvalidChoice) {
    std::istringstream in("1 2 3\n4 5 6\n99\n10\n");
    std::ostringstream out;
    UI(in, out);
    std::string output = out.str();
    EXPECT_NE(output.find("������������ �����"), std::string::npos);
}
