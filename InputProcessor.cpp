#include<iostream>
#include"MyStack.h"
#include"MyArrayList.h"
#include"ExpressionProcessor.h"
#include"MyStack.cpp"
#include"MyArrayList.cpp"
#include"ExpressionProcessor.cpp"
using namespace std ; 

struct ConvertType{
    int count = 0 ;
    int priority = 10 ;
    string name ;
};

class InputProcessor{
    private:
        ConvertType c[6] ;
        int per ;
        int k ;
        string s ;
        MyArrayList<string>* sp ;
        MyArrayList<string>* ans ;

        void countAndChap(){
            if(ans == nullptr)
                cout << "Invalid input" << endl ;
            else{
                for(int i = 0 ; i < ans->getSize() ; i++){
                    cout << ans->get(i) << endl ;
                }
                if(c[k].count == 0)
                    c[k].priority = per++ ;
                c[k].count++ ;
            }
        }

        void upToDownSort(){
            for(int i = 0 ; i < 5 ; i++){
                for(int j = 0 ; j < 5 - i ; j++){
                    if(c[j].count < c[j+1].count){
                        swap(&c[j] , &c[j+1]) ;
                    }
                    else if(c[j].count == c[j+1].count){
                        if(c[j].priority > c[j+1].priority)
                            swap(&c[j] , &c[j+1]) ;
                    }
                }
            }
        }

        void downToUpSort(){
            for(int i = 0 ; i < 5 ; i++){
                for(int j = 0 ; j < 5 - i ; j++){
                    if(c[j].count > c[j+1].count){
                        swap(&c[j] , &c[j+1]) ;
                    }
                    else if(c[j].count == c[j+1].count){
                        if(c[j].priority > c[j+1].priority)
                            swap(&c[j] , &c[j+1]) ;
                    }
                }
            }
        }

        void swap(ConvertType* c1 , ConvertType* c2){
            ConvertType* tmp = c1 ; 
            c1 = c2 ; 
            c2 = tmp ;
        }

    public:
        InputProcessor(){
            cout << "Welcome!\nConvert Infix to postfix --> 1\nConvert Postfix to infix --> 2\nConvert Infix to prefix --> 3\nConvert Prefix to infix --> 4\nConvert Postfix to prefix --> 5\nConvert Prefix to postfix --> 6\nHistory --> 7\nExit program --> 0" << endl ;
            per = 1 ;
            c[0].name = "Infix to postfix" ;
            c[1].name = "Postfix to infix";
            c[2].name = "Infix to prefix" ;
            c[3].name = "Prefix to infix" ;
            c[4].name = "Postfix to prefix" ;
            c[5].name = "Prefix to postfix" ;
        }

        void getNum(int n){
            if(n <= 6 && n >= 0){
                cin >> s ;
                sp = split(s) ;
                switch(n){
                    case 0:
                        ans = inToPost(*sp) ;
                        k = n ;
                        countAndChap() ;
                        break ;
                    case 1:
                        ans = postToIn(*sp) ;
                        k = n ;
                        countAndChap() ;
                        break ;
                    case 2:
                        ans = inToPre(*sp) ;
                        k = n ;
                        countAndChap() ;
                        break ;
                    case 3:
                        ans = preToIn(*sp) ;
                        k = n ;
                        countAndChap() ;
                        break ;
                    case 4:
                        ans = postToPre(*sp) ;
                        k = n ;
                        countAndChap() ;
                        break ;
                    case 5:
                        ans = preToPost(*sp) ;
                        k = n ;
                        countAndChap() ;
                        break ;
                    case 6:
                        cout << "Up to down sort : 1\nDown to up sort : 2" << endl ;
                        int t ; 
                        cin >> t ;
                        if(t == 1)
                            upToDownSort() ;
                        else if(t == 2)
                            downToUpSort() ;
                        else
                            cout << "Invalid input." << endl ;
                        break ;
                }
            }
            else{
                cout << "Invalid input\nTry again!" << endl ;
            }
        }

};
