
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
            cout<< temp->data;
            temp = temp->next;
        }
    };

Node* reversell(Node* &head){
    
    Node* prev = nullptr;
    Node* curr = head;
    Node* temp = curr->next;
    while (curr != nullptr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;   
    }
    return prev;
}

//LL IS PLAINDROM
bool checkPalindrom(Node* &head){
    if(head == nullptr){
        cout<< " LL IS EMPTY"<<endl;
        return false;
    }
    if(head->next == nullptr){
        return true;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr)
    {
        fast= fast->next;
        if(fast != nullptr){
            fast= fast->next;
            slow = slow->next;
        }
    }
    Node* bakiLL = reversell(slow->next);
    slow->next = bakiLL;
    
    Node* temp1 = head;
    Node* temp2 = bakiLL;

    while (temp2 != nullptr)
    {
        if(temp1->data != temp2->data){
           return false;
        }else
        {
            temp1 =  temp1->next;
            temp2 = temp2->next;
        }
        
    }
    return true;
}

// REMOVE THE DUPLECAT IN LL
void removeDiplicat(Node* &head){
    if(head == nullptr){
        return;
    }
    if(head->next == nullptr){
          return;
    }

    Node* curr = head;
    while (curr != nullptr)
    {
       if ((curr->next != nullptr) && (curr->data == curr->next->data))
       {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        temp->next=nullptr;
        delete temp;
       }
       else
       {
        curr = curr->next;
       }
    }

}

//importent sort 0,1,2
Node* sort2(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zerotail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* onetail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twotail = twoHead;

    Node* curr = head;
    while (curr != nullptr)
    {
        if(curr->data == 0){
            Node* temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            zerotail->next = temp;
            zerotail = temp;
            
        }
            else if(curr->data == 1){
            Node* temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            onetail->next = temp;
            onetail = temp;
        }
            else if(curr->data == 2){
            Node* temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            twotail->next = temp;
            twotail = temp;
        }
    }
    
    Node* temp = oneHead;
    oneHead=oneHead->next;
    temp->next = nullptr;
    delete temp;

    temp = twoHead;
    twoHead=twoHead->next;
    temp->next = nullptr;
    delete temp;
   
    if (oneHead != nullptr)
    {
        zerotail->next = oneHead;
        if (twoHead != nullptr)
        {
            onetail->next = twoHead;
        }
        
    }else
    {
        if (twoHead != nullptr)
        {
            zerotail->next = twoHead;
        }
        
    }
    
    temp = zeroHead;
    zeroHead=zeroHead->next;
    temp->next = nullptr;
    delete temp;


    return zeroHead;
}

Node* addTwoll(Node* &head1, Node* &head2){
    head1 = reversell(head1);
    head2 = reversell(head2);

    Node* ansHead = nullptr;
    Node* ansTail = nullptr;
    int curry = 0;

    while (head1!= nullptr && head2 != nullptr)
    {
        int sum = curry + head1->data + head2->data;
        int digit = sum%10;
        curry = sum/10;
        Node* newNode = new Node(digit);
        if(ansHead == nullptr){
            ansHead = newNode;
            ansTail = newNode;
        }else
        {
            ansTail->next=newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2= head2->next;
        
    }
    while (head1 != nullptr)
    {
         int sum = curry + head1->data ;
        int digit = sum%10;
        curry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next=newNode;
        ansTail = newNode;   
        head1=head1->next;
    }
     while (head2 != nullptr)
    {
         int sum = curry + head2->data;
        int digit = sum%10;
        curry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next=newNode;
        ansTail = newNode;   
        head2=head2->next;
    }
    while (curry != 0)
    {
        int sum = curry;
        int digit = sum%10;
        curry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next=newNode;
        ansTail = newNode;   
    }
    
    ansHead = reversell(ansHead);
    return ansHead;
    
    
}



int main(){
    
     Node* head1 = new Node(2);
     Node* secound1 = new Node(4);
    

     head1->next = secound1;
     secound1->next = nullptr;

    Node* head2 = new Node(2);
     Node* secound2 = new Node(3);
     Node* thard2 = new Node(4);

      head2->next = secound2;
     secound2->next = thard2;
     thard2->next = nullptr;

     Node* ans = addTwoll(head1, head2);
     cout<<"AFTER ADD  "<< endl;
     printing(ans);






        /*THIS IS THE BASIC CODE*/
    //  Node* head = new Node(1);
    //  Node* secound = new Node(0);
    //  Node* thard = new Node(2);
    //  Node* fourth = new Node(2);
    //  Node* fifth = new Node(1);
    //   Node* sixth = new Node(0);
    
    //  head->next = secound;
    //  secound->next = thard;
    //  thard->next = fourth;
    //  fourth->next = fifth;
    //  fifth->next = sixth;
    //  sixth->next = nullptr;
    
    // printing(head);
    // cout<<endl;
    // cout<< "AFTER SORT  "<<endl;
    // head = sort2(head);
    // printing(head);

    // removeDiplicat(head);
    // cout<< "AFTER REMOVE  "<<endl;
    //  printing(head);
    // bool ans  = checkPalindrom(head);
    // cout<< "is Palaindrom  " << ans << endl;
 return 0;


}