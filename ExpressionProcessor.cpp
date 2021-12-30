#include"ExpressionProcessor.h"
using namespace std ;

MyArrayList<string>* preToIn(MyArrayList<string> &pre , bool isCountable){
    static MyArrayList<string> answers ;
    MyStack<string> st ;
    bool isValid = true ;

    for(int i = pre.getSize()-1 ; i >= 0 ; i--){
        if(isOperator(pre.get(i))){
            if(st.getSize() < 2)
                return nullptr ;

            string s1 = st.pop() ;
            string s2 = st.pop() ; 
            string tmp = "(" + s1 + pre.get(i) + s2 + ")" ; 

            st.push(tmp) ;
        }    
        else{
            st.push(pre.get(i)) ; 
        }
        string ss = *st.toStr() ;
        answers.add(ss) ;
    }

    if(st.getSize() != 1)
        return nullptr ; 
    return &answers ;
}

MyArrayList<string>* split(string s){
    static MyArrayList<string> a ;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != ' '){
            string tmp = "" ;
            while(i < s.length() && s[i] != ' '){
                tmp += s[i] ;
                i++ ;
            }
            
            a.add(tmp) ;
        }
    }
    return &a ;
}

bool isOperator(string s){
    if(s == "+" || s == "-" || s == "/" || s == "*" || s == "^")
        return true ; 
    return false ;
}