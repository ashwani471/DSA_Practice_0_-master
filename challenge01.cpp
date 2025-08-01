#include<iostream>

using namespace std;

int main(){

string userTea;
int teaquantity;

cout << "what would you like to order? /n ";

getline(cin , userTea);


// ask for quantity

cout << "how many cups of" << userTea << "would you like to have?" ;
cin >> teaquantity;

cout << userTea;
cout << teaquantity;


    return 0;

}