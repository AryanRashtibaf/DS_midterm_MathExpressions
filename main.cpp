#include<bits/stdc++.h>
#include"MyStack.hpp"
using namespace std ; 

int main(){
    MyStack<int> s ; 
    for (int i = 0; i < 5; i++)
    {
        s.push(i) ; 
    }
    try{
    cout << s.getSize() << endl ;
    cout << s.getTop() << endl ;
    cout << s.isFull() << endl ;
    cout << s.isEmpty() << endl ;
    cout << "gf" << endl;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ; 
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ; 
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ;
    cout << s.pop() << endl ; 
    cout << s.pop() << endl ;
    cout << "df" << endl ;
    }
    catch(...){
        cout << "gdfggfgfgf" << endl ;
    }
}