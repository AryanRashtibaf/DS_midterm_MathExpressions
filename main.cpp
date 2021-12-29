#include<iostream>
#include"MyStack.cpp"
#include"MyArrayList.cpp"
using namespace std ; 

int main(){
    MyArrayList<int> a ; 
    a.add(2) ; 
    a.add(4) ;
    cout << a.get(0) << a.get(1) << a.getSize() << endl ;
}