#include <iostream>
using std::cout;



class Shirt{
public:
    virtual void printMyColor()=0;
protected:
     std::string color;
};


class Shoe{
public:
    virtual void printMyColor()=0;
protected:
    std::string color;
};

class AbstractFactory{
public:
    virtual Shoe * createShoes()=0;
    virtual Shirt * createShirts()=0;
};

class YellowShirt: public Shirt{
    virtual void printMyColor(){
        cout << "I am a " << color<< " Shirt\n";
    };

public:
    YellowShirt(){
        cout<<"Yellow shirt created!\n";
    }
};

class YellowShoe:public Shoe{

    virtual void printMyColor(){
        cout << "I am a " << color<< " Shoe\n";
    };
public:
    YellowShoe(){
        cout<<"Yellow shoe created!\n";
    }
};


class BlueShirt: public Shirt{
    virtual void printMyColor(){
        cout << "I am a " << color<< " Shirt\n";
    };
public:
    BlueShirt(){
        cout<<"Blue shirt created!\n";
    }
};

class BlueShoe: public Shoe{

    virtual void printMyColor(){
        cout << "I am a " << color<< " Shoe\n";
    };
public:
    BlueShoe(){
        cout<<"Blue shoe created!\n";
    }
};



class YellowFactory: public AbstractFactory{
public:
    virtual Shoe* createShoes(){
        return  new YellowShoe();
    };
    virtual Shirt * createShirts(){
        return new YellowShirt();
    };
};




class BlueFactory: AbstractFactory{
public:
    virtual Shoe* createShoes(){
        return  new BlueShoe();
    };
    virtual Shirt * createShirts(){
        return new BlueShirt();
    };
};













int main() {
    BlueFactory* bFact = new BlueFactory();
    bFact->createShirts();
    bFact->createShirts();
    bFact->createShirts();
    bFact->createShirts();

    bFact->createShoes();
    bFact->createShoes();
    bFact->createShoes();
    bFact->createShoes();
    bFact->createShoes();
    bFact->createShoes();


    return 0;
}