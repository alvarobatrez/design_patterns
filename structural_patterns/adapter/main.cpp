#include <iostream>
#include <cmath>

// Target: Interfaz esperada por el cliente
class DrawingAPI
{
    public:

    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual void drawSquare(double x, double y, double side) = 0;
    virtual ~DrawingAPI() = default;
};

// Adaptee: La clase con una interfaz incompatible
class LegacyDrawingAPI
{
    public:

    void drawLegacyCircle(double x, double y, double radius)
    {
        std::cout << "Drawing Circle in Legacy API at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }

    void drawLegacySquare(double x, double y, double side)
    {
        std::cout << "Drawing Square in Legacy API at (" << x << ", " << y << ") with side " << side << std::endl;
    }
}

int main()
{
    return 0;
}