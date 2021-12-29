template<typename T> class MyStack{
    private:
        int top ; 
        int size ; 
        T* arr ;
        void increaseSize() ;

    public:
        MyStack() ; 
        T getTop() ; 
        T pop() ; 
        int getSize() ;
        void push(T p) ; 
        bool isFull() ; 
        bool isEmpty() ; 
};

template<typename T> void MyStack<T> :: increaseSize(){
    T* tmp = arr ;
    size *= 2 ;  
    arr = new int[size] ; 
    for(int i = 0 ; i < size / 2 ; i++)
        arr[i] = tmp[i] ; 
    delete []tmp ;
}

template<typename T> MyStack<T> :: MyStack(){
    size = 2 ; 
    top = -1 ; 
    arr = new int[size] ;
}

template<typename T> T MyStack<T> :: getTop(){
    if (!isEmpty()){
        return arr[top] ; 
    }
    throw __EXCEPTIONS;
}

template<typename T> T MyStack<T> :: pop(){
    if(!isEmpty())
        return arr[top--] ;
    throw __EXCEPTIONS;
}

template<typename T> int MyStack<T> :: getSize(){
    return top + 1 ;
}

template<typename T> void MyStack<T> :: push(T p){
    if(isFull())
        increaseSize() ;
    arr[++top] = p ;
}

template<typename T> bool MyStack<T> :: isFull(){
    if(size == top+1)
        return true ;
    return false ;
}

template<typename T> bool MyStack<T> :: isEmpty(){
    if(top < 0)
        return true ; 
    return false ;
}



