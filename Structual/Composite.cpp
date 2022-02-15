#include <vector>
#include <iostream>

class Soldier{
protected:
    int _id;
    std::vector<Soldier*> _kids;
public:
    Soldier(int id){
        _id = id;
    }
    virtual void salute()=0;
    virtual void printNumber()=0;
    int getId(){
        return _id;
    }
};


class HeadOfGroup: public Soldier{
public:
    HeadOfGroup(int id): Soldier(id){};
    virtual void add(Soldier* soldier)=0;
    virtual void remove(Soldier* soldier)=0;
    virtual Soldier * getChild(int id)=0;
};

class Commander: public HeadOfGroup{

public:
    Commander(int id): HeadOfGroup(id){};
    virtual void salute(){
        std::cout<<"I AM CAPTAIN! I DONT SALUTE!"<<std::endl<<std::endl;
        int i =0;
        for(;i<_kids.size();i++){
            _kids[i]->salute();
        }
    }
    virtual void printNumber(){
        std::cout<<"I am a Commander and my number is: "<<_id<<"."<<std::endl<<std::endl;

        int i =0;
        for(;i<_kids.size();i++){
            _kids[i]->printNumber();
        }
    };
    virtual void add(Soldier* soldier){
        _kids.push_back(soldier);
    };
    virtual void remove(Soldier* soldier){
        std::vector<Soldier*>::iterator it;
        for (;it!=_kids.end();it++){
            if (*it==soldier){
                _kids.erase(it);
            }
        }
    };
    virtual Soldier * getChild(int id){
        if (_id==id){
            return this;
        }
        std::vector<Soldier*>::iterator it= _kids.begin();
        for (;it!=_kids.end();it++){
            if ((*it)->getId()==id){
                return *it;
            }
        }
        return nullptr;
    }
};

class Warrior: public Soldier{
public:
    Warrior(int id): Soldier(id){};
    virtual void salute(){
        std::cout<<"HI HI CAPTAIN! I am ready to fight!"<<std::endl;
        std::cout<<"I am a Warrior!"<<std::endl<<std::endl;
    }
    virtual void printNumber(){
        std::cout<<"I am a Warrior and my number is: "<<_id<<"."<<std::endl<<std::endl;
    }
};


class CoffeeMaker: public Soldier{
public:
    CoffeeMaker(int id): Soldier(id){};
    virtual void salute(){
        std::cout<<"HI HI CAPTAIN! want coffee?"<<std::endl;
        std::cout<<"I am a CoffeeMaker!"<<std::endl<<std::endl;
    }
    virtual void printNumber(){
        std::cout<<"I am a CoffeeMaker and my number is: "<<_id<<"."<<std::endl<<std::endl;
    }
};


int main(){
//    building army
    HeadOfGroup* head = new Commander(1);
    head->add(new CoffeeMaker(2));
    head->add(new CoffeeMaker(3));
    head->add(new Warrior(4));
    head->add(new Commander(5));
    ((HeadOfGroup*)head->getChild(5))->add(new CoffeeMaker(6));
    ((HeadOfGroup*)head->getChild(5))->add(new CoffeeMaker(7));
    head->printNumber();
    head->salute();

}