#include <iostream>
#include <mutex>

class Singleton
{
    private:
    // Constructor privado para evitar instaciación directa
    Singleton()
    {
        std::cout << "Singleton instance created\n";
    }

    // Destructor también puede ser privado
    ~Singleton()
    {
        std::cout << "Singleton instance destroyed\n";
    }

    public:
    // Método estático para obtener instancia única
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

    // Eliminar los métodos copia para asegurar que la instancia no se copie
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
};

int main()
{
    // Intento de obtener la instancia única de Singleton
    Singleton &instance1 = Singleton::getInstance();
    instance1.doSomething();

    // Intento de obtener la misma instancia
    Singleton &instance2 = Singleton::getInstance();
    instance2.doSomething();

    // Verificación de que ambas referencias son la misma instancia
    std::cout << "Are both instances the same? " << 
    std::boolalpha << static_cast<bool>(&instance1 == &instance2) << std::endl;

    return 0;
}