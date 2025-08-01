#include<iostream>
using namespace std;
#include "queueUsingLL.h"
#include "queue"

void reverseQueue(queue<int> q){
    if(q.empty()){
        return;
    }

    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main(){
    // Queue q;
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // cout<<q.front()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.front()<<endl;

    queue<int> q;

    reverseQueue(q);
}