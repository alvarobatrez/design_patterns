from abc import ABC, abstractmethod

# Producto Abstracto 1
class Button(ABC):

    @abstractmethod
    def render(self):
        pass

# Producto Abstracto 2
class Window(ABC):

    @abstractmethod
    def render(self):
        pass

# Producto Concreto 1 para estilo Moderno
class ModernButton(Button):

    def render(self):
        print("Rendering Modern Button")

# Producto Concreto 2 para estilo Moderno
class ModernWindow(Window):

    def render(self):
        print("Rendering Modern Window")

# Producto Concreto 1 para estilo Clásico
class ClassicButton(Button):

    def render(self):
        print("Rendering Classic Button")

# Producto Concreto 2 para estilo Clásico
class ClassicWindow(Window):

    def render(self):
        print("Rendering Classic Window")

# Fábrica Abstracta
class GUIFactory(ABC):

    @abstractmethod
    def create_button(self):
        pass

    @abstractmethod
    def create_window(self):
        pass

# Fábrica Concreta para estilo Moderno
class ModernGUIFactory(GUIFactory):

    def create_button(self):
        return ModernButton()
    
    def create_window(self):
        return ModernWindow()
    
# Fábrica Concreta para estilo Clásico
class ClassicGUIFactory(GUIFactory):

    def create_button(self):
        return ClassicButton()
    
    def create_window(self):
        return ClassicWindow()
    
# Cliente
class Application:

    def __init__(self, factory):
        self.factory = factory
        self.button = None
        self.window = None

    def create_ui(self):
        self.button = self.factory.create_button()
        self.window = self.factory.create_window()

    def render_ui(self):
        self.button.render()
        self.window.render()

if __name__ == '__main__':

    app = Application(ModernGUIFactory())
    app.create_ui()
    app.render_ui()

    app = Application(ClassicGUIFactory())
    app.create_ui()
    app.render_ui()