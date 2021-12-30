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

MyArrayList<string>* inToPost(MyArrayList<string> &in , bool isCountable){
    MyStack<string> post ;
    MyStack<string> operators ;
    static MyArrayList<string> answers ; 

    if(!validInfix(in))
        return nullptr ; 

    for(int i = 0 ; i < in.getSize() ; i++){
        if(isOperator(in.get(i))){
            while(operators.getSize() > 0 && getPeriority(operators.getTop()) >= getPeriority(in.get(i)) && operators.getTop() != "(" && operators.getTop() != ")"){
                string tmp = operators.pop() ;
                post.push(tmp) ; 
            }
            operators.push(in.get(i)) ;
        }

        else if(in.get(i) == "("){
            operators.push(in.get(i)) ;
        }

        else if(in.get(i) == ")"){
            while(operators.getTop() != "("){
                string tmp = operators.pop() ; 
                post.push(tmp) ; 
            }
            operators.pop() ;
        }

        else{
            post.push(in.get(i)) ;
        }
        string tmp = "Operators stack: " + *operators.toStr() + "\n" ;
        tmp += "Postfix stack: " + *post.toStr() + "\n_________________________________" ;
        answers.add(tmp) ;
    }

    while(operators.getSize() == 0)
        post.push(operators.pop()) ;

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

int getPeriority(string s){
    if(s == "^")
        return 4 ; 
    if(s == "*" || s == "/")
        return 3 ;
    if(s == "+" || s == "-")
        return 2 ; 
    return 0 ; 
}     

bool validInfix(MyArrayList<string> &in){
    int oper = 0 ; 
    int p = 0 ;
    for(int i = 0 ; i < in.getSize() ; i++){
        if(in.get(i) == "(")
            p++ ;
        else if(in.get(i) == ")")
            p-- ;
        else if(isOperator(in.get(i)))
            oper++ ; 
        else
            oper-- ;
        if(oper > 0 || oper < -1 || p < 0)
            return false ; 
    }
    if(oper == -1 && p == 0)
        return true ;

    return false ;
}

