#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
class Subject;
class Observable{
public:
    virtual void update(Subject* subject)=0;
};

class Subject{
protected:
    std::vector <Observable*> observers;

public:
    virtual void addListener(Observable* obs){
        observers.push_back(obs);
    }
    virtual void deleteListener(Observable* obs){
        std::remove(observers.begin(), observers.end(),obs);
    }

    virtual void notifyAll() {
        int i = 0;
        int size = observers.size();
        std::cout << "____________________________________________\n";

        for (; i < size; i++) {
            observers[i]->update(this);
        }
        std::cout << "____________________________________________\n\n";
    }
    virtual int getState()=0;

    };



class GradesSystem:public Subject{
protected:
    int _grade;
public:
    void setGrade(int grade){
        this->_grade = grade;
        notifyAll();
    }
    int getGrade(){
        return this->_grade;
    }

    virtual int getState(){
        return getGrade();
    };

};


class Student{
protected:
    std::string name;
    int nervousLevel = 0;
    int lastGrade;

public:
    Student(std::string name){
        this->name= name;
    }

    virtual void printStatus(){
        std::cout<<"My name is "<<name<<". and I am ";
        int temp = nervousLevel;
        for (;temp>0;temp--){
            std::cout<<"super ";
        }
        std::cout<<"nervous!\n";
    }
};


class CalmStudent:public Observable, public Student{
protected:
    virtual void update(Subject *subject){
        nervousLevel++;
        printStatus();

    }

public:
    CalmStudent(std::string name):Student(name){;};
};


class CrazyStudent:public Observable, Student{
protected:
    virtual void update(Subject* subject){
        nervousLevel=nervousLevel*2;
        lastGrade = subject->getState();
        printStatus();
    }

public:
    virtual void printStatus(){
        Student::printStatus();
        std::cout<<"OMG my grade is "<< lastGrade<<"!!\n";
    }
    CrazyStudent(std::string name):Student(name){nervousLevel++;};
};


int main(){
    GradesSystem* gradesSystem = new GradesSystem();
    CalmStudent* Or = new CalmStudent("Or");
    CalmStudent* Yoav = new CalmStudent("Yoav");
    CrazyStudent* Yotam = new CrazyStudent("Yotam");

    gradesSystem->addListener(Or);
    gradesSystem->addListener(Yoav);
    gradesSystem->addListener(Yotam);


    while (true){
        int temp;
        std::cout<<"please insert new grade:";
        std::cin>>temp;
        gradesSystem->setGrade(temp);
    }


}