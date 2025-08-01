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

class Queue{
    Node* head;
    Node* tail;
    int size;

    public:
      Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
      }
      int getSize(){
        return size;
      }

      bool isEmpty(){
        return size==0;
      }

      void enqueue(int ele){
        Node* newNode = new Node(ele);
        if(head == NULL){
           head = newNode;
           tail = newNode;
           size++;
        }else{
            tail->next = newNode;
            tail = newNode;
            size++;
        }
      }
    
      int front(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
      }

      int dequeue(){
        if(isEmpty()){
            return 0;
        }
        Node* temp = head;
        int ans = head->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
      }
};