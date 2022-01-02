#include<iostream>
#include"InputProcessor.cpp"
using namespace std ; 

int main(){
    InputProcessor inp ; 
    int n ; 
    while (1){
        cin >> n ; 
        if(n == 0)
            return 0 ;
        inp.getNum(n-1) ;
    }
}