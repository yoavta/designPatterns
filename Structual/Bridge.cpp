#include <iostream>
class NoodlesMakerImplementation{

public:
    virtual void impMiseOnPlace()=0;

// Mise On Place = Make preparation for cooking.
virtual void impCook()=0;
};

class NormalNoodles: public NoodlesMakerImplementation{
public:
    virtual void impMiseOnPlace(){
        std::cout<<"Make preparations:"<<std::endl;
        std::cout<<"cutting carrots......"<<std::endl;
        std::cout<<"chopping garlic......"<<std::endl;
        std::cout<<"chopping chicken......"<<std::endl;
        std::cout<<"making sauce......"<<std::endl<<std::endl;
    }

    virtual void impCook(){
        std::cout<<"cooking:"<<std::endl;
        std::cout<<"......"<<std::endl;
        std::cout<<"Ready!!...... Normal Noodles ready to go!"<<std::endl<<std::endl;
    }
};

class VegetarianSpicyNoodles: public NoodlesMakerImplementation{
public:
    virtual void impMiseOnPlace(){
        std::cout<<"Make preparations:"<<std::endl;
        std::cout<<"cutting carrots......"<<std::endl;
        std::cout<<"chopping garlic......"<<std::endl;
        std::cout<<"chopping tofu......"<<std::endl;
        std::cout<<"chopping spicyChili......"<<std::endl;
        std::cout<<"making sauce......"<<std::endl<<std::endl;
    }

    virtual void impCook(){
        std::cout<<"cooking:"<<std::endl;
        std::cout<<"......"<<std::endl;
        std::cout<<"Ready!!...... Vegetarian Spicy Noodles ready to go!"<<std::endl<<std::endl;
    }
};




class NoodlesMaker{
    NoodlesMakerImplementation* _noodlesMakerImplementation;
public:
    NoodlesMaker(NoodlesMakerImplementation* noodlesMakerImplementation){
        _noodlesMakerImplementation = noodlesMakerImplementation;
    }
    virtual void miseOnPlace(){// Mise On Place = Make preparation for cooking.
        _noodlesMakerImplementation->impMiseOnPlace();
    }
    virtual void cook(){
        _noodlesMakerImplementation->impCook();
    };
};


class NoodlesForOne: public NoodlesMaker{
public:
    NoodlesForOne(NoodlesMakerImplementation* noodlesMakerImplementation): NoodlesMaker(noodlesMakerImplementation){};
    virtual void makeDish(){
        miseOnPlace();
        cook();
    }
};

class NoodlesForFamily: public NoodlesMaker{
protected:
    int _sizeOfFamily;
public:
    NoodlesForFamily(int sizeOfFamily,NoodlesMakerImplementation* noodlesMakerImplementation): NoodlesMaker(noodlesMakerImplementation){
        _sizeOfFamily=sizeOfFamily;
    }
    virtual void makeDish(){
        int i = 0;
        for (;i<_sizeOfFamily;i++){
        miseOnPlace();
        cook();
        }
    }
};



int main(){
    NoodlesMakerImplementation* noodlesMakerImplementation = new VegetarianSpicyNoodles();
    NoodlesMaker* noodlesMaker = new NoodlesForOne(noodlesMakerImplementation);
    noodlesMaker->miseOnPlace();
    noodlesMaker->cook();
}
