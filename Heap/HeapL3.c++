#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Info{
    public:
    int data;
    int row;
    int col;
    Info(int val, int r, int c){
        data = val;
        row = r;
        col = c;
    }
};

class compare {
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};


vector<int> marageKSA(int arr[][4], int k, int n){
    priority_queue<Info*, vector<Info*>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        Info* temp = new Info(arr[i][0], i, 0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        Info* temp = minHeap.top();
        int element = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(element);
        if(topCol+1 < n ){
           Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1); 
            minHeap.push(newInfo);
        }

    }
    return ans;
    
}  


int main(){
    int arr[][4] = {{2,4,6,8}, 
                    {1,3,5,7}, 
                    {0,9,10,11}};
    int k = 3;
    int n = 4;
    vector<int> ans  = marageKSA(arr, k, n);

    for(auto i : ans){
        cout<< i << " ";
    }cout<< endl;
    return 0;
};