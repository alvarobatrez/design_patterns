#include <iostream>
#include <memory>

// Producto complejo
class Car
{
    private:

    std::string engine_;
    std::string wheels_;
    std::string chassis_;
    std::string interior_;
    
    public:

    void setEngine(const std::string &engine) { engine_ = engine; }
    void setWheels(const std::string &wheels) { wheels_ = wheels; }
    void setChassis(const std::string &chassis) { chassis_ = chassis; }
    void setInterior(const std::string &interior) { interior_ = interior; }
    
    void show() const
    {
        std::cout << "Car Specifications:\n";
        std::cout << "Engine: " << engine_ << std::endl;
        std::cout << "Wheels: " << wheels_ << std::endl;
        std::cout << "Chassis: " << chassis_ << std::endl;
        std::cout << "Interior: " << interior_ << std::endl;
    }
};

// Builder abstracto
class CarBuilder
{
    protected:

    std::unique_ptr<Car> car_ = std::make_unique<Car>();

    public:
    
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildChassis() = 0;
    virtual void buildInterior() = 0;

    std::unique_ptr<Car> getCar() {return std::move(car_); }

    virtual ~CarBuilder() {}
};

// Concrete Builder para un auto deportivo
class SportsCarBuilder : public CarBuilder
{
    public:

    void buildEngine() override { car_->setEngine("V8 Engine"); }
    void buildWheels() override { car_->setWheels("18 inch Alloy Wheels"); }
    void buildChassis() override { car_->setChassis("Carbon Fiber Chasis"); }
    void buildInterior() override { car_->setInterior("Leather Interior"); }
};

// Concrete Builder para un auto económico
class EconomyCarBuilder : public CarBuilder
{
    public:

    void buildEngine() override { car_->setEngine("I4 Engine"); }
    void buildWheels() override { car_->setWheels("14 inch Alloy Wheels"); }
    void buildChassis() override { car_->setChassis("Aluminum Chasis"); }
    void buildInterior() override { car_->setInterior("Fabric Interior"); }
};

// Director
class Director
{
    private:

    CarBuilder *builder_;

    public:

    void setBuilder(CarBuilder *builder) { builder_ = builder; }

    void constructCar()
    {
        builder_->buildEngine();
        builder_->buildWheels();
        builder_->buildChassis();
        builder_->buildInterior();
    }
};

int main()
{
    Director director;

    SportsCarBuilder sportsBuilder;
    director.setBuilder(&sportsBuilder);
    director.constructCar();
    auto sportsCar = sportsBuilder.getCar();
    sportsCar->show();

    EconomyCarBuilder economyBuilder;
    director.setBuilder(&economyBuilder);
    director.constructCar();
    auto economyCar = economyBuilder.getCar();
    economyCar->show();

    return 0;
}