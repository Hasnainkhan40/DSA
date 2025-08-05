#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
class Stack {
    public:

    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int [size];
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(size - top > 1){
            top++;
            arr[top] = data;
        }else{
            cout<< "Stack Overflow" << endl;
        }
    }
       void pop(){
        if(top == -1){
            cout<< "Stack underflow" << endl;
        }else{
            top--;
        }
    }

    int Top(){
       if(top == -1){
            cout<< "Not Element" << endl;
        }else{
           return arr[top];
        }
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
           return false;
        }
    }

};

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    cout << "Size: " << s.getSize() << endl;
cout << "Is empty: " << s.isEmpty() << endl;
 while (!s.isEmpty()) {
    cout << s.Top() << " ";
    s.pop();
}

    return 0;
    
}