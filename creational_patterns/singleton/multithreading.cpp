#include <iostream>
#include <mutex>
#include <thread>

class Singleton
{
    private:

    Singleton() {}
    ~Singleton() {}

    static Singleton *instance_;

    public:

    // Método estático para obtener la instancia única
    static Singleton &getInstance()
    {
        // Instancia se crea la primera vez que se llama este método
        static std::once_flag flag;
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

    // Eliminar los métodos de copia para asegurar que la instancia no se copie
    Singleton(const Singleton &) = delete;
    Singleton& operator=(const Singleton &) = delete;
};

Singleton *Singleton::instance_ = nullptr;

void threadFunction()
{
    Singleton &instance = Singleton::getInstance();
    instance.doSomething();
}

int main()
{
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);

    t1.join();
    t2.join();
    
    return 0;
}