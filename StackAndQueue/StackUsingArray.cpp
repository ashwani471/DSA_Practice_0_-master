#include<iostream>
using namespace std;
#include<climits>

class StackUsingArray{
    private:
      int *data;
      int nextIndex;
      int capacity;
    public:
       StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
       }  

    int size(){
        return nextIndex;
    }   

    bool isEmpty(){
        return nextIndex==0;
    }

    void push(int ele){
        if(nextIndex == capacity){
           int *newData = new int[2*capacity];
           for(int i = 0 ; i<capacity ; i++){
            newData[i] = data[i];
           }
           capacity*=2;
           delete [] data;
           data = newData;
            // cout<<"stack is full"<<endl;
            // return;
        }
        data[nextIndex] = ele;
        nextIndex++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
       if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        } 
        return data[nextIndex-1];
    }
};