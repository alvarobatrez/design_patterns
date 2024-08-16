#include <iostream>
#include <memory>

// Producto Abstracto 1
class Button
{
    public:

    virtual void render() = 0;
    virtual ~Button() {}
};

// Producto Abstracto 2
class Window
{
    public:

    virtual void render() = 0;
    virtual ~Window() {}
};

// Producto Concreto 1 para estilo Moderno
class ModernButton : public Button
{
    public:

    void render() override
    {
        std::cout << "Rendering Modern Button\n";
    }
};

// Producto Concreto 2 para estilo Moderno
class ModernWindow : public Window
{
    public:

    void render() override
    {
        std::cout << "Rendering Modern Window\n";
    }
};

// Producto Concreto 1 para estilo Clásico
class ClassicButton : public Button
{
    public:

    void render() override
    {
        std::cout << "Rendering Classic Button\n";
    }
};

// Producto Concreto 2 para estilo Clásico
class ClassicWindow : public Window
{
    public:

    void render() override
    {
        std::cout << "Rendering Classic Window\n";
    }
};

// Fábrica Abstracta
class GUIFactory
{
    public:

    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Window> createWindow() = 0;
    virtual ~GUIFactory() {}
};

// Fábrica Concreta para estilo Moderno
class ModernGUIFactory : public GUIFactory
{
    public:

    std::unique_ptr<Button> createButton() override
    {
        return std::make_unique<ModernButton>();
    }

    std::unique_ptr<Window> createWindow() override
    {
        return std::make_unique<ModernWindow>();
    }
};

// Fábrica Concreta para estilo Clásico
class ClassicGUIFactory : public GUIFactory
{
    public:

    std::unique_ptr<Button> createButton() override
    {
        return std::make_unique<ClassicButton>();
    }

    std::unique_ptr<Window> createWindow() override
    {
        return std::make_unique<ClassicWindow>();
    }
};

// Cliente
class Application
{
    private:
    
    std::unique_ptr<GUIFactory> factory_;
    std::unique_ptr<Button> button_;
    std::unique_ptr<Window> window_;
    
    public:

    Application(std::unique_ptr<GUIFactory> factory) : factory_(std::move(factory)) {}

    void createUI()
    {
        button_ = factory_->createButton();
        window_ = factory_->createWindow();
    }

    void renderUI()
    {
        button_->render();
        window_->render();
    }
};

int main()
{
    auto app = std::make_unique<Application>(std::make_unique<ModernGUIFactory>());
    app->createUI();
    app->renderUI();

    app = std::make_unique<Application>(std::make_unique<ClassicGUIFactory>());
    app->createUI();
    app->renderUI();

    return 0;
}