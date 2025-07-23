#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


//***marge short***
void marge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* left = new int [len1];
    int* right = new int [len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

     k = mid+1;
    for (int i = 0; i < len1; i++)
    {
        right[i] = arr[k];
        k++;
    }

    int leftIndex = 0;
        int rightIndex = 0;
            int mainIndex = s;
    
    while (leftIndex < len1 && rightIndex < len2)
    {
        if(left[leftIndex] < right[rightIndex]){
            arr[mainIndex++] = left[leftIndex++];
        }else
        {
             arr[mainIndex++] = right[rightIndex++];
        }
        
    }

    while (leftIndex < len1)
    {
        arr[mainIndex++] = left[leftIndex++];
    }
    while (rightIndex < len2)
    {
        arr[mainIndex++] = right[rightIndex++];
    }
}

 void margesort(int arr[], int s, int e){

    if(s>=e){
        return;
    }

    int mid = (s+e)/2;

    margesort(arr, s, mid);

    margesort(arr, mid+1, e);

    marge(arr, s, e);
    
 }


// *******---quickSort---*******
int patitionLogic(int arr[], int s, int e){
    int pivitIndex = s;
    int pivitValue = arr[s];

    int count = 0;
    for (int i = s+1; i<=e; i++)
    {
        if(arr[i] <=pivitValue){
            count++;
        }
    }

    int rightIndex = s + count;
    swap(arr[pivitIndex], arr[rightIndex]);
    pivitIndex = rightIndex;

    int i = s;
    int j = e;

    while (i < pivitIndex && j > pivitIndex)
    {
        while (arr[i] <= pivitValue)
        {
            i++;
        }
        while (arr[j] > pivitValue)
        {
            j--;
        }

          if (i <= pivitIndex && j > pivitIndex)
        {
            swap(arr[i], arr[j]);
        }
        return pivitIndex;
        
    }
  


}




 void quickSort(int arr[], int s, int e){

    if(s >= e) {
        return ;
    }

    int p =  patitionLogic(arr, s, e);
    
    //left side
    quickSort(arr, s, p-1);

    //right side
    quickSort(arr, p+1, e);
 }





int main() {
    
    // ***quickSort***
    int arr[] = {8,1,3,4,4,20,50,30, 1,8,4,6,5,8,4,2,5,4,8,8,8,};
    int n = 21;
    int s = 0;
    int e = n-1;

    quickSort(arr, s, e);

    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
    return 0;


    // //***marge short***
    // int arr[] = {10,5,4,7,1,1,};
    // int n = 6;
    // int s=0;
    // int e=n-1;
    

    // margesort(arr, s, e);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<< arr[i] << " ";
    // }
    // cout<< endl;
    
};