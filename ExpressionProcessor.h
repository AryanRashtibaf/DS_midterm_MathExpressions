#ifndef ExpressionProcessor_H
#define ExpressionProcessor_H
#include<string>
#include"MyArrayList.h"
#include"MyStack.h"

using namespace std ;
    
bool isOperator(string s) ;
int getPeriority(string s) ;
bool validInfix(MyArrayList<string> &in) ;
MyArrayList<string>* split(string s) ;
MyArrayList<string>* preToIn(MyArrayList<string> &pre , bool isCountable) ;
MyArrayList<string>* inToPost(MyArrayList<string> &in , bool isCountable) ; 
MyArrayList<string>* postToPre(MyArrayList<string> &post , bool isCountable) ; 
MyArrayList<string>* preToPost(MyArrayList<string> &pre) ; 
MyArrayList<string>* postToIn(MyArrayList<string> &post) ;
MyArrayList<string>* inToPre(MyArrayList<string> &in) ;


#endif