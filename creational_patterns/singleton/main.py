class Singleton:

    _instance = None

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super(Singleton, cls).__new__(cls, *args, **kwargs)
            print('Singleton instance created')

        return cls._instance
    
    def do_something(self):
        print('Singleton instance is doing something')

# Cliente
if __name__ == '__main__':
    # Intento de crear la primera instancia
    instance1 = Singleton()
    instance1.do_something()

    # Intento de crear otra instancia
    instance2 = Singleton()
    instance2.do_something()

    # Verificación de que ambas referencias son la misma instancia
    print('Are both instances the same? ', instance1 is instance2)