#include<iostream>
using namespace std;
#include "Complex.cpp";

int main(){
  Complex c1(3,4);
  Complex c2(2,3);

  c1.plus(c2);
  c1.multiply(c2);
  c1.print();
  c2.print();
}