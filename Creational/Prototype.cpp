#include <iostream>
#include <vector>
#include <algorithm>

class Prototype{
public:
    virtual Prototype*  clone()=0;

    virtual std::string getDetails()=0;
    };


class element: public Prototype{
protected:
    std::string color;
    std::string size;
    std::string shape;

public:
    virtual Prototype*  clone()=0;

    std::string getDetails(){
        return color+ "," + size+ "," + shape;
    }
};


class Rectangle:public element{
public:
    Rectangle(Rectangle *r){
        this->color = r->color;
        this->size = r->size;
        this->shape = "Rectangle";
    }

    Rectangle(std::string color,std::string size){
        this->color = color;
        this->size = size;
        this->shape = "Rectangle";

    }

    virtual Prototype*  clone(){
        return new Rectangle(this);
    }
};


class Circle:public element{
public:
    Circle(Circle *r){
        this->color = r->color;
        this->size = r->size;
        this->shape = "Circle";
    }

    Circle(std::string color,std::string size){
        this->color = color;
        this->size = size;
        this->shape = "Circle";

    }

    virtual Prototype*  clone(){
        return new Circle(this);
    }
};




class Application{
public:
    void printBoard(){
        int i=0;
        std::cout<<"________________________\n"<<"My board:\n";
        for (;i<board.size();i++){
            std::cout<<board[i]->getDetails()<<std::endl;
        }
        std::cout<<"________________________\n\n";
    }

    void addObj(Prototype* p){
        if (std::find(board.begin(), board.end(), p)!= board.end()){
            return;
        }
        board.push_back(p);
    }


protected:
    std::vector <Prototype* > board;
};









int main(){

    Application* app = new Application();
    app->printBoard();
    Prototype* c1 = new Rectangle("blue", "big");
    app->addObj(c1);
    app->printBoard();
    app->addObj(c1->clone());
    app->addObj(c1->clone());
    app->addObj(c1->clone());
    app->addObj(c1);
    app->addObj(c1);
    app->printBoard();


    return 1;
}