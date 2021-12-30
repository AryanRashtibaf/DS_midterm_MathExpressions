#include<iostream>
#include"MyStack.h"
#include"MyArrayList.h"
#include"ExpressionProcessor.h"
#include"MyStack.cpp"
#include"MyArrayList.cpp"
#include"ExpressionProcessor.cpp"
using namespace std ; 

int main(){
    string s = "( a + b ) ^ 3 * 2 / 7" ;
    MyArrayList<string>* a = split(s) ;
    MyArrayList<string>* ans ;
    ans = inToPost(*a , true) ;
    for(int i = 0 ; i < ans->getSize() ; i++){
        cout << ans->get(i) << endl ;
    } 

}