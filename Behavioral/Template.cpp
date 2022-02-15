#include <string>
#include <iostream>

using std::string;

class Greeting {
protected:
    string _name;
public:
    Greeting(string name) {
        _name = name;
    }

    virtual void tellAboutYourSelf() = 0;

    virtual void tellAboutYourGoals() = 0;

    virtual void finishTalk() = 0;

    void sayHello() {
        std::cout<<"__________________________"<<std::endl;
        tellAboutYourSelf();
        tellAboutYourGoals();
        finishTalk();
        std::cout<<"__________________________"<<std::endl<<std::endl;

    }

};
    class NormalGreeter: public Greeting{
        virtual void tellAboutYourSelf() {
        std::cout<<"my name is "<< _name<<"."<<std::endl;
        };

        virtual void tellAboutYourGoals() {
            std::cout<<"I want to be a computer scientist."<<std::endl;
        };
        virtual void finishTalk() {
            std::cout<<"Good bay."<<std::endl;
        };
    public:
        NormalGreeter(string c):Greeting(c) {};
    };

class DiggingGreeter: public Greeting{
    virtual void tellAboutYourSelf() {
        std::cout<<"my name is "<< _name<<"."<<std::endl;
        std::cout<<"I like to Skiing."<<std::endl;
        std::cout<<"I was born in Honololo."<<std::endl;
        std::cout<<"I have 2 brothers."<<std::endl;

    };

    virtual void tellAboutYourGoals() {
        std::cout<<"I want to be a computer scientist."<<std::endl;
        std::cout<<"this is always been my passion."<<std::endl;
    };
    virtual void finishTalk() {
        std::cout<<"It was really nice to talk with you."<<std::endl;
        std::cout<<"Good bay."<<std::endl;
    };
public:
    DiggingGreeter(string c):Greeting(c) {};
};



int main(){
    Greeting* g1 = new DiggingGreeter("yoav");
    Greeting* g2 = new DiggingGreeter("liad");
    Greeting* g3 = new NormalGreeter("ori");
    Greeting*  g[] = {g1,g2,g3,new NormalGreeter("yahel")};

    int i =0;
    for (;i<4;i++){
        g[i]->sayHello();
    }

    return 1;
}