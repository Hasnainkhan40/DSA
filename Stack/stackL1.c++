#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>

using namespace std;
// class Stack {
//     public:

//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//         arr = new int [size];
//         this->size = size;
//         top = -1;
//     }

//     void push(int data){
//         if(size - top > 1){
//             top++;
//             arr[top] = data;
//         }else{
//             cout<< "Stack Overflow" << endl;
//         }
//     }
//        void pop(){
//         if(top == -1){
//             cout<< "Stack underflow" << endl;
//         }else{
//             top--;
//         }
//     }

//     int Top(){
//        if(top == -1){
//             cout<< "Not Element" << endl;
//         }else{
//            return arr[top];
//         }
//     }

//     int getSize(){
//         return top+1;
//     }

//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }else{
//            return false;
//         }
//     }

// };

//fild the medele element in stack
void getmedele(stack<int> &s, int totelSize){
    if(s.size() == 0){
        cout<< "Stack is empty"  << endl;
        return;
    }
    if(s.size() == totelSize/2+1){
        cout<< "Medele element "  << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();
    getmedele(s, totelSize);
    s.push(temp);
}


//insert at bottom
void insertAtBottem(stack<int> &s, int &target){

    if(s.empty()){
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    //recursion
    insertAtBottem(s, target);
     //backtrack
    s.push(temp);
}

//reverse the stack
void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottem(s, topElement);
}

//sort the stack
void insertAtsort(stack<int> &s, int target){
    if(s.empty()){
        s.push(target);
        return;
    }
    if(s.top() >= target){
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    //recursion
    insertAtsort(s, target);
     //backtrack
    s.push(temp);

}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();
    sortStack(s);
    insertAtsort(s, topElement);
}
int main(){
    stack<int> s;
    s.push(9);
    s.push(5);
    s.push(3);
    s.push(11);
    s.push(7);
    // s.push(60);
    // s.push(70);
    // if(s.empty()){
    //    cout<<"Stack is Empty"<<endl; 
    // }

    // int target = s.top();
    // s.pop();
    // insertAtBottem(s,target);
    //reverseStack(s);
    sortStack(s);
    while (!s.empty())
    {
        cout<< "Printing stack "<< s.top()<<endl;
        s.pop();
    }
    






    //fild the medele element in stack
    // int totelsize = s.size();
    // getmedele(s, totelsize);
//     cout << "Size: " << s.getSize() << endl;
// cout << "Is empty: " << s.isEmpty() << endl;
//  while (!s.isEmpty()) {
//     cout << s.Top() << " ";
//     s.pop();
// }

    return 0;
    
}