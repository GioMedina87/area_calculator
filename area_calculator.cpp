// ------------------------------------------------------------------------------
// Eduardo G. Medina
// Project 5 - Area Calculator
// Language: C++
// Filename: area_calculator.cpp
// ------------------------------------------------------------------------------

#include <iostream>
#include <cmath> // Include cmath for mathematical operations

using namespace std;

// Abstract base class Shape
class Shape {
public:
    // Virtual function to get the area (to be overridden by derived classes)
    virtual double get_area() const = 0;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Getter and setter for radius
    double get_radius() const {
        return radius;
    }

    void set_radius(double r) {
        radius = r;
    }

    // Override get_area function
    double get_area() const override {
        return radius * radius * 3.14;
    }
};

// Derived class Square
class Square : public Shape {
private:
    double width;

public:
    // Constructor
    Square(double w) : width(w) {}

    // Getter and setter for width
    double get_width() const {
        return width;
    }

    void set_width(double w) {
        width = w;
    }

    // Override get_area function
    double get_area() const override {
        return width * width;
    }
};

// Derived class Rectangle
class Rectangle : public Square {
private:
    double height;

public:
    // Constructor
    Rectangle(double w, double h) : Square(w), height(h) {}

    // Getter and setter for height
    double get_height() const {
        return height;
    }

    void set_height(double h) {
        height = h;
    }

    // Override get_area function
    double get_area() const override {
        return get_width() * height;
    }
};

// Function to display the area of a shape
void display_area(const Shape& shape) {
    cout << "Area: " << shape.get_area() << endl;
}

int main() {
    cout << "The Area Calculator\n";

    char continueOption;
    do {
        // Prompt user to choose a shape
        cout << "\nCircle, square, or rectangle? (c/s/r): ";
        char shapeType;
        cin >> shapeType;

        // Process the chosen shape
        if (shapeType == 'c') {
            // Circle
            double radius;
            cout << "Enter radius: ";
            cin >> radius;

            // Create Circle object
            Circle circle(radius);

            // Display area
            display_area(circle);
        } else if (shapeType == 's') {
            // Square
            double width;
            cout << "Enter width: ";
            cin >> width;

            // Create Square object
            Square square(width);

            // Display area
            display_area(square);
        } else if (shapeType == 'r') {
            // Rectangle
            double width, height;
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter height: ";
            cin >> height;

            // Create Rectangle object
            Rectangle rectangle(width, height);

            // Display area
            display_area(rectangle);
        } else {
            // Invalid input
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        // Prompt user to continue
        cout << "Continue? (y/n): ";
        cin >> continueOption;

    } while (continueOption == 'y' || continueOption == 'Y');

    cout << "\nThank you for using my app!\n";

    return 0;
}
