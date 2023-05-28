//Составить описание класса для представления комплексных чисел.Реализовать все виды конструкторов.Обеспечить выполнение операций сложения, вычитания и умножения комплексных чисел.
#include <iostream>
using namespace std;


class Complex {
private:
    double real;    // Действительная часть
    double imaginary;   // Мнимая часть

public:
    // Конструктор по умолчанию
    Complex() : real(0.0), imaginary(0.0) {}

    // Конструктор с параметрами
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Конструктор копирования
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

    // Метод для получения действительной части
    double getReal() const {
        return real;
    }

    // Метод для получения мнимой части
    double getImaginary() const {
        return imaginary;
    }

    // Перегрузка оператора сложения
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Перегрузка оператора вычитания
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Перегрузка оператора умножения
    Complex operator*(const Complex& other) const {
        double resultReal = real * other.real - imaginary * other.imaginary;
        double resultImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(resultReal, resultImaginary);
    }
};

int main() {
    // Пример использования класса Complex
    Complex a(2.0, 3.0);
    Complex b(1.0, -2.0);

    Complex sum = a + b;
    Complex difference = a - b;
    Complex product = a * b;
    setlocale(LC_ALL, "Russian");
    std::cout << "Сумма: " << sum.getReal() << " + " << sum.getImaginary() << "i" << std::endl;
    std::cout << "Разность: " << difference.getReal() << " + " << difference.getImaginary() << "i" << std::endl;
    std::cout << "Произведение: " << product.getReal() << " + " << product.getImaginary() << "i" << std::endl;

    return 0;
}
