#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

class Editor{
public:
    std::string board="";

    void setBoard(std::string s){
        board = s;
    }
    void print(){
        std::cout<<"board is:"<<board<<std::endl;
    }
};


class Command{
protected:
Editor* editor;


public:
        Command(Editor* editor) {
this->editor = editor;
}
    virtual void execute()=0;
};

class AddStringCommand: public Command{ ;

    virtual void execute(){
        std::cout<<"insert string\n";
        std:: string temp;
        std::cin>>temp;
        editor->board = editor->board +  temp;

    }

public:
    AddStringCommand(Editor* editor):Command(editor){}
};


class DeleteCommand: public Command{
public:

    DeleteCommand(Editor* editor):Command(editor){};
    virtual void execute(){
        std::cout<<"insert number of chars for deletion\n";
        int temp;
        std::cin>>temp;
        std::string str= editor->board;


        try{
            str.erase(str.length()-temp);
        }
        catch (...){
            editor->board = "";
            return;
        }
//        while (temp){
//            try{
//                str.pop_back();
//                temp = temp -1;
//            }
//            catch (...){
//                editor.board = "";
//                return;
//            }
//        }
        editor->board = str;

    }
};

class Application{
private:
    Editor * editor;

public:

    void addEditor(Editor* editor){
        this->editor =editor;
    }
    void executeCommand(Command* c){
        c->execute();
    }
};



int main(){
    Application* app = new Application();
    Editor* editor = new Editor();
    app->addEditor(editor);
    Command* insert = new AddStringCommand(editor);
    Command* del = new DeleteCommand(editor);




    while (true){
        app->executeCommand(insert);
        app->executeCommand(del);
        editor->print();
    }

    return 1;
}