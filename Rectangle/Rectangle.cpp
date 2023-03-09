

#include <iostream>
#include <iomanip>
using namespace std;

double DlinaStoroni(double x2, double x1, double y1, double y2);
double Gipotenuza(double a, double b);
double Square(double a, double b);

class Point 
{
public:
    double x; double y;
    Point(double a, double b)
    {
        x = a; y = b;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Point pointO(0, 0);
    Point point1(0, 0);
    Point point2(0, 0);
    Point point3(0, 0);
    Point point4(0, 0);

    char operation;
    double storona1; double storona2; double rad; double gipotenuza; double square;
    bool menu = true; bool tf = true;
    while (menu)
    {
        system("CLS");
        tf = true;
        cout << "Выберете номер операции\n" << "1. Составить прямоугольник.\n" << "2. Закрыть программу.\n";
        cin >> operation;
        switch (operation)
        {
        case '1': 
            while (tf)
            {
                tf = false;
                system("CLS");
                cout << "Введите координаты точки для прямоугольника:\n";
                cin >> point1.x;
                cin >> point1.y;
                if (point1.x == 0 && point1.y == 0)
                {
                    cout << "Координаты точки не могут совпадать с центром окружности\n";
                    tf = true;
                }
            }
            rad = sqrt(point1.x * point1.x + point1.y * point1.y);
            point3.x = -1 * point1.x;
            point3.y = -1 * point1.y;
            tf = true;
            cout << "Введите абcциссу второй точки:\n";
            cout << "(Абcцисса не должна совпадать с абcцисоой первой точки, а также выходить за пределы окружности!)\n";
            while (tf)
            {
                tf = false;
                cin >> point2.x;
                if ((point2.x > rad || point2.x < (-1 * rad)) || (point2.x == point1.x) || (point2.x == (-1 * point1.x)))
                {
                    cout << "Данная абcцисса не соответствует требованиям, введите другое значение\n";
                    tf = true;
                }
            }
            system("CLS");
            point2.y = sqrt(rad * rad - point2.x * point2.x);
            point4.x = -1 * point2.x;
            point4.y = -1 * point2.y;
            cout << "Координаты вершин прямоугольника:\n";
            cout << setiosflags(ios::left) << setw(15) << "X" << setiosflags(ios::left) << setw(15) << "Y";
            cout << endl;
            cout << setiosflags(ios::left) << setw(15) << point1.x << setiosflags(ios::left) << setw(15) << point1.y;
            cout << endl;
            cout << setiosflags(ios::left) << setw(15) << point2.x << setiosflags(ios::left) << setw(15) << point2.y;
            cout << endl;
            cout << setiosflags(ios::left) << setw(15) << point3.x << setiosflags(ios::left) << setw(15) << point3.y;
            cout << endl;
            cout << setiosflags(ios::left) << setw(15) << point4.x << setiosflags(ios::left) << setw(15) << point4.y;
            cout << endl;

            storona1 = DlinaStoroni(point2.x, point1.x, point2.y, point1.y);
            cout << "Длина первого катета = " << storona1 << "\n";
            storona2 = DlinaStoroni(point2.x, point3.x, point2.y, point3.y);
            cout << "Длина второго катета = " << storona2 << "\n";
            gipotenuza = Gipotenuza(storona1, storona2);
            cout << "Гипотенуза треугольника = " << gipotenuza << "\n";
            square = Square(storona1, storona2);
            cout << "Площадь полученного прямоугольника = " << square << "\n";
            system("pause");
            break;
        case '2': menu = false; break;
        default:
            break;
        }
    }
}
double DlinaStoroni(double x2, double x1, double y1, double y2)
{
    double Dlina = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return Dlina;
}
double Gipotenuza(double a, double b)
{
    double gipotenuza = sqrt(a * a + b * b);
    return gipotenuza;
}
double Square(double a, double b)
{
    double square = a * b;
    return square;
}