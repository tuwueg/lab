//Создать базовый класс «Круг». Элементы класса: поле, содержащее
//значение радиуса круга(статус доступа protected); конструктор для
//инициализации поля; функция для печати радиуса круга.Создать производный
//класс «Эллипс».Элементы класса : дополнительно поле, содержащее значение
//второй полуоси эллипса(для задания первой полуоси использовать
//наследуемое поле радиуса круга); конструктор для инициализации полей;
//переопределенная функция печати параметров эллипса(внутри
//переопределенной функции должна вызываться функция из базового класса).
//Создать по одному объекту каждого из классов.Показать вызов созданных
//функций.При переопределении функций обеспечить динамический
//полиморфизм, показать его особенности в программе.
#include <iostream>

class Circle {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    virtual void printRadius() {
        setlocale(LC_ALL, "Russian");
        std::cout << "Радиус окружности: " << radius << std::endl;
    }
};

class Ellipse : public Circle {
private:
    double semiAxis;

public:
    Ellipse(double r, double a) : Circle(r), semiAxis(a) {}

    void printRadius() override {
        Circle::printRadius();
        std::cout << "Полуось эллипса: " << semiAxis << std::endl;
    }
};

int main() {
    Circle* circle = new Circle(5.0);
    Ellipse* ellipse = new Ellipse(3.0, 4.0);

    circle->printRadius();   // Вызов функции printRadius() для объекта класса Circle
    ellipse->printRadius();  // Вызов функции printRadius() для объекта класса Ellipse

    delete circle;
    delete ellipse;

    return 0;
}
