#include<iostream>

class Node{
   public:
    int data;
    Node* next;
   
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
   private:
    Node* head;
    int stSize;

   public:
    Stack(){
        head = NULL;
        stSize = 0;
    }

    int size(){
        return stSize;
    }
    
    bool isEmpty(){
        return stSize==0;
    }

    void push(int ele){
        Node* newNode  = new Node(ele);
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
            stSize++;
        }
        
    }

    int pop(){
        if(isEmpty() ){
            return 0;
        }
        Node* temp = head;
        int ans = head->data;
        head = head->next;
        delete temp;
        stSize--;
        return ans;
    }

    int top(){
        if(isEmpty()){
            return 0 ;
        }
        return head->data;
    }
};