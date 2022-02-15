
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>




class StudentState{
protected:
    int sleepingTime;
    std::vector<std::string> song={
            "Oh", "no,", "not", "I," ,"I" ,"will", "survive\n"
                                              ,"Oh,", "as" ,"long" ,"as", "I" ,"know" ,"how", "to", "love,", "I", "know" ,"I'll", "stay", "alive\n"};

public:
    virtual void setTime()=0;

    virtual void singSong(){
        int i=0;
        for (;i<song.size();i++){
            std::cout<<song[i]<<" "<<std::flush;;
            std::this_thread::sleep_for(std::chrono::seconds(sleepingTime));
        }
        std::cout<<std::endl;
    }
    virtual void countToTen(){
        int i=0;
        for (;i<11;i++){
            std::cout<<i<<" "<<std::flush;;
            std::this_thread::sleep_for(std::chrono::seconds(sleepingTime));
        }
        std::cout<<std::endl;
    }

    };



class Student{
std::string name;
StudentState* state;
public:
    virtual void singSong(){
        this->state->singSong();
    }
    virtual void countToTen(){
        this->state->countToTen();

    }
    Student(std::string name,StudentState* state){
        this->name= name;
        this->state= state;
    }
    void setState(StudentState* state){
        this->state= state;
    }
};




class TiredStudent: public StudentState{
public:
    virtual void setTime(){
        sleepingTime = 4;
    }
    TiredStudent():StudentState(){
        setTime();
    }

};

class NormalStudent: public StudentState{
public:

    virtual void setTime(){
        sleepingTime = 1;
    }
    NormalStudent():StudentState(){
        setTime();
    }
};

int main(){
    NormalStudent* normalStudent = new NormalStudent();
    TiredStudent* tiredStudent = new TiredStudent();
    Student* yo = new Student("Yo",normalStudent);
    yo->singSong();
    yo->countToTen();
    yo->setState(tiredStudent);
    yo->singSong();
    yo->countToTen();
    return 1;
}

