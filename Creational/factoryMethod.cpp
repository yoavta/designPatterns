#include <iostream>

class Document{
protected:
    std::string file = "";
    bool status = false;

public:
    virtual void  open()=0;

    virtual void  close()=0;
    virtual void  save(){
        std::cout << "documents saved!" << std::endl;
    }
    void virtual revert(){
        std::cout << "documents revert!" << std::endl;
    }
};


class SignDoc : public Document{
    virtual void  open(){
        std::cout <<"@#$@#$@$\n";
        file = "@#$@#$@$";
        status = true;
    }
    virtual void  close(){
        file = "closed signed";
        status = false;
    }
};

class AlphaDoc :public Document{
    virtual void  open(){
        std::cout <<"QWEASDZXCASD\n";
        file = "QWEASDZXCASD";
        status = true;
    }
    virtual void  close(){
        file = "closed alpha";
        status = false;
    }
};


class Application{
protected:
    bool status = false;
    Document* doc;

public:
    virtual Document*  createDocument()=0;

    virtual void newDocument(){
        doc = createDocument();
    }
    void virtual openDocument(){
        std::cout <<"openDocument\n";
        doc->open();

    }
};


class SignApp : public Application{
    virtual Document*  createDocument(){
        Document* doc = new SignDoc();
        return doc;
    }
};

class AlphaApp : public Application{
    virtual Document*  createDocument(){
        Document* doc = new AlphaDoc();
        return doc;
    }
};



int main() {
    SignApp* sApp = new SignApp();
    sApp->newDocument();
    sApp->openDocument();

    AlphaApp* aApp = new AlphaApp();
    aApp->newDocument();
    aApp->openDocument();

    return 0;
}