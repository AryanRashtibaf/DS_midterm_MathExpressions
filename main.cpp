#include<iostream>
#include"MyStack.h"
#include"MyArrayList.h"
#include"ExpressionProcessor.h"
#include"MyStack.cpp"
#include"MyArrayList.cpp"
#include"ExpressionProcessor.cpp"
using namespace std ; 

int main(){
    string s = "/ * - + a b c ^ d ^ e f g" ;
    MyArrayList<string>* a = split(s) ;
    MyArrayList<string>* ans ;
    ans = preToPost(*a) ;
    for(int i = 0 ; i < ans->getSize() ; i++){
        cout << ans->get(i) << endl ;
    }
}