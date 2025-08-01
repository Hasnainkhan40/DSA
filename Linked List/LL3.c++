
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
    };
//GET THE MEDDEL ELEMENT OF LL
Node* getmeddel(Node* &head){
    if(head == nullptr){
        cout<<"LL is Null"<< endl;
    }
    if(head->next == nullptr){
        return head;
    };

    Node* slow = head;
    Node* fast = head->next;

    while (slow != nullptr && fast != nullptr)
    {
        fast = fast->next;
        if(fast != nullptr){
            fast=fast->next;
            slow = slow->next;
        }
    }
    return slow;
    
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

Node* reversKNods(Node* &head, int k){
    if(head == nullptr){
        return nullptr;
    }
    int len = findlen(head);
    if(k > len){
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head; 
    Node* temp = curr->next;
    int count=0;
    while (count < k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;

    }

    if(temp != nullptr){
        head->next = reversKNods(temp, k);
    }
    return prev;
    


}





int main(){
        /*THIS IS THE BASIC CODE*/
     Node* head = new Node(10);
     Node* secound = new Node(20);
     Node* thard = new Node(30);
     Node* fourth = new Node(40);
     Node* fifth = new Node(50);
      Node* sixth = new Node(60);
    
     head->next = secound;
     secound->next = thard;
     thard->next = fourth;
     fourth->next = fifth;
     fifth->next = sixth;
     sixth->next = nullptr;
     printing(head);

    // cout<<"Print the mid  " << getmeddel(head) ->data<<endl;
    cout<<endl;
    head = reversKNods(head, 4);
    printing(head);


}