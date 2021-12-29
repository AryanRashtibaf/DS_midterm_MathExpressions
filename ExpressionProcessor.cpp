#include<string>
#include"MyArrayList.cpp"

using namespace std ;
class ExpresionProcessor{
    public:
        static bool isOperator(string s) ;
        static bool isFunction(string s) ;
        static MyArrayList<string>* split(string s) ;
        static string* preToIn(MyArrayList<string> pre , bool isCountable) ;
        static string* inToPost(MyArrayList<string> in , bool isCountable) ; 
        static string* postToPre(MyArrayList<string> post , bool isCountable) ; 
        static string* preToPost(MyArrayList<string> pre) ; 
        static string* postToIn(MyArrayList<string> post) ;
        static string* inToPre(MyArrayList<string> in) ;
};