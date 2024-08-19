#include <iostream>
#include <memory>
#include <unordered_map>

// Prototipo (interfaz base)
class Shape
{
    protected:

    int x_ = 0;
    int y_ = 0;

    public:

    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}

    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }
    int getX() const { return x_; }
    int getY() const { return y_; }
};

// Prototipo concreto 1
class Circle : public Shape
{
    private:

    int radius_;

    public:

    Circle(int radius) : radius_(radius) {}

    std::unique_ptr<Shape> clone() const override
    {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override
    {
        std::cout << "Drawing Circle at (" << x_ << ", " << y_ << ") with radius " << radius_ << std::endl;
    }
};

// Prototipo concreto 2
class Rectangle : public Shape
{
    private:

    int width_;
    int height_;

    public:

    Rectangle(int width, int height) : width_(width), height_(height) {}

    std::unique_ptr<Shape> clone() const override
    {
        return std::make_unique<Rectangle>(*this);
    }

    void draw() const override
    {
        std::cout << "Drawing Rectangle at (" << x_ << ", " << y_ << ") with width " << width_ << " and height" << height_ << std::endl;
    }
};

// Cliente
class PrototypeManager
{
    private:

    std::unordered_map<std::string, std::unique_ptr<Shape>> prototypes_;

    public:

    void registerPrototype(const std::string &key, std::unique_ptr<Shape> prototype)
    {
        prototypes_[key] = std::move(prototype);
    }

    std::unique_ptr<Shape> create(const std::string &key) const
    {
        if (prototypes_.find(key) != prototypes_.end())
        {
            return prototypes_.at(key)->clone();
        }
        return nullptr;
    }
};

int main()
{
    PrototypeManager manager;

    // Registrar prototipos
    manager.registerPrototype("Circle", std::make_unique<Circle>(10));
    manager.registerPrototype("Rectangle", std::make_unique<Rectangle>(20, 30));

    // Crear y personalizar una nueva figura basada en el prototipo Círculo
    auto circle = manager.create("Circle");
    circle->setX(15);
    circle->setY(25);
    circle->draw();

    // Crear y personalizar una nueva figura basada en el prototipo Rectángulo
    auto rectangle = manager.create("Rectangle");
    rectangle->setX(50);
    rectangle->setY(60);
    rectangle->draw();
    
    return 0;
}