#include <iostream>
#include <string>

class Device
{
    public:

    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void setVolume(int volume) = 0;
    virtual int getVolume() const = 0;
    virtual ~Device() = default;
};

// Concrete Implementor: Una implementación concreta para TV
class TV : public Device
{
    private:

    int volume_ = 10;

    public:

    void powerOn() override
    {
        std::cout << "TV is now ON\n";
    }

    void powerOff() override
    {
        std::cout << "TV is now OFF\n";
    }

    void setVolume(int volume) override
    {
        volume_ = volume;
        std::cout << "TV volume set to " << volume_ << std::endl;
    }

    int getVolume() const override
    {
        return volume_;
    }
};

// Concrete Implementor: Una implementación concreta para Radio
class Radio : public Device
{
    private:

    int volume_ = 5;

    public:

    void powerOn() override
    {
        std::cout << "Radio is now ON\n";
    }

    void powerOff() override
    {
        std::cout << "Radio is now OFF\n";
    }

    void setVolume(int volume) override
    {
        volume_ = volume;
        std::cout << "Radio volume set to " << volume_ << std::endl;
    }

    int getVolume() const override
    {
        return volume_;
    }
};

// Abstraction: Define la interfaz de control para los dispositivos
class RemoteControl
{
    protected:

    Device *device_;
    bool isOn_ = false;

    public:

    RemoteControl(Device *device) : device_(device) {}

    virtual void togglePower()
    {
        if (isOn_)
        {
            device_->powerOff();
        }
        else
        {
            device_->powerOn();
        }
        
    }
};

int main()
{
    
    
    return 0;
}