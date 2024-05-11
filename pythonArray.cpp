#include <iostream>
#include <sstream>

template <typename T, int M>

class Point{
    private:
        int Asize = M;
        T* Array = nullptr;
        friend std::ostream& operator<<(std::ostream& os, const Point& arr) {
        os << '[';
        for (int i = 0; i < arr.Asize; ++i) {
            os << arr.Array[i];
            if (i < arr.Asize - 1) {
                os << ", ";
            }
        }
        os << ']';
        return os;
    }

    public:
        Point(){
            Array = new T[Asize];
        }

        T* append(T somevalue){
            delete []Array;
            ++Asize;
            Array = new T[Asize];
            *(Array + (Asize-1)) = somevalue;
            return Array;            
        }

        T* putfront(T somevalue){
            T* oldvalues = new T[Asize];
            for(int i = 0; i < Asize; ++i){
                oldvalues[i] = Array[i];
            }

            delete []Array;
            ++Asize;
            Array = new T[Asize];
            *(Array + 0) = somevalue;

            for(int i = 1; i < Asize; ++i){
                Array[i] = oldvalues[i-1];
            }
            delete []oldvalues;
            return Array;  

        }

        T* insert(int index, T somevalue){
            if(index > Asize || index < 0){
                std::cout << "Out of scope\n";
                return NULL;
            }

            T* oldvalues = new T[Asize];
            for(int i = 0; i < Asize; ++i){
                oldvalues[i] = Array[i];
            }
            delete []Array;
            ++Asize;
            int later_value_count = Asize - index;
            Array = new T[Asize];
            for(int i = 0; i < index; ++i){
                Array[i] = oldvalues[i];
            }
            Array[index] = somevalue;
            
            for(int i = later_value_count; i < Asize; ++i){
                Array[i] = oldvalues[i-1];
            }
            delete []oldvalues;
            return Array;        

        }

        T &operator [](int index){
            return Array[index];
        }
        Point& operator=(const Point& somelist) {
            if (this != &somelist) { // Self-assignment check
            delete []Array; // Delete old array
            Asize = somelist.Asize; // Copy size
            Array = new T[Asize]; // Allocate new array
            for(int i = 0; i < Asize; ++i) {
                Array[i] = somelist.Array[i]; // Copy elements
                }
            }
            return *this; // Return a reference to the current object
}


        ~Point(){
            delete []Array;
        }
};


int main(){
    Point<int,5> hello;
    for(int i = 0; i < 5; ++i){
        hello[i] = i+1;
    }
    std::cout << hello;

    system("pause > NUL");
}
