#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
    private:

    Singleton()
    {
        std::cout << "Singleton instance created\n";
    }

    ~Singleton()
    {
        std::cout << "Singleton instance destroyed\n";
    }

    public:

    // Método estático para obtener la instancia única
    static Singleton &getInstance()
    {
        // Instancia se crea la primera vez que se llama este método
        static Singleton instance;
        return instance;
    }

    // Ejemplo de un método de la clase Singleton
    void doSomething()
    {
        std::cout << "Singleton instance is doing something\n";
    }

    // Eliminar los métodos de copia para asegurar que la instancia no se copie
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
};

int main()
{
    Singleton &instance1 = Singleton::getInstance();
    instance1.doSomething();

    Singleton &instance2 = Singleton::getInstance();
    instance2.doSomething();

    std::cout << "Are both instances the same? " << (&instance1 == &instance2) << std::endl;
    
    return 0;
}