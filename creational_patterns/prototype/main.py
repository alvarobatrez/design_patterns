from abc import ABC, abstractmethod
import copy

# Prototipo (interfaz base)
class Shape(ABC):

    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    @abstractmethod
    def clone(self):
        pass

    @abstractmethod
    def draw(self):
        pass

    def set_position(self, x, y):
        self.x = x
        self.y = y

# Prototipo concreto 1
class Circle(Shape):

    def __init__(self, radius, x=0, y=0):
        super().__init__(x, y)
        self.radius = radius

    def clone(self):
        return copy.deepcopy(self)
    
    def draw(self):
        print(f'Drawing Circle at ({self.x}, {self.y}) with radius {self.radius}')

# Prototipo concreto 2
class Rectangle(Shape):

    def __init__(self, width, height, x=0, y=0):
        super().__init__(x, y)
        self.width = width
        self.height = height

    def clone(self):
        return copy.deepcopy(self)
    
    def draw(self):
        print(f'Drawing Rectangle at ({self.x}, {self.y}) with width {self.width} and height {self.height}')

# Cliente
class PrototypeManager:

    def __init__(self):
        self.prototypes = {}

    def register_prototype(self, key, prototype):
        self.prototypes[key] = prototype

    def create(self, key):
        prototype = self.prototypes.get(key)
        if prototype:
            return prototype.clone()
        return None
    
if __name__ == '__main__':
    manager = PrototypeManager()

    # Registar prototipos
    manager.register_prototype("Circle", Circle(10))
    manager.register_prototype("Rectangle", Rectangle(20, 30))

    # Crear y personalizar una nueva figura basada en el prototipo Círculo
    circle = manager.create("Circle")
    circle.set_position(15, 25)
    circle.draw()

    # Crear y personalizar una nueva figura basada en el prototipo Rectángulo
    rectangle = manager.create("Rectangle")
    rectangle.set_position(50, 60)
    rectangle.draw()