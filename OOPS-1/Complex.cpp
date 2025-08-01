#include<iostream>
using namespace std;

class Complex{
  private:
    int real;
    int imaginary;

  public:

    Complex(int real , int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    
    void print(){
        cout<<real << "+" <<imaginary<<"i"<<endl;
    }  

    void plus(Complex c2){
        int x = real + c2.real;
        int y = imaginary + c2.imaginary;

        this->real = x ;
        this->imaginary = y;

    }
    
    void multiply(Complex c2){
        int x = real*c2.real;
        int y = imaginary*c2.imaginary;

        this->real = x;
        this->imaginary = y;
    }
};