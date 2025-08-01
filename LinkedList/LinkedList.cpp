#include<iostream>
using namespace std;
#include "Node.cpp"

class Pair {
    public:
      Node *head;
      Node *tail;
};

class OddEvenPair{
 public:
   Node *oddHead;
   Node *oddTail;
   Node *evenH;
   Node *evenT;
};

OddEvenPair evenAfterOdd(Node* head){
  if(head == NULL || head->next == NULL){
    OddEvenPair ans;
    if(head->data%2 == 0){
        ans.evenH = head;
        ans.evenT = head;
        ans.evenH->next = NULL;
        ans.evenT->next = NULL;
        ans.oddHead=NULL;
        ans.oddTail = NULL;
    }else{
        ans.evenH = NULL;
        ans.evenT = NULL;
        ans.oddHead=head;
        ans.oddTail = head;
        ans.oddHead->next = NULL;
        ans.oddTail->next=NULL;
    }
    return ans;
  }

    OddEvenPair smallAns = evenAfterOdd(head->next);
    if(head->data%2==0){
        if(smallAns.evenH !=NULL && smallAns.evenT!=NULL){
           head->next = smallAns.evenH;
           smallAns.evenH = head;
        }else{
            smallAns.evenH = head;
            smallAns.evenT = head;
            smallAns.evenH->next = NULL;
            smallAns.evenT->next = NULL;
        }

    }else{
        if(smallAns.oddHead!=NULL && smallAns.oddTail!=NULL){
            head->next = smallAns.oddHead;
            smallAns.oddHead = head;
        }else{
            smallAns.oddHead = head;
            smallAns.oddTail = head;
            smallAns.oddTail->next = NULL;
            smallAns.oddHead->next = NULL;
        }
    }
    return smallAns;

}

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
       Node* newNode = new Node(data);
       if(head == NULL){
          head = newNode;
          tail=newNode;
       }else{
        tail->next = newNode;
        tail=newNode;
       }
       cin>>data;
    }
    return head;
}

int length(Node *head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void printithNode(Node* head , int pos){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        if(cnt == pos){
            cout<<temp->data;
            return;
        }
        cnt++;
        temp = temp->next;
    }
}

Node* insertNode(Node *head , int i , int data){
    Node *newNode = new Node(data);
    int cnt = 0;
    Node *temp = head;

    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp!=NULL && cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp!=NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;  
}

Node* deleteNode(Node* head , int i){
    Node* temp = head;
    int cnt = 0;
    if(i==0){
        head = head->next;
        return head;
    }

    while(temp!=NULL && cnt < i-1){
        temp = temp->next;
        cnt++;
    }
    if(temp!=NULL){
        Node* a = temp->next;
        Node* b = a->next;
        temp->next = b;
        delete a;
    }
    return head;
}

int length_rec(Node *head){
    if(head->next == NULL){
        return 1;
    }

    // if(head == NULL){
    //     return 0;
    // }

    int len = length_rec(head->next); 
    return len+1;
}

Node* insert_rec(Node* head , int i , int data){
    if(i == 0){
        Node* newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    Node* newHead = insert_rec(head->next , i-1 ,data);
    head->next = newHead;
    return head;
}

Node* delete_rec(Node* head , int i){
    if(i == 0 ){
        head = head->next;
        return head;
    }

    Node* newHead = delete_rec(head->next , i-1);
    head->next = newHead;
    return head;
}

int findNode(Node* head, int ele){

}

Node* useAppendLastToFirst(Node* head , int n , Node* tail){
    if(n==0){
        Node* newHead = head;
       
        return newHead;
    } 

    Node* prevHead,*prevTail = NULL;
    Node* temp = head;
    prevHead = head;
    prevTail=head;
    for(int i = 0 ; i<n-1 ; i++){
        temp = temp->next;
        prevTail = temp;
    }

    Node* newHead = useAppendLastToFirst(head->next , n-1 , tail);
    prevTail->next=NULL;
    tail->next=prevHead;
    return newHead;
    
}

Node* appendLastToFirst(Node* head , int n){
    int length = length_rec(head);
     if (n == 0 || head == NULL || n >= length) return head;
    // cout<<length;
    int ApFL = length-n;
    Node* tail = NULL;

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    tail = temp;
    
   Node* newHead = useAppendLastToFirst(head , ApFL , tail);
   
   return newHead;
}

Node* removeDuplicates(Node* head){
    if(head->next->next == NULL){
        if(head->data == head->next->data){
            return head->next;
        }else{
            return head;
        }
    }

    Node* prevNode = head;
    Node* temp = removeDuplicates(head->next);

    if(prevNode->data == temp->data){
        return temp;
    }else{
        prevNode->next = NULL;
        prevNode->next = temp;
        return prevNode;
    }
}

Node* useReverseLinkedList(Node* head , Node* &tail){
     if(head->next == NULL){
        return head;
    }

    Node* prevNode = head;
    Node* temp = useReverseLinkedList(head->next,tail);
    tail->next=prevNode;
    prevNode->next = NULL;
    tail=tail->next;
    return temp;

}

Node* reverseLinkedList(Node* head){
    Node* tail = head;
    Node* temp = head;
    while(temp->next != NULL){
        temp  = temp->next;
    }
    tail = temp;

   Node* head2 = useReverseLinkedList(head ,tail);
   return head2;
}

Pair reverseLL_2(Node* head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverseLL_2(head->next);
    smallans.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head=smallans.head;
    ans.tail = head;
    return ans;

}

Node* reverseLL_3(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* smallAns = reverseLL_3(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}


Node* findMid(Node* head ){
    Node* slow = head ;
    Node* fast = head -> next;
    
    while( fast != NULL  && fast->next != NULL ){
         slow = slow->next ; 
         fast=fast->next->next;
    } 
    return slow;
}

Node* mergeTwoSortedLinkedList(Node* n1 , Node* n2){
    if(n1 == NULL ){
       return n2;
    }
    if(n2==NULL){
        return n1;
    }
    Node* nHead;
    Node* oldHead;
    if(n1->data < n2->data){
        nHead = n1;
        oldHead = mergeTwoSortedLinkedList(n1->next , n2);
        
        nHead->next = oldHead;
        return nHead;
       
    }else{
        nHead = n2;
        oldHead = mergeTwoSortedLinkedList(n1 , n2->next);
        if(n2->next==NULL){
            n2->next=n1;
        }
         nHead->next = oldHead;
        return nHead;
    }


}



int main(){ 
    // Node n1(1);
    // Node n2(2);

    // // statically
    // n1.next = &n2;
    // Node *head = &n1;

    // print(head);

    // // Dynamically

    // Node *n3 = new Node(3);
    // Node *n4 = new Node(4);

    // n3->next = n4;
    // Node *head2 = n3;

    Node* head = takeInput();
    // Node* head2 = takeInput();

    // print(head);

    // int len = length_rec(head);

    // cout<<len;

    // printithNode(head , 2);

    // int i,data;
    // cin>>i;
    // cin>>data;
    // Node* head2 = insert_rec(head , i , data);

    // int i;
    // cin>>i;
    // Node* head2 = delete_rec(head , i);
    print(head);
    // Node* headnew = appendLastToFirst(head , i);
    // Node* headnew=removeDuplicates(head);
    // Node* headnew = reverseLinkedList(head);
    // Node* mid = findMid(head);
    // cout<<mid->data;
    // Node* headnew = mergeTwoSortedLinkedList(head , head2);
    // Pair headnew = reverseLL_2(head);
    OddEvenPair headnew = evenAfterOdd(head);
    print(headnew.evenH);
    print(headnew.oddHead);

    
}