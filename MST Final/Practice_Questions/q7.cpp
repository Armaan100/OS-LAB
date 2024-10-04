#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(1.0), width(1.0) {}

    // Parameterized constructor
    Rectangle(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
        } else {
            length = 1.0;  // Default value
            width = 1.0;   // Default value
            cout << "Invalid dimensions provided. Setting to default (1.0, 1.0)." << endl;
        }
    }

    // Friend function to calculate area
    friend double calculateArea(Rectangle& rect);

    // Friend function to calculate perimeter
    friend double calculatePerimeter(Rectangle& rect);

    // Static member function to compare areas
    static Rectangle compareArea(Rectangle& rect1, Rectangle& rect2);
};

// Friend function to calculate the area
double calculateArea(Rectangle& rect) {
    return rect.length * rect.width;
}

// Friend function to calculate the perimeter
double calculatePerimeter(Rectangle& rect) {
    return 2 * (rect.length + rect.width);
}

// Static member function to compare areas
Rectangle Rectangle::compareArea(Rectangle& rect1, Rectangle& rect2) {
    double area1 = calculateArea(rect1);
    double area2 = calculateArea(rect2);
    return (area1 >= area2) ? rect1 : rect2; // Return either if equal
}

int main() {
    const int SIZE = 3;
    Rectangle* rectangles = new Rectangle[SIZE];

    // Input dimensions for each rectangle
    for (int i = 0; i < SIZE; i++) {
        double length, width;
        cout << "Enter length and width for rectangle " << i + 1 << ": ";
        cin >> length >> width;
        rectangles[i] = Rectangle(length, width);
    }

    // Display areas and perimeters of rectangles
    for (int i = 0; i < SIZE; i++) {
        cout << "Rectangle " << i + 1 << ": " 
             << "Area = " << calculateArea(rectangles[i]) 
             << ", Perimeter = " << calculatePerimeter(rectangles[i]) << endl;
    }

    // Compare areas of first two rectangles
    Rectangle largerRectangle = Rectangle::compareArea(rectangles[0], rectangles[1]);
    cout << "The larger rectangle is Rectangle 1 with area: " << calculateArea(rectangles[0]) << endl;
    
    // If comparing all rectangles
    for (int i = 1; i < SIZE - 1; i++) {
        largerRectangle = Rectangle::compareArea(largerRectangle, rectangles[i]);
    }
    cout << "The rectangle with the largest area is: " 
         << calculateArea(largerRectangle) << endl;

    // Cleanup
    delete[] rectangles;
    return 0;
}
