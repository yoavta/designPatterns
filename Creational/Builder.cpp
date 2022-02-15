#include <iostream>

class CookieProcess{
protected:
    std::string res = "";
public:
    virtual void makeBase() = 0;
    virtual void reset(){
        res = "";
    };
    virtual std::string getResult(){
        return res;
    }
    virtual void makeTopping() = 0;
};


class VanillaCookie: public  CookieProcess{
public:
    virtual void makeBase(){
        res = res + "| vanilla base | ";
        std::cout <<" creating vanilla base!\n";
    }
    virtual void makeTopping(){
        res = res + "| vanilla Topping | ";
        std::cout <<" creating vanilla Topping!\n";
    }
};



class FruitCookie: public  CookieProcess{
public:
    virtual void makeBase(){
        res = res + "| Fruit Base | ";
        std::cout <<" creating Fruit base!\n";
    }
    virtual void makeTopping(){
        res = res + "| Fruit Topping | ";
        std::cout <<" creating Fruit Topping!\n";
    }
};


class CookieMaker{

public:
    std::string bakeLayersCake(CookieProcess * cp){
        cp->reset();
        cp->makeBase();
        cp->makeTopping();
        cp->makeBase();
        cp->makeTopping();
        cp->makeBase();
        cp->makeTopping();
        return  cp->getResult();
    }

    std::string bakeNormalCake(CookieProcess * cp){
        cp->reset();
        cp->makeBase();
        cp->makeTopping();
        return  cp->getResult();
    }
};










int main(){

    CookieMaker* cM = new CookieMaker();

    CookieProcess* vanilla = new VanillaCookie();
    std::string res = cM->bakeLayersCake(vanilla);
    std::cout << "Result: "<< res<< std::endl<< std::endl;

    CookieProcess* fruit = new FruitCookie();


    std::string res2 = cM->bakeLayersCake(fruit);
    std::cout << "Result: "<< res2<< std::endl<< std::endl;



    std::string res3 = cM->bakeNormalCake(fruit);
    std::cout << "Result: "<< res2<< std::endl<< std::endl;

    return 1;
}