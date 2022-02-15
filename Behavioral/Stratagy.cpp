
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>




class SpeakingWays{
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



class SpeakSlow: public SpeakingWays{
public:
    virtual void setTime(){
        sleepingTime = 4;
    }
    SpeakSlow(): SpeakingWays(){
        setTime();
    }

};

class SpeakNormal: public SpeakingWays{
public:

    virtual void setTime(){
        sleepingTime = 1;
    }
    SpeakNormal(): SpeakingWays(){
        setTime();
    }
};

class Speaker{
    std::string name;
    SpeakingWays* stratagy;
public:
    virtual void singSong(SpeakingWays* speakingWays) {
        speakingWays->singSong();
    }
    virtual void countToTen(SpeakingWays* speakingWays) {
        speakingWays->countToTen();

    }
    Speaker(std::string name) {
        this->name= name;
        this->stratagy= stratagy;
    }
    void setState(SpeakingWays* stratagy){
        this->stratagy= stratagy;
    }
};




int main(){
    std::cout<<"stratagy\n";
    SpeakNormal* normalSpeak = new SpeakNormal();
    SpeakSlow* slowSpeak = new SpeakSlow();
    Speaker* yo = new Speaker("Yo");
    yo->singSong(normalSpeak);
    yo->countToTen(normalSpeak);
    yo->singSong(slowSpeak);
    yo->countToTen(slowSpeak);
    return 1;
}

