#include <iostream>
#include <memory>

// Producto
class Document
{
    public:

    virtual void open() = 0;
    virtual void save() = 0;
    virtual ~Document() {}
};

// Producto Concreto
class PDFDocument : public Document
{
    public:

    void open() override
    {
        std::cout << "Opening PDF document\n";
    }

    void save() override
    {
        std::cout << "Saving PDF document\n";
    }
};

class WordDocument : public Document
{
    public:

    void open() override
    {
        std::cout << "Opening Word document\n";
    }

    void save() override
    {
        std::cout << "Saving Word document\n";
    }
};

class ExcelDocument : public Document
{
    public:

    void open() override
    {
        std::cout << "Opening Excel document\n";
    }

    void save() override
    {
        std::cout << "Saving Excel document\n";
    }
};

// Creador
class Application
{
    public:

    virtual std::unique_ptr<Document> createDocument() = 0;

    void newDocument()
    {
        auto doc = createDocument();
        doc->open();
        doc->save();
    }

    virtual ~Application() {}
};

// Creador Concreto
class PDFApplication : public Application
{
    public:

    std::unique_ptr<Document> createDocument() override
    {
        return std::make_unique<PDFDocument>();
    }
};

class WordApplication : public Application
{
    public:

    std::unique_ptr<Document> createDocument() override
    {
        return std::make_unique<WordDocument>();
    }
};

class ExcelApplication : public Application
{
    public:

    std::unique_ptr<Document> createDocument() override
    {
        return std::make_unique<ExcelDocument>();
    }
};

int main()
{
    std::unique_ptr<Application> app;

    app = std::make_unique<PDFApplication>();
    app->newDocument();

    app = std::make_unique<WordApplication>();
    app->newDocument();

    app = std::make_unique<ExcelApplication>();
    app->newDocument();
    
    return 0;
}