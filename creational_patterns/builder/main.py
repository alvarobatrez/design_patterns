from abc import ABC, abstractmethod

# Producto complejo
class Car:

    def __init__(self):
        self.engine = None
        self.wheels = None
        self.chassis = None
        self.interior = None

    def set_engine(self, engine):
        self.engine = engine

    def set_wheels(self, wheels):
        self.wheels = wheels

    def set_chassis(self, chassis):
        self.chassis = chassis

    def set_interior(self, interior):
        self.interior = interior

    def show(self):
        print('Car Speficications')
        print(f'Engine: {self.engine}')
        print(f'Wheels: {self.wheels}')
        print(f'Chassis: {self.chassis}')
        print(f'Interior: {self.interior}')

# Builder abstracto
class CarBuilder(ABC):

    def __init__(self):
        self.car = Car()

    @abstractmethod
    def build_engine(self):
        pass

    @abstractmethod
    def build_wheels(self):
        pass

    @abstractmethod
    def build_chassis(self):
        pass

    @abstractmethod
    def build_interior(self):
        pass

    def get_car(self):
        return self.car
    
# Concrete Builder para un auto deportivo
class SportsCarBuilder(CarBuilder):
    
    def build_engine(self):
        self.car.set_engine("V8 Engine")

    def build_wheels(self):
        self.car.set_wheels("18 inch Alloy Wheels")

    def build_chassis(self):
        self.car.set_chassis("Carbon Fiber Chassis")

    def build_interior(self):
        self.car.set_interior("Leather Interior")

# Concrete Builder para un auto económico
class EconomyCarBuilder(CarBuilder):
    
    def build_engine(self):
        self.car.set_engine("I4 Engine")

    def build_wheels(self):
        self.car.set_wheels("14 inch Alloy Wheels")

    def build_chassis(self):
        self.car.set_chassis("Aluminum Chassis")

    def build_interior(self):
        self.car.set_interior("Fabric Interior")

# Director
class Director:

    def __init__(self):
        self.builder = None

    def set_builder(self, builder):
        self.builder = builder

    def construct_car(self):
        self.builder.build_engine()
        self.builder.build_wheels()
        self.builder.build_chassis()
        self.builder.build_interior()

if __name__ == '__main__':

    director = Director()

    sports_builder = SportsCarBuilder()
    director.set_builder(sports_builder)
    director.construct_car()
    sports_car = sports_builder.get_car()
    sports_car.show()

    economy_builder = EconomyCarBuilder()
    director.set_builder(economy_builder)
    director.construct_car()
    economy_car = economy_builder.get_car()
    economy_car.show()