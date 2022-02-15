#include <vector>
#include <iostream>
#include "Iterator.h"
using std::vector;

class SpecialVector;




std::vector<int>::iterator EvenIterator::getNext() {
    if(itEven != vector->even.end()){
        return itEven++;
    }
    else{
        return itOdd++;
    }
}

bool EvenIterator::hasNext() {

    if (itEven == vector->even.end() && itOdd==vector->odd.end() ){
    return false;
    }
    return true;
}

EvenIterator::EvenIterator(SpecialVector *pVector) {
    itEven = pVector->even.begin();
    itOdd= pVector->odd.begin();
    vector = pVector;
}


Iterator *SpecialVector::createIterator() {
    return new EvenIterator(this);
}


int main(){
    SpecialVector * vec = new SpecialVector();
    vec->pushBack(1);
    vec->pushBack(2);
    vec->pushBack(3);
    vec->pushBack(4);
    vec->pushBack(5);
    vec->pushBack(6);
    Iterator* it = vec->createIterator();

    while(it->hasNext()){
        std::cout<<*it->getNext()<<std::endl;
    }

    return 1;
}

