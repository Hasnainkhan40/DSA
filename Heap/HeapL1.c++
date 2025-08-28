#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Heap{
    public:
    int *arr;
    int size;
    int capacity;


    Heap(int capacity){
        this->arr = new int[capacity];
        this->size = 0;
        this->capacity = 0;
    }

void insert(int val){
    if (size == capacity)
    {
        cout<<"Heap Overflow"<<endl;
    }
    size++;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
        int parentIndex = index/2;
        if(arr[index] >  arr[parentIndex]){
            swap(arr[index], arr[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
        
    }
}
void printHeap(){
    for (int i = 1; i < size; i++)
    {
       cout<<arr[i]<<" ";
    }
    
}

int deleteHeap(){
    int anwer = arr[1];
    arr[1] = arr[size];
    size--;
    int index = 1;
    while (index < size)
    {
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;
        int largestIndex = index;
        if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
        {
            largestIndex = leftIndex;
        }
        if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
        {
            largestIndex = rightIndex;
        }
        
        if (largestIndex == index)
        {
            break;;
        }else
        {
            swap(arr[largestIndex], arr[index]);
            index = largestIndex;
        }
    }
    return anwer;
    
}
};

void heapify(int *arr, int size, int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestIndex = index;
     if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
        {
            largestIndex = leftIndex;
        }
        if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
        {
            largestIndex = rightIndex;
        }
        
        if (largestIndex != index)
        {
            swap(arr[largestIndex], arr[index]);
            index = largestIndex;
            heapify(arr, size, index);
        }

    }

void BuildHeap(int arr[],int n){
    for (int index = n/2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
 
}

void heapSort(int arr[], int n){
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
    
}


int main(){
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;
    BuildHeap(arr, n);
    cout << "Printing Heap" << endl;
    for (int i = 1; i <= 6; i++)
    {
       cout<< arr[i]<< " ";
    }
    cout<< endl;

    heapSort(arr, 6);
    cout << "Printing Heap" << endl;
    for (int i = 1; i <= 6; i++)
    {
       cout<< arr[i]<< " ";
    }
    
    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // cout<<"Printing Heap" << endl;
    // h.printHeap();

    // cout<<"Deleting Heap" << endl;
    // h.deleteHeap();
    // h.printHeap();


    return 0;
}