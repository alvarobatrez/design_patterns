from abc import ABC, abstractmethod

# Producto
class Document(ABC):

    @abstractmethod
    def open(self):
        pass

    @abstractmethod
    def save(self):
        pass

# Producto Concreto
class PDFDocument(Document):

    def open(self):
        print("Opening PDF document")

    def save(self):
        print("Saving PDF document")

class WordDocument(Document):

    def open(self):
        print("Opening Word document")

    def save(self):
        print("Saving Word document")

class ExcelDocument(Document):

    def open(self):
        print("Opening Excel document")

    def save(self):
        print("Saving Excel document")

# Creador
class Application(ABC):

    @abstractmethod
    def create_document(self):
        pass

    def new_document(self):
        doc = self.create_document()
        doc.open()
        doc.save()

# Creador Concreto
class PDFApplication(Application):
    
    def create_document(self):
        return PDFDocument()
    
class WordApplication(Application):
    
    def create_document(self):
        return WordDocument()
    
class ExcelApplication(Application):
    
    def create_document(self):
        return ExcelDocument()
    
if __name__ == '__main__':

    app = PDFApplication()
    app.new_document()

    app = WordApplication()
    app.new_document()

    app = ExcelApplication()
    app.new_document()