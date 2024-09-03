#include <iostream>
#include <mutex>
#include <thread>

class Singleton
{
    private:
    // Constructor privado para evitar instaciación directa
    Singleton() {}

    // Destructor también puede ser privado
    ~Singleton() {}

    // Puntero estático para almacenar la única isntancia del Singleton
    static Singleton *instance_;

    public:
    // Método estático para obtener instancia única
    static Singleton &getInstance()
    {
        // Garantiza que la función se ejecute una sola vez
        static std::once_flag flag;
        // Asegura que la creación de la instancia sea segura en múltiples hilos
        std::call_once(flag, []()
        {
            instance_ = new Singleton();
            std::cout << "Singleton instance created\n";
        });

        return *instance_;
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

// Inicialización de la instancia estática en nullptr
Singleton *Singleton::instance_ = nullptr;

// Función para ser ejecutada por varios hilos, intenta obtener la instancia Singleton
void threadFunction()
{
    Singleton &instance = Singleton::getInstance();
    instance.doSomething();
}

int main()
{
    // Crear dos hilos que llamarán en threadFunction
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);

    // Asegura que el programa no termine hasta que ambos finalicen
    t1.join();
    t2.join();

    return 0;
}