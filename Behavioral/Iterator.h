//
// Created by tamir on 12/02/2022.
//

#ifndef DESIGNPATTERNS_ITERATOR_H
#define DESIGNPATTERNS_ITERATOR_H

class SpecialVector;

class Iterator{
public:
    virtual bool hasNext()=0;
    virtual   std::vector<int>::iterator getNext()=0;
};

class IterableCollection{
public:
    virtual  Iterator* createIterator()=0;
};


class EvenIterator: public Iterator{
private:
    std::vector<int>::iterator itOdd;
    std::vector<int>::iterator itEven;
    SpecialVector * vector;
public:

    virtual bool hasNext();
    virtual   std::vector<int>::iterator  getNext();

    EvenIterator(SpecialVector *pVector);
};


class SpecialVector: IterableCollection {

public:
    std::vector<int> odd;
    std::vector<int> even;

    Iterator *createIterator();

    void pushBack(int num){
        if (num%2==0){
            even.push_back(num);
        }
        else{
        odd.push_back(num);
        }
    }


    void popBack(int num){
        if (num%2==0){
            even.pop_back();
        }
        else{

        odd.pop_back();
        }
    }

};
#endif //DESIGNPATTERNS_ITERATOR_H
