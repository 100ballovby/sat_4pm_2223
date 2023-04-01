#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void task1() {
    /**Создайте структуру "Point", которая представляет собой точку в двумерном пространстве с координатами x и y типа int. Создайте вектор, который содержит 10 таких точек и напишите функцию, которая вычисляет расстояние между двумя точками. Чтобы посчитать расстояние между двумя точками, нужна формула: **/
    vector<Point> points(10);
    // заполняю вектор случайными числами
    for (int i = 0; i < points.size(); i++) {
        points[i].x = rand() % 10;
        points[i].y = rand() % 10;

        cout << "Point " << i << ": (" << points[i].x << "," << points[i].y << ");" << endl;
    }

    double dist = distance(points[0], points[points.size() - 1]);
    cout << "Distance between first and last points is " << dist << endl;
}

// TASK 3
struct Triangle {
    Point a;
    Point b;
    Point c;
};

void printTriangles(vector<Triangle> &triangles) {
    for (Triangle t : triangles) {
        cout << "Triangles vertices: " << endl;
        cout << "(" << t.a.x << ", " << t.a.y << ");" << endl;
        cout << "(" << t.b.x << ", " << t.b.y << ");" << endl;
        cout << "(" << t.c.x << ", " << t.c.y << ");" << endl;
        cout << endl;
    }
}

void task3() {
    /**Создайте структуру "Triangle", которая содержит три поля типа "Point" (каждое из которых представляет собой вершину треугольника). Создайте вектор, который содержит 5 экземпляров этой структуры. Напишите функцию, которая принимает вектор "Triangle" и выводит на экран информацию о каждом треугольнике в нем (координаты вершин).**/
    vector<Triangle> triangles;
    // создадим 5 треугольников и добавим их в вектор
    triangles.push_back({{0, 0}, {0, 1}, {1, 0}});
    triangles.push_back({{1, 1}, {2, 2}, {3, 1}});
    triangles.push_back({{4, 4}, {5, 4}, {4, 5}});
    triangles.push_back({{6, 6}, {7, 7}, {8, 6}});
    triangles.push_back({{9, 9}, {10, 9}, {9, 10}});

    printTriangles(triangles);
}

int main() {
    srand(time(NULL));
    task1();
    task3();
    return 0;
}