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
};

// Adapter: Convierte la interfaz de LegacyDrawingAPI en DrawingAPI
class DrawingAPIAdapter : public DrawingAPI
{
    private:

    LegacyDrawingAPI &legacyAPI_;

    public:

    DrawingAPIAdapter(LegacyDrawingAPI &legacyAPI) : legacyAPI_(legacyAPI) {}

    void drawCircle(double x, double y, double radius) override
    {
        legacyAPI_.drawLegacyCircle(x, y, radius);
    }

    void drawSquare(double x, double y, double side) override
    {
        legacyAPI_.drawLegacySquare(x, y, side);
    }
};

// Cliente que utiliza la interfaz DrawingAPI
class Shape
{
    public:

    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    private:

    double x_, y_, radius_;
    DrawingAPI &drawingAPI_;

    public:

    Circle(double x, double y, double radius, DrawingAPI &drawingAPI)
    : x_(x), y_(y), radius_(radius), drawingAPI_(drawingAPI) {}

    void draw() override
    {
        drawingAPI_.drawCircle(x_, y_, radius_);
    }
};

class Square : public Shape
{
    private:

    double x_, y_, side_;
    DrawingAPI &drawingAPI_;

    public:

    Square(double x, double y, double side, DrawingAPI &drawingAPI)
    : x_(x), y_(y), side_(side), drawingAPI_(drawingAPI) {}

    void draw() override
    {
        drawingAPI_.drawSquare(x_, y_, side_);
    }
};

int main()
{
    LegacyDrawingAPI legacyAPI;
    DrawingAPIAdapter adapter(legacyAPI);

    Circle circle(5.0, 10.0, 7.0, adapter);
    Square square(15.0, 20.0, 10.0, adapter);

    circle.draw();
    square.draw();
    
    return 0;
}