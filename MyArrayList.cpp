template<typename T> class MyArrayList{
    private:
        int arraySize , size ; 
        T* data ; 
        void increaseArraySize() ;

    public:
        MyArrayList() ;
        ~MyArrayList() ;
        T get(int index) ;
        void add(T a) ;
        int getSize() ; 
};

template<typename T> MyArrayList<T> :: MyArrayList(){
    size = 0 ; 
    arraySize = 1 ; 
    data = new T[arraySize] ;
}

template<typename T> MyArrayList<T> :: ~MyArrayList(){
    delete []data ;
}

template<typename T> T MyArrayList<T> :: get(int index){
    return data[index] ; 
}

template<typename T> void MyArrayList<T> :: add(T a){
    if(size == arraySize)
        increaseArraySize() ;
    data[size++] = a ; 
}

template<typename T> int MyArrayList<T> :: getSize(){
    return size ; 
}

template<typename T> void MyArrayList<T> :: increaseArraySize(){
    T* tmp = new T[arraySize * 2] ; 
    for(int i = 0 ; i < arraySize ; i++)
        tmp[i] = data[i] ; 
    delete []data ;
    data = tmp ;
}