#include<iostream>
using namespace std;

class DynamicArray{

    int *data;
    int capacity;
    int nextIndex;

    public:
      DynamicArray(){
        data = new int[2];
        capacity=2;
        nextIndex =0;
    }

    DynamicArray(DynamicArray const &d){
        this->data = new int[d.capacity];
        for(int i = 0 ;i<d.nextIndex ; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int elem){
        if(nextIndex == capacity){
            int *newData = new int[2*capacity];
            for(int  i =0 ; i<capacity ; i++){
                newData[i] = data[i];
            }
            delete [] data;
            newData = data;
            capacity *= 2;
        }
        data[nextIndex] = elem;
        nextIndex++;
    }

    void print(){
        for(int i = 0 ; i<nextIndex ; i++){
            cout<<data[i] << " ";
        }
        cout<<endl;
    }
};
