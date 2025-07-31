
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

/*LL CREATION IMPOSTRENT*/
class Node {
  public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = nullptr;
    };
    Node(int data){
        this->data = data;
        this->next = nullptr;
    };
};

 /*PRINT LL*/
void printing(Node* head){
        Node* temp = head;
        while (temp != nullptr)
        {
            cout<< temp->data<<endl;
            temp = temp->next;
        }
        
    }
 /*INSERT AT START*/
void insertAtHead(Node* &head, Node* &tail,int data){
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
         tail = newNode;
         return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
  
    head = newNode;
};

 /*INSERT AT LAST*/
void insertAtTail(Node* &head, Node* &tail,int data){
      if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
         tail = newNode;
         return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;

    
    tail = newNode;
};

 /*FIND THE LENGTH*/
int findlen(Node* &head){
    int len = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

 /*INSERT AT ANY POSITION*/
void insertAtPos(int data,int pos, Node* &head, Node* &tail){
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(pos == 0){
        insertAtHead(head, tail, data);
        return;
    }
    int len = findlen(head);
    if(pos >= len){
        insertAtTail(head, tail, data);
        return;
    }

    int i = 0;
    
    Node* prev = head;
    while (i<pos)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    Node* newNode = new Node(data);

    newNode->next = curr;
    prev->next = newNode;
    
    
};



void deletNode(int pos, Node* &head,Node* &tail){

    if(head == nullptr){
        cout<< "Empty LL"  << endl;
        return;
    }

    //delet first node
    if(pos == 1){
        Node* temp = head;
        head =  head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    //delet last node
    int len = findlen(head);

    if(pos == len){
        int i=1;
        Node* prev = head; 
        while (i < pos-1)
        {
            prev= prev->next;
            i++;
        }
        prev->next=nullptr;
        Node* temp = tail;
        tail = prev;
        delete temp;
        return;

    }

    int i = 1;
    Node* prev = head;
    while (i < pos-1)
    {
        prev = prev->next;
        i++;
    }

    Node* curr  = prev->next;
    prev->next = curr->next;
    curr->next = nullptr; 
    delete curr;
    
}


int main(){
    

    /*THIS IS THE MAIN CODE*/
    Node* head =nullptr;
    Node* tail = nullptr;
    insertAtHead(head, tail,10);
    insertAtHead(head,tail, 20);
    insertAtHead(head, tail,30);
    insertAtHead(head, tail,40);
    insertAtHead(head, tail,50);
    insertAtTail(head, tail, 60);

    /*THIS IS THE BASIC CODE*/
    // Node* first = new Node(10);
    // Node* secound = new Node(20);
    // Node* thard = new Node(30);
    
    // first->next = secound;
    // secound->next = thard;
    // thard->next = nullptr;

    cout<< "After print" <<endl;
    

    /*INSERT AT ANY POSITION*/
    insertAtPos(101, 6, head, tail);
    printing(head);
    cout << "Delet" <<endl << endl;
    deletNode(4, head, tail);
    
     printing(head);
     cout << endl << endl;



    return 0;
};