#include"ExpressionProcessor.h"
using namespace std ;

MyArrayList<string>* preToIn(MyArrayList<string> &pre){
    static MyArrayList<string>* answers ;
    answers = new MyArrayList<string>() ;
    MyStack<string> st ;
    bool isValid = true ;

    for(int i = pre.getSize()-1 ; i >= 0 ; i--){
        if(isOperator(pre.get(i))){
            if(st.getSize() < 2)
                return nullptr ;
            

            string s1 = st.pop() ;
            string s2 = st.pop() ; 
            string tmp = "( " + s1 + pre.get(i) + s2 + ") "  ; 

            st.push(tmp) ;
        }    
        else{
            st.push(pre.get(i)) ; 
        }

        string tmp = *st.toStr() ;
        answers->add(tmp) ;
    }

    if(st.getSize() != 1)
        return nullptr ; 
    return answers ;
}

MyArrayList<string>* postToPre(MyArrayList<string> &post){
    static MyArrayList<string>* answers ;
    answers = new MyArrayList<string>() ;
    MyStack<string> st ; 
    bool isvalid = true ;

    for(int i = 0 ; i < post.getSize() ; i++){
        if(isOperator(post.get(i))){
            if(st.getSize() < 2)
                return nullptr ;
            
            string s2 = st.pop() ; 
            string s1 = st.pop() ;
            string tmp = post.get(i) + s1 + s2;
            

            st.push(tmp) ; 
        }
        else{
            st.push(post.get(i)) ;
        }

        string tmp = *st.toStr() ;
        answers->add(tmp) ;
    }    

    if(st.getSize() != 1)
        return nullptr ;
    return answers ;
}

MyArrayList<string>* inToPost(MyArrayList<string> &in){
    MyStack<string> post ;
    MyStack<string> operators ;
    static MyArrayList<string>* answers ; 
    answers = new MyArrayList<string>() ;

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

        else if(in.get(i) == "( "){
            operators.push(in.get(i)) ;
        }

        else if(in.get(i) == ") "){
            while(operators.getTop() != "( "){
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
        answers->add(tmp) ;
    }
    while(operators.getSize() != 0)
        post.push(operators.pop()) ;
    string tmp = "Operators stack: " + *operators.toStr() + "\n" ;
    tmp += "Postfix stack: " + *post.toStr() + "\n_________________________________" ;
    answers->add(tmp) ;
    return answers ; 
}

MyArrayList<string>* preToPost(MyArrayList<string> &pre){
    static MyArrayList<string>* answers ; 
    answers = new MyArrayList<string>() ;
    MyArrayList<string>* ans1 = preToIn(pre) ;
    if(ans1 == nullptr)
        return nullptr ;
    
    for(int i = 0 ; i < ans1->getSize() ; i++){
        answers->add("Prefix to infix:\n" + ans1->get(i)) ;
    }

    string tmp = ans1->get(ans1->getSize()-1) ;
    MyArrayList<string>* in = split(tmp) ; 
    MyArrayList<string>* ans2 = inToPost(*in) ;
    
    for(int i = 0 ; i < ans2->getSize() ; i++){
        answers->add("Infix to postfix:\n" + ans2->get(i)) ; 
    }

    delete ans1 ;
    delete ans2 ;
    return answers ;
} 

MyArrayList<string>* postToIn(MyArrayList<string> &post){
    static MyArrayList<string>* answers ; 
    answers = new MyArrayList<string>() ;
    MyArrayList<string>* ans1 = postToPre(post) ;
    if(ans1 == nullptr)
        return nullptr ;
    
    for(int i = 0 ; i < ans1->getSize() ; i++){
        answers->add("Postfix to prefix:\n" + ans1->get(i)) ;
    }
    string tmp = ans1->get(ans1->getSize()-1) ;
    MyArrayList<string>* pre = split(tmp) ; 
    MyArrayList<string>* ans2 = preToIn(*pre) ;

    for(int i = 0 ; i < ans2->getSize() ; i++){
        answers->add("Prefix to infix:\n" + ans2->get(i)) ; 
    }

    delete ans1 ;
    delete ans2 ;
    return answers ;
}

MyArrayList<string>* inToPre(MyArrayList<string> &in){
    static MyArrayList<string>* answers ; 
    answers = new MyArrayList<string>() ;
    MyArrayList<string>* ans1 = inToPost(in) ;
    if(ans1 == nullptr)
        return nullptr ;
    
    for(int i = 0 ; i < ans1->getSize() ; i++){
        answers->add("Infix to postfix:\n" + ans1->get(i)) ;
    }
    
    string t = ans1->get(ans1->getSize()-1) ;
    string* tmp = findPostfix(t) ;
    MyArrayList<string>* post = split(*tmp) ; 
    MyArrayList<string>* ans2 = postToPre(*post) ;
    
    for(int i = 0 ; i < ans2->getSize() ; i++){
        answers->add("Postfix to prefix:\n" + ans2->get(i)) ; 
    }

    delete ans1 ;
    delete ans2 ;
    return answers ;
}


MyArrayList<string>* split(string s){
    static MyArrayList<string>* a;
    a = new MyArrayList<string>() ;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != ' ' && s[i] != ',' && s[i] != '\n'){
            string tmp = "" ;
            while(i < s.length() && s[i] != ' ' && s[i] != ',' && s[i] != '\n'){
                tmp += s[i] ;
                i++ ;
            }
            tmp += " " ;
            a->add(tmp) ;
        }
    }
    return a ;
}

bool isOperator(string s){
    if(s == "+ " || s == "- " || s == "/ " || s == "* " || s == "^ ")
        return true ; 
    return false ;
}

int getPeriority(string s){
    if(s == "^ ")
        return 4 ; 
    if(s == "* " || s == "/ ")
        return 3 ;
    if(s == "+ " || s == "- ")
        return 2 ; 
    return 0 ; 
}     

bool validInfix(MyArrayList<string> &in){
    int oper = 0 ; 
    int p = 0 ;
    for(int i = 0 ; i < in.getSize() ; i++){
        if(in.get(i) == "( ")
            p++ ;
        else if(in.get(i) == ") ")
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

string* findPostfix(string s){
    int i = 0 ; 
    static string ans ; 
    while(s[i] != '\n')
        i++ ;
    while(s[i] != ':')
        i++ ;
    ans = "" ; 
    i++ ;
    while(s[i] != '\n'){
        ans += s[i] ; 
        i++ ;
    }
    return &ans ;
}