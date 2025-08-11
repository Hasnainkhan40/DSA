
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

//NORMAL QUEUE
class Queue
{
public:
   int *arr;
   int size;
   int front;
   int rear;

   
    Queue(int size){
        this->size = size;
        arr = new int [size];
        front=0;
        rear=0;
    };

        void qpush(int data){
        if (rear == size)
        {
            cout<< "Queue is empty" ;
        }
        else{
            arr[rear] = data;
            rear++;
        } 
    }
    void qpop(){
        if (front == rear)
        {
            cout<< "Queue is empty" ;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front=0;
                rear=0;
            }
        } 
    }
    int qgetfront(){
        if (front == rear)
        {
            cout<< "Queue is empty";
        }
        else{
            return  arr[front];
           
        } 
    }
    bool qisEmpty(){
        if(front == rear){
            return true;
        }else
        {
            return false;
        }
        
    }
    int getSize(){
        return rear-front;
    }

    
};


//CIRCULAR QUEUE
class CirQueue
{
public:
   int *arr;
   int size;
   int front;
   int rear;

   
    CirQueue(int size){
        this->size = size;
        arr = new int [size];
        front=-1;
        rear=-1;
    
    };

    void push(int data){
        if(front ==0 && rear == size-1){
            cout<< "Queue is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;

        }else if(rear == size-1 && front !=0){
            rear=0;
            arr[rear] = data;
        }else
        {
            rear++;
            arr[rear] = data;
        }
        
    }

    void pop(){
        if(front == -1){
            cout<< "Queue is empty";
        }else if(front == rear){
            arr[front] = -1;
            front=-1;
            rear=-1;
        }else if(front == size-1){
            front=0;
        }else
        {
            front++;
        }
        
    }
};


//DUBBLY QUEUE
class DQueue
{
public:
   int *arr;
   int size;
   int front;
   int rear;

   
    DQueue(int size){
        this->size = size;
        arr = new int [size];
        front=-1;
        rear=-1;
    
    };

    void pushRear(int data){
        if(front ==0 && rear == size-1){
            cout<< "Queue is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;

        }else if(rear == size-1 && front !=0){
            rear=0;
            arr[rear] = data;
        }else
        {
            rear++;
            arr[rear] = data;
        }
        
    }
    
    void pushFront(int data){
        if(front ==0 && rear == size-1){
            cout<< "Queue is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[front] = data;

        }else if(front == 0 && rear != size-1){
            front=size-1;
            arr[front] = data;
        }else
        {
            front--;
            arr[front] = data;
        }
        
    }

    void popFront(){
        if(front == -1){
            cout<< "Queue is empty";
        }else if(front == rear){
            arr[front] = -1;
            front=-1;
            rear=-1;
        }else if(front == size-1){
            front=0;
        }else
        {
            front++;
        }
        arr[front] = -1;
        
    }
    void popRear(){
        if(front == -1){
            cout<< "Queue is empty";
            return;
        }else if(front == rear){
            arr[front] = -1;
            front=-1;
            rear=-1;
        }else if(rear == 0){
            rear = size-1;
        }else
        {
            rear--;
        }
         arr[rear] = -1;
        
    }

    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<< arr[i] << endl;
        }
        
    }
};










int main(){
    // CirQueue q(10);
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    
    // q.pop();
    //  cout<< "data"<<endl;
    // return 0;

    DQueue q(5);
    q.pushRear(10);
    q.pushRear(20);
    q.pushFront(30);
    q.pushFront(40);
    q.pushFront(50);
    q.print();
  
    q.popRear();
    q.popFront();

    q.print();
    return 0;


}