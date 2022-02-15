#include <iostream>

class God {
private:
    static God *instance;

    God() {
        std::cout << "god is first created!\n";
        instance = this;
    }

public:
    static God *createGod();
};


God* God::createGod() {
    if (instance!= nullptr){
        std::cout<<"god already created!\n";
        return instance;
    }
    God();
    return instance;
}
God* God::instance =0;


int main(){
    God* g = God::createGod();
    God* g2 = God::createGod();
    God* g3 = God::createGod();
}