#include <iostream>
#include <stdexcept>

using namespace std;

class Point {
private:
    double x, y, z;

public:
    Point(double x, double y, double z);

    void printCoordinates();
};

class outofrange : public std::out_of_range {
public:
    double invalidX, invalidY, invalidZ;

    outofrange(const string& msg, double x, double y, double z) : std::out_of_range(msg), invalidX(x), invalidY(y), invalidZ(z) {};

    void printInvalidPoint() {
        cout << "Invalid Point coordinates: x = " << invalidX << ", y = " << invalidY << ", z = " << invalidZ << endl;
    }
};

Point::Point(double x, double y, double z) {
    if (x < 0 || x > 1 || y < 0 || y > 1 || z < 0 || z > 1) {
        throw outofrange("Coordinates must be in the range [0, 1]", x, y, z);
    }
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::printCoordinates() {
    cout << "Point coordinates: x = " << x << ", y = " << y << ", z = " << z << endl;
}

int main() {
    try {
        Point point1(0.5, 0.7, 0.2);
        point1.printCoordinates();

        Point point2(1.2, 0.5, 0.8); // This will throw an exception
        point2.printCoordinates();
    }
    catch (outofrange& e) {
        cout << "Exception occurred: " << e.what() << endl;
        e.printInvalidPoint();
    }

    return 0;
}
