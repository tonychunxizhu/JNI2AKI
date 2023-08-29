//
// Created by blueuser on 2023-08-21.
//


/* File : example.h */
class Shape {
public:
    Shape() {
        nshapes++;
    }
    virtual ~Shape() {
        nshapes--;
    }
    double x, y;
    void move(double dx, double dy);
    virtual double area() = 0;
    virtual double perimeter() = 0;
    static int nshapes;
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) { }
    virtual double area();
    virtual double perimeter();
};
class Square : public Shape {
private:
    double width;
public:
    Square(double w) : width(w) { }
    virtual double area();
    virtual double perimeter();
};