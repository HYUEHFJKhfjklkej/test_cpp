#include <cmath>
#include <iostream>

class Shape {
 public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual void print() const = 0;
}

class Circle : public Shape {
 public:
  Circle(double radius) : radius_(radius) {}
  double area() const override { return M_PI * radius_ * radius_; }
  double perimeter() const override { return 2 * M_PI * radius_; }
  void print() const override {
    std::cout << "Circle (radius: " << radius_ << ")\n";
  }

 private:
  double radius_;
};

class Rectangle : public Shape {
 public:
  Rectangle(double width, double height) : width_(width), height_(height) {}
  double area() const override { return width_ * height_; }
  double perimeter() const override { return 2 * (width_ + height_); }
  void print() const override {
    std::cout << "Rectangle (width: " << width_ << ", height: " << height_
              << ")\n";
  }

 private:
  double width_;
  double height_;
};

class Square : public Rectangle {
 public:
  Square(double side) : Rectangle(side, side) {}
  void print() const override {
    std::cout << "Square (side: " << getWidth() << ")\n";
  }

 private:
  double getWidth() const { return width_; }
};

class Triangle : public Shape {
 public:
  Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}
  double area() const override {
    double s = (a_ + b_ + c_) / 2;
    return sqrt(s * (s - a_) * (s - b_) * (s - c_));
  }
  double perimeter() const override { return a_ + b_ + c_; }

  void print() const override {
    std::cout << " Triangle (a: " << a_ << ", b: " << b_ << ", c: " << c_
              << ")\n";
  }

 private:
  double a_;
  double b_;
  double c_;
};

int main() {
  Circle circle(5);
  Rectangle rectangle(10, 5);
  Square square(8);
  Triangle triangle(3, 4, 5);
  Shape* shapes[] = {&circle, &rectangle, &square, &triangle};
  for (Shape* shape : shapes) {
    shape->print();
    std::cout << "Area: " << shape->area() << std::endl;
    std::cout << "Perimeter: " << shape->perimeter() << std::endl;
    std::cout << std::endl;
  }
  return 0;
}