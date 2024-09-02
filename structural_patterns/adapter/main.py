# Target: Interfaz esperada por el cliente
class DrawingAPI:

    def draw_circle(self, x, y, radius):
        pass

    def draw_square(self, x, y, side):
        pass

# Adaptee: La clase con una interfaz incompatible
class LegacyDrawingAPI:

    def draw_legacy_circle(self, x, y, radius):
        print(f'Drawing Circle in Legacy API at ({x}, {y}) with radius {radius}')

    def draw_legacy_square(self, x, y, side):
        print(f"Drawing Square in Legacy API at ({x}, {y}) with side {side}")

# Adapter: Convierte la interfaz de LegacyDrawingAPI en DrawingAPI
class DrawingAPIAdapter(DrawingAPI):

    def __init__(self, legacy_api):
        self.legacy_api = legacy_api

    def draw_circle(self, x, y, radius):
        self.legacy_api.draw_legacy_circle(x, y, radius)

    def draw_square(self, x, y, side):
        self.legacy_api.draw_legacy_square(x, y, side)

# Cliente que utiliza la interfaz DrawingAPI
class Shape:

    def __init__(self, drawing_api):
        self.drawing_api = drawing_api

    def draw(self):
        pass

class Circle(Shape):

    def __init__(self, x, y, radius, drawing_api):
        super().__init__(drawing_api)
        self.x = x
        self.y = y
        self.radius = radius

    def draw(self):
        self.drawing_api.draw_circle(self.x, self.y, self.radius)

class Square(Shape):

    def __init__(self, x, y, side, drawing_api):
        super().__init__(drawing_api)
        self.x = x
        self.y = y
        self.side = side

    def draw(self):
        self.drawing_api.draw_square(self.x, self.y, self.side)

if __name__ == '__main__':
    legacy_api = LegacyDrawingAPI()
    adapter = DrawingAPIAdapter(legacy_api)

    circle = Circle(5, 10, 7, adapter)
    square = Square(15, 20, 10, adapter)

    circle.draw()
    square.draw()