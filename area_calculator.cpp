// ------------------------------------------------------------------------------
// Eduardo G. Medina
// Project 5 - Area Calculator
// Language: C++
// Filename: area_calculator.cpp
// ------------------------------------------------------------------------------

#include <iostream>
#include <cmath> // Not required for this program but good if using math functions like pow()

using namespace std;

// Abstract base class for all shapes
class Shape {
public:
    // Pure virtual function to force all derived classes to implement their own get_area
    virtual double get_area() const = 0;
};

// Circle class that inherits from Shape
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Getter and setter for radius
    double get_radius() const { return radius; }
    void set_radius(double r) { radius = r; }

    // Override get_area() for circle: π * r^2
    double get_area() const override {
        return radius * radius * 3.14;
    }
};

// Square class that inherits from Shape
class Square : public Shape {
private:
    double width;

public:
    Square(double w) : width(w) {}

    double get_width() const { return width; }
    void set_width(double w) { width = w; }

    // Override get_area() for square: width^2
    double get_area() const override {
        return width * width;
    }
};

// Rectangle class that inherits from Square and adds height
class Rectangle : public Square {
private:
    double height;

public:
    Rectangle(double w, double h) : Square(w), height(h) {}

    double get_height() const { return height; }
    void set_height(double h) { height = h; }

    // Override get_area() for rectangle: width * height
    double get_area() const override {
        return get_width() * height;
    }
};

// Helper function to display the area
void display_area(const Shape& shape) {
    cout << "Area: " << shape.get_area() << endl;
}

int main() {
    cout << "The Area Calculator\n";

    char continueOption;

    // Main loop: runs at least once and repeats if user chooses 'y' to continue
    do {
        char shapeType;
        bool validShape = false;

        // Inner loop ensures the user enters a valid shape option
        while (!validShape) {
            cout << "\nCircle, square, or rectangle? (c/s/r): ";
            cin >> shapeType;

            if (shapeType == 'c') {
                double radius;
                cout << "Enter radius: ";
                cin >> radius;
                Circle circle(radius);
                display_area(circle);
                validShape = true;
            } else if (shapeType == 's') {
                double width;
                cout << "Enter width: ";
                cin >> width;
                Square square(width);
                display_area(square);
                validShape = true;
            } else if (shapeType == 'r') {
                double width, height;
                cout << "Enter width: ";
                cin >> width;
                cout << "Enter height: ";
                cin >> height;
                Rectangle rectangle(width, height);
                display_area(rectangle);
                validShape = true;
            } else {
                // If invalid option is entered, prompt again
                cout << "Invalid choice! Please enter 'c', 's', or 'r'.\n";
            }
        }

        // Ask user if they want to calculate another shape
        cout << "Continue? (y/n): ";
        cin >> continueOption;

    } while (continueOption == 'y' || continueOption == 'Y');

    cout << "\nThank you for using my app!\n";

    return 0;
}
