#include<iostream>
#include"MyStack.h"
#include"MyArrayList.h"
#include"ExpressionProcessor.h"
#include"MyStack.cpp"
#include"MyArrayList.cpp"
#include"ExpressionProcessor.cpp"
using namespace std ; 

int main(){
    string s = " * + A B - C D " ;
    MyArrayList<string>* a = split(s) ;
    MyArrayList<string>* ans ;
    ans = preToIn(*a , true) ;
    cout << ans->get(ans->getSize()-1) << endl ; 

}