#ifndef MyArrayList_H
#define MyArrayList_H

template<typename T> class MyArrayList{
    private:
        int arraySize , size ; 
        T* data ; 
        void increaseArraySize() ;

    public:
        MyArrayList() ;
        ~MyArrayList() ;
        T get(int index) ;
        void add(T a) ;
        int getSize() ; 
};

#endif