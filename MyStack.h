#ifndef MyStack_H
#define MyStack_H

#include<string>
using namespace std ;
template<typename T> class MyStack{
    private:
        int top ; 
        int size ; 
        T* arr ;
        void increaseSize() ;

    public:
        MyStack() ; 
        T getTop() ; 
        T pop() ; 
        int getSize() ;
        void push(T p) ; 
        bool isFull() ; 
        bool isEmpty() ; 
        string* toStr() ;

};

#endif