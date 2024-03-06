#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double sum() const = 0;
};

class Triangle : public Shape
{
private:
	double base;
	double height;
public:
	Triangle(double b, double h) : base{ b }, height{ h } {}

	double sum() const override {
		return 0.5 * base * height;
	}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double r) : radius{ r } {}

	double sum() const override {
		return 3.14 * radius * radius;
	}
};

class Rectangle : public Shape
{
private:
	double lenght;
	double width;
public:
	Rectangle(double l, double w) : lenght{ l }, width{ w } {}

	double sum() const override {
		return lenght * width;
	}
};

int main() {
	Triangle triangle(5, 3);
	Circle circle(4);
	Rectangle rectangle(6,2);

	Shape* ptr_triangle = static_cast<Shape*>(&triangle);
	Shape* ptr_circle = static_cast<Shape*>(&circle);
	Shape* ptr_rectangle = static_cast<Shape*>(&rectangle);


	double totalSum = 0.0;
	totalSum += ptr_triangle->sum();
	totalSum += ptr_circle->sum();
	totalSum += ptr_rectangle->sum();

	cout << "Total sum of all shapes: " << totalSum << endl;
}