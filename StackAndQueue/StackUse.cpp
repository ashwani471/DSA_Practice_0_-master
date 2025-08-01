#include<iostream>
using namespace std;
#include<cstring>
#include<stack>
// #include "StackUsingArray.cpp"
// #include "StackUsingLL.cpp"

bool checkBalanced(char *str){
  stack<char> s;
  for(int i=0 ; i<strlen(str);i++){
     if(str[i]=='(' || str[i]== '[' || str[i]=='{'){
      s.push(str[i]);
     }else{
      if(str[i]==')'){
        if(s.top()=='('){
          s.pop();
          continue;
        }else{
          return false;
        }
      }
      if(str[i]==']'){
        if(s.top()=='['){
          s.pop();
          continue;
        }else{
          return false;
        }
      }
      if(str[i]=='}'){
        if(s.top()=='{'){
          s.pop();
          continue;
        }else{
          return false;
        }
      }
     } 
  }
  if(s.size()==0){
    return true;
  }else{
    false;
  }
}

void insertAtBtm(stack<int> &st , int ele){
  if(st.empty()){
    st.push(ele);
    return;
  }

  int topele = st.top();
  st.pop();
  insertAtBtm(st,ele);

  st.push(topele);

}

void reverseSt(stack<int> &st){

  if(st.empty()){
    return;
  }

  int x= st.top();
  st.pop();
  reverseSt(st);
  insertAtBtm(st,x);
}

int main(){
  // StackUsingArray s(5);
  // s.push(10);
  // s.push(20);
  // s.push(30);
  // cout<<s.top()<<endl;
  // s.pop();
  // cout<<s.top()<<endl;

  // Stack s;
  // s.push(1);
  // s.push(2);
  // s.push(3);
  // cout<<s.top()<<endl;
  // cout<<s.pop()<<endl;
  // cout<<s.top()<<endl;

  // char str[100];
  // cin>>str;

  // if(checkBalanced(str)){
  //   cout<<"true"<<endl;
  // }else{
  //   cout<<"false";
  // }

  stack<int> st;
  reverseSt(st);
  
}