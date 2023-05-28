//Класс «Прямая призма»(Prisma_Attached_Triangular - прямая призма, в
//основание которой - правильный треугольник - вписана окружность).Создать
//массив объектов класса с параметрами : а - сторона правильного треугольника, г - радиус
//вписанной окружности и r = a / 2 tg60°, Н - высота призмы.Вычислить площадь
//основания, боковую и полную поверхности, а также объем объектов - призм, упорядочив
//массив по убыванию объема.
//Sосн = a ^ 2 sqrt(3 / 4), Sбок = 3a * H, Sполн = 2Sосн + Sбок

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class Prisma_Attached_Triangular {
private:
    double a;  // Сторона правильного треугольника
    double r;  // Радиус вписанной окружности
    double H;  // Высота призмы

public:
    Prisma_Attached_Triangular(double side, double radius, double height) : a(side), r(radius), H(height) {}

    double calculateBaseArea() const {
        return a * a * sqrt(3) / 4;  // Площадь основания (правильного треугольника)
    }

    double calculateSideArea() const {
        return 3 * a * H;  // Площадь боковой поверхности
    }

    double calculateTotalArea() const {
        return 2 * calculateBaseArea() + calculateSideArea();  // Полная площадь поверхности
    }

    double calculateVolume() const {
        return calculateBaseArea() * H;  // Объем призмы
    }
};

bool compareVolume(const Prisma_Attached_Triangular& pr1, const Prisma_Attached_Triangular& pr2) {
    return pr1.calculateVolume() > pr2.calculateVolume();  // Сравнение объемов призм для сортировки
}

int main() {
    std::vector<Prisma_Attached_Triangular> prisms;
    setlocale(LC_ALL, "Russian");

    // Создание массива объектов класса Prisma_Attached_Triangular с параметрами
    prisms.emplace_back(10.0, 5.0, 8.0);
    prisms.emplace_back(8.0, 4.0, 6.0);
    prisms.emplace_back(12.0, 6.0, 10.0);

    // Вычисление и вывод площади основания, боковой и полной поверхности, а также объема для каждой призмы
    for (const auto& prism : prisms) {
        std::cout << "Площадь основания: " << prism.calculateBaseArea() << std::endl;
        std::cout << "Площадь боковой поверхности: " << prism.calculateSideArea() << std::endl;
        std::cout << "Полная площадь поверхности: " << prism.calculateTotalArea() << std::endl;
        std::cout << "Объем призмы: " << prism.calculateVolume() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    // Сортировка массива объектов по убыванию объема
    std::sort(prisms.begin(), prisms.end(), compareVolume);

    // Вывод отсортированного массива
    std::cout << "Сортировка по обьему:" << std::endl;
    for (const auto& prism : prisms) {
        std::cout << "Объем призмы: " << prism.calculateVolume() << std::endl;
    }

    return 0;
}
