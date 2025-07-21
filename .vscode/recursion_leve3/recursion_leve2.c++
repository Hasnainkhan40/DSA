#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;



// ***find element using binnary screche***

int binarySearch(vector<int>& arr, int s, int e, int key){
    if(s > e){
        return -1;
    }

    int mid = s+(e-s)/2;

    if(arr[mid] == key){
        return mid;
    }

    if(arr[mid] < key){
        return binarySearch(arr, mid+1, e, key);
    }else
    {
       return binarySearch(arr, s, mid-1, key);
    }

}

// ***check the arr is soterd***

bool checkSotrt(vector<int>& arr, int& n, int i){
    if(i == n-1){
        return true;
    }

    if(arr[i+1] < arr[i]){
        return false;
    }

    checkSotrt(arr, n, i+1);
}


int main(){


    vector<int> arr{1,2,3,4,5,6,7,8,9, 100};
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int key= 100;

    int ans = binarySearch(arr, s, e, key);
    cout<< ans << " ";
 
    // ***check the arr is soterd***
    // vector<int> arr{1,2,3,4,5,6,7,8,9};
    // int n = 9;
    // int i = 0;

    // bool issoterd = checkSotrt(arr, n, i);

    // if(issoterd){
    //     cout<<"Sorterd Arrar" << endl;
    // }else
    // {
    //     cout<<"Not Sorterd Arrar" << endl;
    // }
    

    // return 0;
} 
